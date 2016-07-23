/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knage <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/22 10:31:25 by knage             #+#    #+#             */
/*   Updated: 2016/07/22 12:25:17 by knage            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void    ft_initrooms(t_env *env)
{
    int x;
    
    x = 0;
    while (x < env->room_count)
    {
        env->room[x] = 0;
        x++;
    }
}

t_links *create_path(t_links *path, int node)
{
    t_links *temp;
    
	temp = (t_links *)malloc(sizeof(t_links));
    temp->bar_code = node;
    temp->next = path;
    path = temp;
    return (path);
}

void    setnode(t_env *env, int node)
{
    t_links *temp;
    
    if (node != env->special[1])
        env->room[node] = 1;
    temp = (t_links *)malloc(sizeof(t_links));
    temp->bar_code = node;
    temp->counter = 1;
    temp->path = env->start;
    temp->path = create_path(temp->path, node);
    temp->next = env->stack[env->nodes_count[0]];
    env->stack[env->nodes_count[0]] = temp;
}
