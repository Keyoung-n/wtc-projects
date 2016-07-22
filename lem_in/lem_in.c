/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knage <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/04 14:58:40 by knage             #+#    #+#             */
/*   Updated: 2016/07/21 16:20:54 by knage            ###   ########.fr       */
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

void	print_list(t_data *curr, t_env *env)
{
	ft_putstr("start: ");
	ft_putnbr(env->special[0]);
	ft_putchar('\n');
	ft_putstr("end: ");
	ft_putnbr(env->special[1]);
	ft_putchar('\n');
	while (curr)
	{
		ft_putstr("name:");
		ft_putstr(curr->name);
		ft_putchar(' ');
		ft_putnbr(curr->bar_code);
		ft_putchar('\n');
		print_links(curr->links);
		curr = curr->next;
	}
}

void	extract_data(t_env *env, t_data **room)
{
	char	*line;
	int		type;
	t_data	*temp;

	get_ant_numbers(env);
	temp = *room;
	while (get_next_line(0, &line))
	{
		ft_putstr(line);
		ft_putchar('\n');
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
	int		o[env->room_count + 1];
	int		i;

	i = 0;
	ant_hill(data, rooms);
	env->room_count++;
	env->o = o;
	env->a = rooms;
	ft_leminalg(env);
//index
//march
}

int		main(void)
{
	t_data	*rooms;
	t_env	env;

	rooms = NULL;
	env.room_count = -1;
	extract_data(&env, &rooms);
	ft_putchar('\n');
	print_list(rooms, &env);
	lem_in(rooms, &env);
	return (0);
}
