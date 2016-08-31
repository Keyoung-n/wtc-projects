
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_str.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knage <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/25 08:41:34 by knage             #+#    #+#             */
/*   Updated: 2016/08/25 14:42:14 by knage            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fortytwosh.h"

int	select_char(t_keyhook *env, char buff[4])
{
	if (buff[0] == -30 && buff[1] == -119 && buff[2] == -92)
	{
		if (env->start == -2 && ((env->start = env->cursor) || 1))
			env->end = env->cursor - 1;
		env->cursor--;
		env->end--;
		if (env->start == env->end - 1 && (env->end = -2))
			env->start = -2;
	}
	else if (buff[0] == -30 && buff[1] == -119 && buff[2] == -91)
	{
		if (env->start == -2 && ((env->start = env->cursor - 1) || 1))
			env->end = env->cursor;
		env->cursor += (env->cursor != env->x);
		env->end++;
		if (env->start == env->end - 1 && (env->end = -2))
			env->start = -2;
	}
	else if (!buff[1] && (buff[0] == 32 || ft_isprint(buff[0])))
	{
		insert_char(env, buff[0]);
		if (env->cursor < env->x + 1)
			env->cursor += 1;
	}
	else
		return (0);
	return (1);
}

int		extra_keyhooks(t_keyhook *env, char buff[4])
{
	if (buff[0] == 27 && buff[1] == 91 && buff[2] == 51 && buff[3] == 126)
	{
		if (env->x > -1 && env->cursor <= env->x)
		{
			remove_last_char(env);
			--env->x;
		}
	}
	else if (buff[0] == -30 && buff[1] == -119 && buff[2] == -120 && !buff[3])
		cut(env);
	else if (buff[0] == -61 && buff[1] == -89 && !buff[2] && !buff[3])
		copy(env);
	else if (buff[0] == -30 && buff[1] == -120 && buff[2] == -102 && !buff[3])
		paste(env);
	else if (buff[0] == 27 && buff[1] == 91 && buff[2] == 53
			&& buff[3] == 126 && env->x > -1)
		env->cursor = 0;
	else if (buff[0] == -30 && buff[1] == -120 && buff[2] == -111 && !buff[3])
		env->cursor = ft_ctrlup(env->cursor, env->x);
	else if (buff[0] == -61 && buff[1] == -97 && !buff[2] && !buff[3])
		env->cursor = ft_ctrldown(env->cursor, env->x);
	else
		select_char(env, buff);
	return (1);
}

int		word_jump(t_keyhook *env, char buff[4])
{
	if (buff[0] == 27 && buff[1] == 91 && buff[2] == 54 && buff[3] == 126)
		env->cursor = env->x + 1;
	else if (buff[0] == 27 && buff[1] == 91 && buff[2] == 72 && !buff[3])
	{
		while (env->cursor > 0 && env->line[env->cursor - 1] == ' ')
			env->cursor -= 1;
		while (env->cursor > 0 && env->line[env->cursor - 1] != ' ')
			env->cursor -= 1;
	}
	else if (buff[0] == 27 && buff[1] == 91 && buff[2] == 70 && !buff[3])
	{
		while (env->cursor <= env->x
				&& env->line[env->cursor + 1] == ' ')
			env->cursor += 1;
		while (env->cursor <= env->x
				&& env->line[env->cursor + 1] != ' ')
			env->cursor += 1;
		env->cursor = env->cursor * (env->cursor >= env->x)\
					  + (env->cursor + 2) * (env->cursor < env->x);
	}
	else
		extra_keyhooks(env, buff);
	return (1);
}

int		ctrl_v(t_keyhook *env, char buff[4])
{
	if (buff[0] == 22 && !buff[1] && !buff[2] && !buff[3])
		env->ctrl_v = 1;
	else
		word_jump(env, buff);
	return (1);
}

char	*get_str(char *promt, char ret)
{
	char		b[8];
	char		*temp;
	t_keyhook	env;

	key_hook_init(&env);
	env.pro = promt;
	env.ret = ret;
	while (1)
	{
		ft_bzero(b, 8);
		printline(&env);
		read(0, b, 8);
		if (ft_isprint(b[0]) && env.x >= env.buff)
			malloc_buff(&env);
		else if (b[0] == 127 && env.x > -1 && env.cursor > 0)
		{
			remove_char(&env);
			--env.x;
		}
		else if (b[0] == 27 && b[1] == 91 && b[2] == 67 && b[3] == 0)
		{
			env.start = -2;
			if (env.cursor < env.x + 1)
				env.cursor += 1;
		}
		else if (b[0] == 27 && b[1] == 91 && b[2] == 68 && b[3] == 0)
		{
			env.start = -2;
			if (env.cursor > 0)
				env.cursor -= 1;
		}
		//  else if (b[0] == 9 && !b[1])
		//        return (ft_tab(e));
		else if (b[0] == env.ret && !b[1])
		{
			printline(&env);
			env.cursor = -2;
			temp = (char *)malloc(sizeof(char *) * ft_strlen(env.line) + 1);
			ft_strcpy(temp, env.line);
			free(env.line);
			env.line = ft_strtrim(temp);
			free(temp);
			variable_check(env.line);
			env.line[env.x + 1] = '\0';
			return (env.line);
		}
		if (b[0] == '\n')
		{
			env.cursor = -3;
			printline(&env);
			ft_putchar('\n');
			insert_char(&env, '\n');
			temp = get_str(promt, ret);
			ft_printf("ret = %s\n", temp);
			return (ft_strjoin(env.line, temp));
		}
		ctrl_v(&env, b);
	}
	return(get_str(promt, ret));
}
