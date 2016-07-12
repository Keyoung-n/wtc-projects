/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knage <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/04 14:58:40 by knage             #+#    #+#             */
/*   Updated: 2016/07/12 07:30:16 by knage            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	extract_data(t_env *env, t_data **room)
{// error 0 // link 1 // point 2 // commnt 3 // special 4
	char	*line;
	int		type;
	t_data	*temp;

	get_ant_numbers(env);
	temp = *room;
	while (get_next_line(0, &line))
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
	}
	*room = temp;
}

void	print_links(t_links *curr)
{
	while (curr)
	{
		ft_printf("link = %s\n", curr->link);
		curr = curr->next;
	}
}

void	print_list(t_data *curr)
{
	while (curr)
	{
		ft_printf("name = %s, x:y = %i:%i type = %i\n", curr->name, curr->x, curr->y, curr->type);
		print_links(curr->links);
		curr = curr->next;
	}
}

int main(void)
{
	t_data	*rooms;
	t_env	env;

	rooms = NULL;
	extract_data(&env, &rooms);
	print_list(rooms);
    //load_data();
	//algo
	//march
	return (0);
}
