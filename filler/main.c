/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knage <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/12 16:52:27 by knage             #+#    #+#             */
/*   Updated: 2016/06/12 16:52:57 by knage            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft/libft.h"
#include "filler.h"

void	reverse_map(t_raw_map **b)
{
	b[1] = 0;
	while (b[0])
	{
		b[2] = b[0]->next;
		b[0]->next = b[1];
		b[1] = b[0];
		b[0] = b[2];
	}
}

void	free_two_d(char **array, int rows)
{
	int	i;

	i = 0;
	while (i != rows)
	{
		free(array[i]);
		i++;
	}
	free(array);
}

int		play(t_env *env, char *line, char **line2, t_raw_map **b)
{
	if (ft_isdigit(line[0]) && ft_isdigit(line[1]) && ft_isdigit(line[2]))
	{
		getmap(env, b, &line);
		getpiece(env, &line, line2);
		reverse_map(b);
		if (algo(env, b) == 0)
		{
		}
		else
		{
			free_two_d(env->piece.piece, env->piece.piece_y);
			return (1);
		}
		free_two_d(env->piece.piece, env->piece.piece_y);
		return (0);
	}
	else
		return (-1);
	return (2);
}

int		main(void)
{
	t_env	env;
	char	*line;
	int		place;

	place = 1;
	get_next_line(0, &line);
	env.player = get_player_number(&line);
	while (1)
	{
		if (env.player == 1 && place == 1 && (place = 0))
			get_map(env);
		else
		{
			while (line[0] != '<' && line[1] == 'g' \
					&& line[2] == 'o' && line[3] == 't' && line[6] != 'X')
			{
				get_next_line(0, &line);
			}
			if (get_map(env) == 1)
				return (0);
			place = 2;
		}
	}
	return (0);
}
