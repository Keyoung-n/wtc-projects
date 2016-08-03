/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipes.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcowle <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/19 09:46:36 by kcowle            #+#    #+#             */
/*   Updated: 2016/08/01 15:30:36 by smahomed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#define STDIN	0
#define STDOUT	1

void    ft_minishell2(t_env *env, t_main m)
{
	int i;
	int n;
	int w;

	if (m.line[0] != '\0')
	{
		ft_isbuiltin(env, &m, m.line);
		m.comcount = 0;
		m.line = ft_strtrim(m.line);
		m.line2 = ft_strsplit(m.line, ' ');
		while (m.line2[m.comcount] != NULL)
			m.comcount++;
		*env = get_dir(env, m.line2);
		if (m.line2[0][0] == '/')
		{
			i = 0;
			n = 1;
			w = n;
			while (m.line2[0][n] != '/')
			{
				m.line2[0][i] = m.line2[0][n];
				while (m.line2[0][w] != '\0')
					m.line2[0][n++] = m.line2[0][w++];
				m.line2[0][n] = '\0';
				n = 0;
				w = 1;
			}
			while (m.line2[0][w] != '\0')
				m.line2[0][n++] = m.line2[0][w++];
			m.line2[0][n] = '\0';
		}
		*env = ft_excecute(m.line2, m.comcount, env);
	}
}

void	ft_excve(t_env *env, char **com, int i, t_main *w)
{
	int fd[(i * 2)];
	int x;
	int u;
	int y;
	int n;
	int k;
	int length;

	k = 0;
	u = 0;
	length = 0;
	x = 0;
	y = 1;
	while (x <= (i * 2))
	{
		pipe(fd + x);
		x = x + 2;
	}
	x = (x - 2);
	length = x;
	env->father = fork();
	*env = ft_keep_struct(*env, 0);
	if (env->father >= 0)
	{
		signal(SIGINT, sinno);
		if (env->father == 0)
		{
			dup2(fd[1], STDOUT);
			while (length >= 0)
			{
				close(fd[length]);
				length--;
			}
			w->line = com[0];
			ft_minishell2(env, *w);
			exit(0);
		}
	}
	n = 0;
	while (com[y + 1] != NULL)
	{
		length = x;
		env->father = fork();
		*env = ft_keep_struct(*env, 0);
		if (env->father >= 0)
		{
			signal(SIGINT, sinno);
			if (env->father == 0)
			{
				length = x;
				dup2(fd[n], STDIN);
				dup2(fd[n + 3], STDOUT);
				while (length >= 0)
				{
					close(fd[length]);
					length--;
				}
				w->line = com[y];
				ft_minishell2(env, *w);
				exit(0);
			}
		}
		else
			ft_putstr("FORK");
		y++;
		n = n + 2;
	}
	env->father = fork();
	*env = ft_keep_struct(*env, 0);
	if (env->father >= 0)
	{
		signal(SIGINT, sinno);
		if (env->father == 0)
		{
			length = x;
			dup2(fd[n], STDIN);
			while (length >= 0)
			{
				close(fd[length]);
				length--;
			}
			w->line = com[y];
			ft_minishell2(env, *w);
			exit(0);
		}
	}
	else
		ft_putstr("FORK");
	length = x;
	while (length >= 0)
	{
		close(fd[length]);
		length--;
	}
	while (k <= i)
	{
		wait(NULL);
		k++;
	}
}

int		count_char(char *str, char c)
{
	int i;
	int count;

	count = 0;
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == c)
			count++;
		i++;
	}
	return (count);
}

void	ft_pipes(t_env *env, char **coms, int i, t_main *w)
{
	char **com;

	com = ft_strsplit(coms[i], '|');
	ft_excve(env, com, count_char(coms[i], '|'), w);
}
