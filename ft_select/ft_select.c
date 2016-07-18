/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_select.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knage <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/11 17:32:53 by knage             #+#    #+#             */
/*   Updated: 2016/07/16 15:13:29 by knage            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

t_list		*load(char **av, int ac)
{
	int		i;
	int		j;
	t_list	*list;

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

int			key_hook(t_list *list, t_env *env)
{
	char	buf[10];

	ft_bzero(buf, 4);
	signals();
	read(0, buf, 4);
	signals();
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
	return (0);
}

void		ft_select(t_env *env, int ac)
{
	while (1)
	{
		signals();
		if (ft_resize(env) == 1)
		{
			if (env->error == 1)
			{
				tputs(tgetstr("te", NULL), 1, ft_putchar_i);
				tputs(tgetstr("ti", NULL), 1, ft_putchar_i);
				tputs(tgetstr("ho", NULL), 1, ft_putchar_i);
				print_list(env->choices);
			}
			if (env->remove == ac - 1)
				break ;
			if (env->remove == ac - 2)
				env->max = 0;
			if (key_hook(env->choices, env))
				break ;
			env->error = 0;
		}
		else
			window_small(env);
	}
}

int			main(int ac, char **av)
{
	t_env	*env;

	if (ac > 1)
	{
		env = get_env();
		if (!(env->active))
		{
			env->active = 1;
			env->max = ac - 2;
			env->remove = 0;
			env->place = 0;
			env->error = 0;
			env->choices = load(av, ac);
		}
		change_term(env);
		print_list(env->choices);
		tputs(tgetstr("mk", NULL), 1, ft_putchar_i);
		ft_select(env, ac);
		change_back();
		if (env->finish == 1)
			finish(env->choices);
	}
	return (0);
}
