/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcowle <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/12 10:52:00 by kcowle            #+#    #+#             */
/*   Updated: 2016/08/22 11:22:14 by kcowle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fortytwosh.h"

void	exclamation_history(t_env *env, t_main *w)
{
	int     x;
	int num;

	w->line++;
	num = ft_atoi(w->line);
	x = 0;
	while (x <= w->y)
	{
		if (x + 1 == num)
		{
			w->line = w->a[x].line;
			ft_putstr(w->line);
			ft_putchar('\n');
			ft_doublecoms(env, w, 0);
		}
		x++;
	}
}

void	ft_if_else(t_env *env, t_main *w)
{
	int i;
	int and;
	int or;
	char *bk;
	char **line2;

	bk = w->line;
	i = 0;
	and = ft_ifindstr(w->line, "&&");
	or = ft_ifindstr(w->line, "||");
	if (and < or)
	{
		line2 = ft_strsplit(w->line, '&');
		w->line = line2[0];
		ft_minishell(env, w);
		if (WIFEXITED(env->father) == 0)
		{
			line2 = ft_strsplit(line2[1], '|');
			w->line = line2[0];
			ft_minishell(env, w);
		}
		else
		{
			line2 = ft_strsplit(line2[1], '|');
			w->line = line2[1];
			ft_minishell(env, w);
		}
	}
	else if (and > or)
	{
		line2 = ft_strsplit(w->line, '|');
		w->line = line2[0];
		ft_minishell(env, w);
		if (WIFEXITED(env->father) != 0)
		{
			line2 = ft_strsplit(line2[1], '&');
			w->line = line2[0];
			ft_minishell(env, w);
		}
		else
		{
			line2 = ft_strsplit(line2[1], '&');
			w->line = line2[1];
			ft_minishell(env, w);
		}
	}
	ft_doublecoms(env, w, 1);
}

void	ft_history(t_main *w)
{
	int		x;

	x = 0;
	while (x < w->y)
	{
		ft_putstr("\t");
		ft_putnbr(x + 1);
		ft_putstr("\t");
		ft_putstr(w->a[x].line);
		ft_putchar('\n');
		x++;
	}
}

void	ft_pp(t_env *env, t_main *w)
{
	int i;
	char **line2;

	i = 0;
	w->line = ft_strtrim(w->line);
	line2 = ft_strsplit(w->line, '|');
	while (line2[i] != NULL)
	{
		w->line = line2[i];
		ft_minishell(env, w);
		if (WIFEXITED(env->father) == 0)
			i++;
		else
			ft_doublecoms(env, w, 1);
	}
}

void	ft_aa(t_env *env, t_main *w)
{
	int i;
	char **line2;

	i = 0;
	w->line = ft_strtrim(w->line);
	line2 = ft_strsplit(w->line, '&');
	while (line2[i] != NULL)
	{
		w->line = line2[i];
		ft_minishell(env, w);

		if (WIFEXITED(env->father) != 0)
			i++;
		else
			ft_doublecoms(env, w, 1);
	}
}

void	semicolon(t_main *w, t_env *env, char **coms)
{
	int	i;

	i = 0;
	coms = ft_strsplit(w->line, ';');
	while (coms[i] != NULL)
	{
		w->line = ft_strtrim(coms[i]);
		ft_minishell(env, w);
		i++;
	}
}

void	com_pipes(t_main *w, t_env *env, char **coms)
{
	int	i;

	i = 0;
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

void	ft_doublecoms(t_env *env, t_main *w, int test)
{
	char		**coms;
	int 		i;

	i = 0;
	coms = NULL;
	w->line = NULL;
	ft_selectinit(w);
	if (test == 1)
	{
		while (ft_select(w, &w->line))
			;
	}
	ft_selectend(w);
	w = ft_keep_main(*w, 0);
	if (ft_findstr("&&", w->line) != 0 && ft_findstr("||", w->line) != 0 && (i = 1))
		ft_if_else(env, w);
	else if (ft_strchr(w->line, '|') != 0 && ft_ifindstr(w->line, "||") == -1)
		com_pipes(w, env, coms);
	else if ((ft_strchr(w->line, '>') != 0 || ft_strchr(w->line, '<') != 0 ))
		ft_redirect(w, env);
	else if (ft_strchr(w->line, ';') == 0)
		ft_minishell(env, w);
	else if (ft_strchr(w->line, '|') == 0 && ft_strchr(w->line, ';') != 0)
		semicolon(w, env, coms);
	if (i == 0)
		ft_doublecoms(env, w, 1);
}
