/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knage <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/19 08:20:47 by knage             #+#    #+#             */
/*   Updated: 2016/07/23 14:16:28 by knage            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	ant_hill(t_data *curr, t_data *rooms, int total)
{
	int	i;

	i = total;
	while (curr)
	{
		rooms[i].name = curr->name;
		rooms[i].bar_code = curr->bar_code;
		rooms[i].links = curr->links;
		free(curr);
		i--;
		curr = curr->next;
	}
}
