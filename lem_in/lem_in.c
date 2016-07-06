/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knage <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/04 14:58:40 by knage             #+#    #+#             */
/*   Updated: 2016/07/06 16:11:52 by knage            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	extract_data(t_env *env, t_data *room)
{// error 0 // link 1 // point 2 // comment 3 // special 4
	char	*line;
	int		type;
	int		special;

	get_ant_numbers(env);
	special = 0;
	while (get_next_line(0, &line))
	{
		type = what_type(line);
		if (type == 1)
			get_link(line, room);
		else if (type == 2)
			get_room(line, room);
		else if (type == 3)
			;
		else if (type == 4)
			special = check_special(line, special);
		else
		{
			ft_putstr("error\n");
			exit(0);
		}
	}
}

int main(void)
{
	t_data	*rooms;
	t_env	env;

	rooms = NULL;
	extract_data(&env, rooms);
    //load_data();
	//algo
	//print
	return (0);
}
