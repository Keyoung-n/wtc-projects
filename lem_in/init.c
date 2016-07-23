/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knage <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/22 10:31:25 by knage             #+#    #+#             */
/*   Updated: 2016/07/23 09:38:49 by knage            ###   ########.fr       */
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

void    ant_wait(t_env *env)
{
    t_links *temp;
    
    temp = (t_links *)malloc(sizeof(t_links));
    temp->bar_code = -1;
    temp->next = env->start;
    env->start = temp;
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

void    fill_room(t_env *env, t_links *temp, int node)
{
    t_links *temp1;
    
    if (node != env->special[1])
        env->room[node] = 1;
    temp1 = (t_links *)malloc(sizeof(t_links));
    temp1->bar_code = node;
    temp1->counter += 1;
    temp1->path = create_path(temp->path, node);
    temp1->next = env->stack[env->nodes_count[0]];
    env->stack[env->nodes_count[0]] = temp1;
}
