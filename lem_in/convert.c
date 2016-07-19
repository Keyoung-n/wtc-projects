/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knage <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/19 08:20:47 by knage             #+#    #+#             */
/*   Updated: 2016/07/19 11:05:28 by knage            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_room	*ant_hill(t_data *curr, int i)
{
    t_room *rooms;
    
    rooms = (t_room*)malloc(sizeof(t_room*) * i);
	while (curr)
	{
		rooms[i].name = curr->name;
		rooms[i].ant = 0;
		rooms[i].links = curr->links;
		free(curr);
		i--;
		curr = curr->next;
	}
    return (rooms);
}
