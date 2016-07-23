/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knage <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/04 14:58:40 by knage             #+#    #+#             */
/*   Updated: 2016/07/23 14:19:49 by knage            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	extract_data(t_env *env, t_data **room)
{
	char	*line;
	int		type;
	t_data	*temp;

	get_ant_numbers(env);
	temp = *room;
	while (get_next_line(0, &line) && ft_printf("%s\n", line))
	{
		type = what_type(line);
		if (type == 1)
			get_link(line, temp);
		else if (type == 2)
			get_room(line, &temp, env);
		else if (type == 3)
			;
		else if (type == 4)
			env->type = check_special(line, env);
		else
		{
			ft_putstr("error: invalid line\n");
			exit(0);
		}
		free(line);
	}
	*room = temp;
}

void	lem_in(t_data *data, t_env *env)
{
	t_data	rooms[env->room_count + 1];
	int		room[env->room_count + 1];

	ant_hill(data, rooms, env->room_count);
	env->room_count++;
	env->room = room;
	env->maze = rooms;
	if (is_end(*env) == 0)
	{
		ft_printf("error: no path found");
		exit(0);
	}
	algo(env);
}

int		main(void)
{
	t_data	*rooms;
	t_env	env;

	rooms = NULL;
	env.room_count = -1;
	extract_data(&env, &rooms);
	ft_putchar('\n');
	lem_in(rooms, &env);
	return (0);
}
