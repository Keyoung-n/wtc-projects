/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_select.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knage <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/11 17:32:53 by knage             #+#    #+#             */
/*   Updated: 2016/07/15 12:23:31 by knage            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

int		ft_putchar_i(int c)
{
	return (write(2, &c, 1));
}

void	print_list(t_list *list)
{
	int i;

	i = 0;
	while (list[i].choice)
	{
        if (list[i].visible == 0)
        {
            ft_putstr_fd("\033[39m", 2);
            if (list[i].select == 1)
                tputs(tgetstr("mr", NULL), 1, ft_putchar_i);
            if (list[i].hover == 1)
                tputs(tgetstr("us", NULL), 1, ft_putchar_i);
            ft_putstr_fd(list[i].choice, 2);
			tputs(tgetstr("me", NULL), 1, ft_putchar_i);
            if (list[i].select == 1)
                ft_putstr_fd("\033[96m", 2);
            ft_putchar_fd('\n', 2);
        }
        i++;
	}
}

t_list    *load(char **av, int ac)
{
	int     i;
	int     j;
	t_list  *list;

	i = 1;
	j = 0;
	list = (t_list*)malloc(sizeof(t_list) * ac);
	while (i != ac)
	{
		if (j == 0)
			list[0].hover = 1;
		else
			list[j].hover = 0;
        list[j].visible = 0;
		list[j].choice = av[i];
		i++;
		j++;
	}
	return (list);
}

void    move(t_list *list, t_env *env, int move)
{
	if (move == 1)
	{
		list[env->place].hover = 0;
		env->place += 1;
        while (list[env->place].hover == 1)
            env->place++;
		if (env->place >= env->max + 1)
			env->place = 0;
		list[env->place].hover = 1;
	}
	else if (move == -1)
	{
		list[env->place].hover = 0;
		env->place -= 1;
        if (list[env->place].visible == 1)
            env->place -= 1;
		if (env->place < 0)
			env->place = env->max;
		list[env->place].hover = 1;
	}
	tputs(tgetstr("te", NULL), 1, ft_putchar_i);    
	tputs(tgetstr("ti", NULL), 1, ft_putchar_i);
    tputs(tgetstr("ho", NULL), 1, ft_putchar_i);
	print_list(list);
}

void	select_item(t_list *list, t_env *env)
{
	if (list[env->place].select == 1)
		list[env->place].select = 0;
	else
	{
		list[env->place].select = 1;
		move(list, env, 1);
	}
	tputs(tgetstr("te", NULL), 1, ft_putchar_i);
	tputs(tgetstr("ti", NULL), 1, ft_putchar_i);
    tputs(tgetstr("ho", NULL), 1, ft_putchar_i);
	print_list(list);
}

void    remove_item(t_list *list, t_env *env)
{
    if (list[env->place].select == 1)
        list[env->place].select = 0;
    if (env->place == env->max)
        env->max -= 1;
    list[env->place].visible = 1;
    env->remove++;
    move(list, env, 1);
}

int		key_hook(t_list *list, t_env *env)
{
	char	buf[10];

	ft_bzero(buf, 4);
	read(0, buf, 4);
	if (buf[0] == 10)
		return ((env->finish = 1));
	if (buf[0] == 27 && buf[2] == 65)
		move(list, env, -1);
	else if (buf[0] == 27 && buf[2] == 66)
		move(list, env, 1);
	else if (buf[0] == 27 && buf[2] == 67)
		move(list, env, 1);
	else if (buf[0] == 27 && buf[2] == 68)
		move(list, env, -1);
    else if (buf[0] == 127)
        remove_item(list, env);
    else if (buf[0] == 27 && buf[3] == 126)
		remove_item(list, env);
	else if (buf[0] == 32)
		select_item(list, env);
	else if (buf[0] == 27)
		return (1);
	else
		; 
	return (0);
}

void	change_term(t_env *env)
{
    tgetent(NULL, getenv("TERM"));
	tcgetattr(0, &env->termios);
	env->termios.c_lflag &= ~(ECHO | ICANON);
	tcsetattr(0, TCSANOW, &env->termios);
	tputs(tgetstr("ti", NULL), 1, ft_putchar_i);
	tputs(tgetstr("ho", NULL), 1, ft_putchar_i);
	tputs(tgetstr("vi", NULL), 1, ft_putchar_i);
}

void	change_back()
{
	tputs(tgetstr("te", NULL), 1, ft_putchar_i);
	tputs(tgetstr("ve", NULL), 1, ft_putchar_i);
}

void	finish(t_list *list)
{
	int i;

	i = 0;
	ft_putstr_fd("\033[39m", 2);
	while (list[i].choice)
	{
		if (list[i].select == 1)
			ft_printf("%s ", list[i].choice);
		i++;
	}
}

int main(int ac, char **av)
{
	t_list      *choices;
	t_env       env;

	if (ac > 1)
	{
		env.max = ac - 2;
        env.remove = 0;
		env.place = 0;
		choices = load(av, ac);
		change_term(&env);
		print_list(choices);
		tputs(tgetstr("mk", NULL), 1, ft_putchar_i);
		while (1)
		{
            if (env.remove == ac - 1)
                break;
            if (env.remove == ac - 2)
                env.max = 0;
			if (key_hook(choices, &env))
				break;
		}
		change_back();
		if (env.finish == 1)
			finish(choices);
	}
	return (0);
}
