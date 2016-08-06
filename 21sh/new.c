/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcowle <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/02 16:23:42 by kcowle            #+#    #+#             */
/*   Updated: 2016/08/04 14:35:48 by kcowle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "21sh.h"

void	ft_doublecoms(t_env *env, t_main *w, int getl)
{
	char		**coms;
	int			y;
	int			i;
	char		*com;
	char		*str;
	int			x;

	w->line = NULL;
	x = 1;
	y = 0;
	i = 0;
    ft_selectinit(w);
	while (ft_select(w, &w->line))
		;
    ft_selectend(w);
	*w = ft_keep_main(*w, 0);
	if (ft_strchr(w->line, ';') == 0 && ft_strchr(w->line, '|') == 0)
		ft_minishell(env, w);
	else if (ft_strchr(w->line, '|') == 0 && ft_strchr(w->line, ';') != 0)
	{
		coms = ft_strsplit(w->line, ';');
		while (coms[y] != NULL)
		{
			w->line = ft_strtrim(coms[y]);
			ft_minishell(env, w);
			y++;
		}
	}
	else if (ft_strchr(w->line, '|') != 0)
	{
		coms = ft_strsplit(w->line, ';');
		while (coms[i] != NULL)
		{
			if (ft_strchr(coms[i], '|') == 0)
			{
				w->line = ft_strtrim(coms[i]);
				ft_minishell(env, w);
			}
			else if (ft_strchr(coms[i], '|') != 0)
				ft_pipes(env, coms, i, w);
			i++;
		}
	}
	ft_doublecoms(env, w, 0);
}
