/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcowle <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/10 14:07:10 by kcowle            #+#    #+#             */
/*   Updated: 2016/08/06 13:31:01 by knage            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "21sh.h"
#include <stdio.h>

void	print_env(t_env *env)
{
	int i;

	i = 0;
	while (env->enviro[i] != NULL)
	{
		ft_putstr(env->enviro[i]);
		ft_putchar('\n');
		i++;
	}
}

t_env	*set_env(char **line2, t_env *env)
{
	int i;

	i = 1;
	while (line2[1] && env->enviro[i] != NULL)
	{
		if (ft_strncmp(line2[1], env->enviro[i], 4) == 0)
		{
			env->enviro[i] = (char *)malloc(sizeof(char *) *\
					ft_strlen(line2[1]));
			ft_strcpy(env->enviro[i], line2[1]);
			return (env);
		}
		i++;
	}
	ft_putstr("env variable \"");
	ft_putstr(line2[1]);
	ft_putstr("\" not found.\n");
	return (env);
}

t_env	*ft_unsetenv(t_env *env)
{
	int i;

	i = 0;
	while (env->envirobk[i] != NULL)
	{
		ft_strcpy(env->enviro[i], env->envirobk[i]);
		i++;
	}
	return (env);
}

void	ft_minishell(t_env *env, t_main *m)
{
	int i;
	int n;
	int w;

	if (m->line[0] != '\0')
	{
		if (m->line[0] == '.' && m->line[1] == '/')
			m->line = ft_strfcut(m->line, 2);
		if (ft_isbuiltin(env, m, m->line))
		{
			m->comcount = 0;
			env->father = fork();
			*env = ft_keep_struct(*env, 0);
			*m = ft_keep_main(*m, 0);
			if (env->father >= 0)
			{
				signal(SIGINT, sinno);
				if (env->father == 0)
				{
                    if (ft_strcmp(m->line, "exit") == 0)
                        ft_exit(env, m);
					m->line = ft_strtrim(m->line);
					m->line2 = ft_strsplit(m->line, ' ');
					while (m->line2[m->comcount] != NULL)
						m->comcount++;
					*env = get_dir(env, m->line2);
					if (m->line2[0][0] == '/')
					{
						i = 0;
						n = 1;
						w = n;
						while (m->line2[0][n] != '/')
						{
							m->line2[0][i] = m->line2[0][n];
							while (m->line2[0][w] != '\0')
								m->line2[0][n++] = m->line2[0][w++];
							m->line2[0][n] = '\0';
							n = 0;
							w = 1;
						}
						while (m->line2[0][w] != '\0')
							m->line2[0][n++] = m->line2[0][w++];
						m->line2[0][n] = '\0';
					}
					*env = ft_excecute(m->line2, m->comcount, env);
				}
				else
				{
					wait(NULL);
					wait(NULL);
				}
			}
		}
	}
}

int		main(void)
{
	t_env			env;
	extern char		**environ;
	int				i;
	int				n;
	t_main			w;

	n = 0;
	i = 0;
	w.line = NULL;
	env.cont = 0;
	w.start = -2;
	w.clip = NULL;
	w.buffsize = 0;
	w.a = 0;
	w.y = -1;
	w.lineprom = 0;
    w.quote = 2;
	while (environ[i] != NULL)
		i++;
	env.enviro = (char **)malloc(sizeof(char **) * i + 1);
	env.envirobk = (char **)malloc(sizeof(char **) * i + 1);
	while (n < i)
	{
		env.enviro[n] = (char *)malloc(sizeof(char *) * ft_strlen(environ[n]));
		env.envirobk[n] = (char *)malloc(sizeof(char *) *\
				ft_strlen(environ[n]));
		ft_strcpy(env.enviro[n], environ[n]);
		ft_strcpy(env.envirobk[n], environ[n]);
		n++;
	}
	ft_init(&w, 0);
	ft_doublecoms(&env, &w, 2);
	return (0);
}
