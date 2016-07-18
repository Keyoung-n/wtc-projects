/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knage <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/04 14:58:40 by knage             #+#    #+#             */
/*   Updated: 2016/07/18 17:37:17 by knage            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	print_links(t_links *curr)
{
    while (curr)
    {
		ft_putstr("	link:");
        ft_putstr(curr->link);
        ft_putchar('\n');
        curr = curr->next;
    }
}

void	print_list(t_data *curr)
{
    while (curr)
    {
		ft_putstr("name:");
        ft_putstr(curr->name);
        ft_putchar('\n');
        print_links(curr->links);
        curr = curr->next;
    }
}

void	extract_data(t_env *env, t_data **room)
{// error 0 // link 1 // point 2 // commnt 3 // special 4
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

int main(void)
{
	t_data	*rooms;
	t_env	env;

	rooms = NULL;
	env.room_count = 0;
	extract_data(&env, &rooms);
	ft_putchar('\n');
	print_list(rooms);
    //load_data();
	//algo
	//march
	return (0);
}
