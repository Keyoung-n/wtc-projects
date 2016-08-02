/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tricks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knage <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/31 14:41:03 by knage             #+#    #+#             */
/*   Updated: 2016/08/02 09:06:58 by knage            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void    ft_copy(t_main *env)
{
    if (env->start > env->end)
        env->clip = ft_strsub(env->a[env->y].line, env->end + 1, env->start);
    if (env->end > env->start)
        env->clip = ft_strsub(env->a[env->y].line, env->start + 1, env->end);
    ft_printstring(env + 0 * (env->start = -2));
}

void    ft_paste(t_main *env)
{
    char *temp1;
    char *temp2;
    
    temp1 =  ft_strjoin(ft_strsub(env->a[env->y].line, 0, env->cursor), env->clip);
    temp2 = ft_strsub(env->a[env->y].line, env->cursor, ft_strlen(env->a[env->y].line));
    env->a[env->y].x = ft_strlen(env->a[env->y].line) + ft_strlen(env->clip);
    env->a[env->y].line = ft_strmerge(temp1, temp2);
	env->cursor += ft_strlen(env->clip);
    ft_printstring(env);
}

void    ft_cut(t_main *env)
{
	char *temp1;
	char *temp2;

    if (env->start > env->end)
    {
        env->clip = ft_strsub(env->a[env->y].line, env->end + 1, env->start);
        env->a->x = ft_strlen(env->a[env->y].line) - ft_strlen(env->clip);
        temp1 = ft_strsub(env->a[env->y].line, 0, env->end + 1);
        temp2 = ft_strsub(env->a[env->y].line, env->start, ft_strlen(env->a[env->y].line));
        env->a[env->y].line = ft_strmerge(temp1, temp2);
    }
    if (env->end > env->start)
    {
        env->clip = ft_strsub(env->a[env->y].line, env->start + 1,env->end);
        env->a->x = ft_strlen(env->a[env->y].line) - ft_strlen(env->clip);
        temp1 = ft_strsub(env->a[env->y].line, 0, env->start + 1);
        temp2 = ft_strsub(env->a[env->y].line, env->end, ft_strlen(env->a[env->y].line));
        env->a[env->y].line = ft_strmerge(temp1, temp2);
    }
    env->start = -2;
    ft_printstring(env);
}
