/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   non_canonical3.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcowle <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/04 16:19:04 by kcowle            #+#    #+#             */
/*   Updated: 2016/08/04 16:19:07 by kcowle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "21sh.h"

int		ft_selectremalloc(t_main *e)
{
	char    *tmp;
	int     x;

	x = -1;
	e->a[e->y].buff += 1024;
	tmp = (char *)malloc(sizeof(char) * e->a[e->y].buff);
	while (e->a[e->y].line[++x])
		tmp[x] = e->a[e->y].line[x];
	if (e->a[e->y].line)
		free(e->a[e->y].line);
	e->a[e->y].line = tmp;
	return (0);
}

void    ft_exit(t_env *env, t_main *w)
{
        tputs(tgetstr("te", NULL), 1, ft_ft_putchar);
        ft_selectend(w);
        kill(env->father, SIGTERM);
}