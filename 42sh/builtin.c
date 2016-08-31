/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knage <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/12 07:30:39 by knage             #+#    #+#             */
/*   Updated: 2016/08/23 16:16:13 by kcowle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fortytwosh.h"

t_env       *ft_vars(t_env *env, t_main *w);

int		ft_builtin2(t_env *env, t_main *w)
{
	char	**line2;
	int		i;
	char	*temp;

	i = 0;
	temp = NULL;
	line2 = NULL;
	line2 = ft_strsplit(w->line, ' ');
	temp = ft_strtrim(line2[0]);
	free(line2[0]);
	line2[0] =NULL;
	line2[0] = (char *)malloc(sizeof(char *) * ft_strlen(temp) + 1);
	ft_strcpy(line2[0], temp);
	if (temp != NULL)
	{
		free(temp);
		temp = NULL;
	}
	if (ft_strncmp(w->line, "env", 2) == 0 && (i = 1))
		print_env(env);
	else if (ft_strncmp(w->line, "setenv", 5) == 0 && (i = 1))
	{
		temp = ft_strdup(w->line);
		free(w->line);
		w->line = NULL;
		w->line = ft_strtrim(temp);
		ft_free2d(line2);
		line2 = NULL;
		free(temp);
		temp =NULL;
		line2 = ft_strsplit(w->line, ' ');
		env = set_env(line2, env);
	}
	else if (ft_isdigit(w->line[0]) == 1 && w->line[1] == '>'
			&& w->line[2] == '&' && (i = 1))
		ft_fdfuncs(w->line);
	else if(ft_strchr(line2[0], '=') != 0 && (i = 1))
		env = ft_vars(env, w);
	ft_free2d(line2);
	line2 = NULL;
	return (i);
}

t_env		*change_var(t_env *env, char *line)
{
	char	**args;
	int		i;

	args = ft_strsplit(line, '=');
	i = 0;
	while (env->vars[i] != NULL)
	{
		if (ft_strncmp(args[0], env->vars[i], ft_strlen(args[0])) == 0)
		{
			env->vars[i] = ft_strpaste(env->vars[i], ft_ifindstr(env->vars[i], "=") + 1, args[1], ft_strlen(env->vars[i]));
			ft_free2d(args);
			args = NULL;
			return (env);
		}
		i++;
	}
	if (args != NULL)
	{
		ft_free2d(args);
		args = NULL;
	}
	return (env);
}

t_env		*ft_vars(t_env *env, t_main *w)
{
	int		i;
	int		x;
	int		num;
	char	**temp;
	char	*test;
	char 	*tmp;

	i = 0;
	x = 0;
	tmp = ft_strtrim(w->line);
	test = ft_strdup(w->line);
   	test[ft_ifindstr(test, "=")] = '\0';
   	if (ft_getvar(env, test) == NULL && tmp[ft_ifindstr(test, "=") + 1] !=  '\0')
	{
		free(tmp);
		tmp = NULL;
		temp = (char **)malloc(sizeof(char **) * 2);
		temp[0] = NULL;
		if (env->vars != NULL)
		{
			num = ft_strlen2D(env->vars);
			ft_free2d(temp);
			temp = NULL;
			temp = (char **)malloc(sizeof(char **) * (num + 2));
			while (env->vars[i] != NULL)
			{
				temp[i] = (char *)malloc(sizeof(char *) * (ft_strlen(env->vars[i]) + 1));
				ft_strcpy(temp[i], env->vars[i]);
				i++;
			}
		}
		w->line = ft_strtrim(w->line);
		temp[i] = (char *)malloc(sizeof(char *) * ft_strlen(w->line) + 1);
		temp[i + 1] = NULL;
		ft_strcpy(temp[i], w->line);
		x = ft_ifindstr(temp[i], "=");
		x--;
		while (temp[i][x] != '\0' && ft_isalnum(temp[i][x]) && x >= 0)
			x--;
		x++;
		if (x == 0)
		{
			x = ft_ifindstr(temp[i], "=") + 1;
			while (temp[i][x] != '\0' && ft_isprint(temp[i][x]))
				x++;
			if (x == ft_strlen(temp[i]))
			{
				env->vars = (char **)malloc(sizeof(char **) * ft_strlen2D(temp) + 1);
				i = 0;
				while (temp[i] != NULL)
				{
					env->vars[i] = (char *)malloc(sizeof(char *) * ft_strlen(temp[i]));
					ft_strcpy(env->vars[i], temp[i]);
					i++;
				}
				env->vars[i] = NULL;
			}
			else
				ft_putstr("Only printable characters allowed for the data of the local variable\n");
		}
		else
			ft_putstr("Only alpha numeric characters allowed for the name of the local variable\n");
		if (temp != NULL)
			ft_free2d(temp);
	}
	else
		env = change_var(env, w->line);
	env = ft_keep_struct(*env, 0);
	if (tmp != NULL)
	{
		free(tmp);
		tmp = NULL;
	}
	if (test != NULL)
	{
		free(test);
		test = NULL;
	}
	return (env);
}

void	ft_printvars(t_env *env)
{
	int i;

	i = 0;
	while (env->vars[i] != NULL)
	{
		ft_putstr(env->vars[i]);
		ft_putchar('\n');
		i++;
	}
}

int     ft_isbuiltin(t_env *env, t_main *w)
{
	int     i;
	char    **line2;
	char	*temp;

	i = 0;
	line2 = NULL;
	line2 = ft_strsplit(w->line, ' ');
	temp = ft_strtrim(line2[0]);
	free(line2[0]);
	line2[0] = NULL;
	line2[0] = (char *)malloc(sizeof(char *) * ft_strlen(temp) + 1);
	ft_strcpy(line2[0], temp);
	free(temp);
	temp = NULL;
	if (ft_strcmp(line2[0], "printvars") == 0 && (i = 1))
		ft_printvars(env);
	else if(ft_strchr(line2[0], '=') != 0 && (i = 1))
		env = ft_vars(env, w);
	else if (ft_strcmp(line2[0], "history") == 0 && (i = 1))
		ft_history(w);
	else if (ft_strncmp(line2[0], "export", 6) == 0 && (i = 1))
		env = export_var(env, line2);
	else if (ft_findstr("&&", w->line)  == 1 && (i = 1))
		ft_aa(env, w);
	else if (ft_findstr("||", w->line) == 1 && (i = 1))
		ft_pp(env, w);
	else if (ft_strcmp(line2[0], "echo") == 0 && (i = 1)) {
		temp = ft_strfcut(w->line, 5);
		if (w->line != NULL)
		{
			free(w->line);
			w->line = NULL;
		}
		w->line = (char *)malloc(sizeof(char *) * ft_strlen(temp) + 1);
		ft_strcpy(w->line, temp);
		free(temp);
		temp = NULL;
		ft_echo(env, w->line);
	}
	else if (ft_strncmp(w->line, "cd", 2) == 0 && (i = 1))
		ft_cd(w->line, env);
	else if (ft_strcmp(w->line, "clear") == 0 && (i = 1))
		tputs(tgetstr("cl", NULL), 1, ft_ft_putchar);
	else if (ft_strncmp(w->line, "unsetenv", 7) == 0 && (i = 1))
	{
		ft_free2d(line2);
		line2 = NULL;
		line2 = ft_strsplit(w->line, ' ');
		env = ft_unsetenv(env, line2[1]);
	}
	else if (i == 0)
		i = ft_builtin2(env, w);
	if (line2 != NULL)
	{
		ft_free2d(line2);
		line2 = NULL;
	}
	return (i);
}
