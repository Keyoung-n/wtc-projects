/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_select.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knage <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/11 17:32:53 by knage             #+#    #+#             */
/*   Updated: 2016/07/14 16:52:42 by knage            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void    load(t_list *list, char **av, int ac)
{
    int i;
    
    i = 1;
    while (i != ac)
    {
        list[i].choice = av[i];
        i++;
    }
}

int		ft_putchar_i(int c)
{
	return (write(2, &c, 1));
}

int		key_hook()
{
	char	buf[10];

	read(0, buf, 4);
	ft_putstr(buf);
    if (buf[0] == 27 && buf[2] == 65)
        ft_putstr("hello");
    if (buf[0] == 27)
        return (1);
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

void	print_list(t_list *list)
{
    int i;
    
    i = 0;
	while (list[i].choice)
    {
        if (list->hover == 1)
            ft_putstr("* ");
        ft_putstr_fd(list->choice, 2);
        ft_putchar_fd('\n', 2);
        i++;
	}
}

int main(int ac, char **av)
{
	t_list      choices[ac -1];
    t_env       env;

    load(choices, av, ac);
	change_term(&env);
	print_list(choices);
    tputs(tgetstr("mk", NULL), 1, ft_putchar_i);
	while (1)
	{
		if (key_hook())
            break;
	}
	change_back();
	return (0);
}
