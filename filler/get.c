/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knage <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/12 16:52:27 by knage             #+#    #+#             */
/*   Updated: 2016/06/12 16:52:57 by knage            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"
#include "libft/libft.h"

int		get_player_number(char **line)
{
	static int number = 0;

	if (line[0][0] == '$' && line[0][1] == '$' && line[0][2] == '$' &&  \
			line[0][ft_strlen(*line) - 2] == 'r'\
			&& line[0][ft_strlen(*line) - 3] == 'e' \
			&& line[0][ft_strlen(*line) - 4] == 'l' &&\
			line[0][ft_strlen(*line) - 5] == 'l')
	{
		if (line[0][10] == '1')
			number = 1;
		else if (line[0][10] == '2')
			number = 2;
	}
	else
	{
		get_next_line(0, line);
		get_player_number(line);
	}
	return (number);
}

void	getmap(t_env *env, t_raw_map **map, char **line)
{
	int	i;

	i = 1;
	insert_line(*line, map);
	while (get_next_line(0, line) > 0 && i < env->map.map_y)
	{
		insert_line(*line, map);
		++i;
	}
}

void	getpiece(t_env *env, char **line, char **line2)
{
	int		i;
	char	*line3;

	i = 0;
	line2 = ft_strsplit(*line, ' ');
	env->piece.piece_y = atoi(line2[1]);
	env->piece.piece_x = atoi(line2[2]);
	env->piece.piece_a = env->piece.piece_y * env->piece.piece_x;
	line3 = (char *)malloc(sizeof(char *) * env->piece.piece_a);
	while (i < env->piece.piece_y)
	{
		get_next_line(0, line);
		ft_strcat(line3, *line);
		i++;
	}
	insert_piece(line3, env);
}

void	getmapsize(t_env *env, char *line, char **line2)
{
	while (line[0] != 'P' || line[1] != 'l' || line[2] != 'a' || \
			line[3] != 't' || line[4] != 'e')
	{
		get_next_line(0, &line);
	}
	line2 = ft_strsplit(line, ' ');
	env->map.map_y = ft_atoi(line2[1]);
	line = strcut(line2[2], 1);
	env->map.map_x = ft_atoi(line);
}

int		get_map(t_env env)
{
	char		*line;
	char		**line2;
	t_raw_map	*b[3];
	int			result;

	result = 0;
	line2 = NULL;
	get_next_line(0, &line);
	b[1] = NULL;
	getmapsize(&env, line, line2);
	get_next_line(0, &line);
	while (ft_isdigit(line[0]) && ft_isdigit(line[1]) && ft_isdigit(line[2]))
		get_next_line(0, &line);
	while (env.player == 1 || env.player == 2)
	{
		result = play(&env, line, line2, b);
		if (result == 2)
		{
		}
		else if (result == -1)
			get_next_line(0, &line);
		else
			return (result);
	}
	return (0);
}
