/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knage <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/19 14:31:08 by knage             #+#    #+#             */
/*   Updated: 2016/07/23 15:42:46 by knage            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	finish(t_env *env)
{
	t_links	*temp[env->ant_count];
	t_links	*path[2];

	env->helper = 0;
	path[1] = env->fpaths[env->helper]->path;
	ft_initrooms(env);
	while (env->helper < env->ant_count)
	{
		path[1] = env->fpaths[env->helper]->path;
		temp[env->helper] = 0;
		while (path[1])
		{
			path[0] = (t_links *)malloc(sizeof(t_links));
			path[0]->bar_code = path[1]->bar_code;
			path[0]->next = temp[env->helper];
			temp[env->helper] = path[0];
			path[1] = path[1]->next;
		}
		env->helper++;
	}
	final(env, temp);
}

void	continue_wave(t_env *env)
{
	t_links	*temp;
	t_links	*temp1;

	temp = env->stack[env->nodes_count[1]];
	while (temp)
	{
		temp1 = env->maze[temp->bar_code].links;
		while (temp1)
		{
			if (env->room[temp1->bar_code] == 0)
				fill_room(env, temp, temp1->bar_code);
			temp1 = temp1->next;
		}
		env->room[temp->bar_code] = 0;
		if (temp->bar_code == env->special[1])
			env->fpaths[++env->helper] = temp;
		temp = temp->next;
	}
}

void	start_wave(t_env *env)
{
	t_links	*temp;

	temp = env->maze[env->special[0]].links;
	while (temp)
	{
		if (env->room[temp->bar_code] == 0)
			setnode(env, temp->bar_code);
		if (temp->bar_code == env->special[1])
		{
			env->helper++;
			env->fpaths[env->helper] = temp;
		}
		temp = temp->next;
	}
}

void	algo(t_env *env)
{
	t_links	*ants[env->ant_count];
	int		ant_out;

	ant_out = 1;
	env->helper = -1;
	ft_initrooms(env);
	env->stack[0] = 0;
	env->stack[1] = 0;
	env->start = 0;
	env->fpaths = ants;
	env->nodes_count[0] = 0;
	env->nodes_count[1] = 1;
	while (env->helper < env->ant_count)
	{
		env->nodes_count[0] = (env->nodes_count[0] == 0);
		env->nodes_count[1] = (env->nodes_count[1] == 0);
		continue_wave(env);
		start_wave(env);
		ant_out = (ant_out == 0);
		if (ant_out == 0)
			ant_wait(env);
		env->stack[env->nodes_count[1]] = 0;
	}
	finish(env);
}
