/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knage <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/16 09:33:23 by knage             #+#    #+#             */
/*   Updated: 2016/07/16 15:17:49 by knage            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void	move(t_list *list, t_env *env, int move)
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

void	remove_item(t_list *list, t_env *env)
{
	if (list[env->place].select == 1)
		list[env->place].select = 0;
	if (env->place == env->max)
		env->max -= 1;
	list[env->place].visible = 1;
	env->remove++;
	move(list, env, 1);
}

void	print_list(t_list *list)
{
	int	i;

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
