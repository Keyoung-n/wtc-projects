/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knage <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/19 14:24:09 by knage             #+#    #+#             */
/*   Updated: 2016/06/19 14:24:19 by knage            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

time_t	get_mtime(const char *path)
{
	struct stat	statbuf;

	if (stat(path, &statbuf) == -1)
		exit(1);
	return (statbuf.st_mtime);
}

void	add_element_by_time(t_list **list, char *value)
{
	t_list	*add;

	add = (t_list *)malloc(sizeof(t_list *));
	add->file_name = value;
	while (*list != 0)
	{
		if (get_mtime((*list)->file_name) < get_mtime(add->file_name))
			break ;
		list = &(*list)->next;
	}
	add->next = *list;
	*list = add;
}
