/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knage <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/04 14:58:40 by knage             #+#    #+#             */
/*   Updated: 2016/07/22 13:35:03 by knage            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	print_links(t_links *curr)
{
	while (curr)
	{
		ft_putstr("	link:");
		ft_putnbr(curr->bar_code);
		ft_putchar('\n');
		curr = curr->next;
	}
}

void	print_list(t_data *rooms, t_env *env)
{
	int i;

	i = 0;
	ft_putstr("start: ");
	ft_putnbr(env->special[0]);
	ft_putchar('\n');
	ft_putstr("end: ");
	ft_putnbr(env->special[1]);
	ft_putchar('\n');
	while (i != env->room_count)
	{
		ft_printf("name: %s bar_code: %i\n", rooms[i].name, rooms[i].bar_code);
		print_links(rooms[i].links);
		i++;
	}
}

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
	print_list(rooms, env);
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
