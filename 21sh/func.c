/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knage <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/10 13:39:50 by knage             #+#    #+#             */
/*   Updated: 2016/07/10 13:40:08 by knage            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "21sh.h"

void	ft_getenv(char *text)
{
	extern	char	**environ;
	int				i;

	i = 0;
	while (environ[i] != NULL)
	{
		if (ft_strncmp(text, environ[i], ft_strlen(text) - 1) == 0)
			ft_putstr(environ[i]);
		i++;
	}
}

int		ft_pow(int n, int p)
{
	int		result;

	result = 1;
	if (p < 0)
		return (0);
	while (p > 0)
	{
		result *= n;
		p--;
	}
	return (result);
}

void	ft_echo(char *line)
{
	t_echo	ec;

	init_echo(line, &ec);
	if (ec.e == 1)
	{
		ft_putstr(line);
		if (ec.newline == 0)
			ft_putchar('\n');
		return ;
	}
	if (line[0] == '$')
	{
		ft_getenv(line + 1);
		ec.state = 0;
	}
	ec.i = 0;
	ft_handle3(&ec, line);
}

char	*get_path(t_env *env)
{
	int			i;
	char		*tmp;
	extern char	**environ;

	i = 0;
	while (1)
	{
		if (ft_strncmp(env->enviro[i], "PATH", 3) == 0)
		{
			tmp = (char *)malloc(sizeof(char *) * ft_strlen(env->enviro[i]));
			ft_strcpy(tmp, env->enviro[i]);
			break ;
		}
		i++;
	}
	tmp[ft_strlen(tmp) + 1] = '\0';
	return (tmp);
}
