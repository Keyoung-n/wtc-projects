/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcowle <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/07 15:59:48 by kcowle            #+#    #+#             */
/*   Updated: 2016/08/10 16:57:18 by knage            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "twentyonesh.h"

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
	int		i;
	char	**enirok;

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
	enirok = (char**)malloc(sizeof(char**) * i + 2);
	i = 0;
	while (line2[1] && env->enviro[i] != NULL)
	{
		enirok[i] = ft_strnew(ft_strlen(enirok[i]) + 1);
		ft_strcpy(enirok[i], env->enviro[i]);
		i++;
	}

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

void	main_init(t_main *main)
{
	main->line = NULL;
	main->start = -2;
	main->clip = NULL;
	main->buffsize = 0;
	main->a = 0;
	main->y = -1;
	main->lineprom = 0;
	main->quote = 2;
	main->open = 0;
	ft_init(main);
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
	env.prev_pwd = NULL;
	env.cont = 0;
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
	main_init(&w);
	ft_doublecoms(&env, &w);
	return (0);
}
