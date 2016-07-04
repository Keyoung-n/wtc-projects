/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knage <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/12 16:52:27 by knage             #+#    #+#             */
/*   Updated: 2016/06/12 16:52:57 by knage            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "filler.h"

void	find_terr(t_env *env)
{
	if (env->player == 1)
	{
		env->p = 'O';
		env->n = 'X';
	}
	else
	{
		env->p = 'X';
		env->n = 'O';
	}
}

int		checkarea(t_env env, int x, int y, char **map)
{
	t_points p;

	p.k = x;
	p.i = 0;
	p.l = 0;
	while (p.i != env.piece.piece_y)
	{
		p.j = 0;
		x = p.k;
		while (p.j != env.piece.piece_x)
		{
			if (map[y][x] == env.n || map[y][x] == ft_tolower(env.n))
				return (0);
			if (S)
				return (0);
			if (env.piece.piece[p.i][p.j] == '*' && \
					(map[y][x] == env.p || map[y][x] == ft_tolower(env.p)))
				p.l++;
			x++;
			p.j++;
		}
		p.i++;
		y++;
	}
	return (p.l);
}

int		check(t_raw_map *m, t_env *env, int y, int x)
{
	int		l;
	char	**map;

	l = 0;
	map = create_two_d(env->map.map_y);
	link_to_twoda(map, env->map.map_x, env->map.map_y, m);
	find_terr(env);
	if (y + env->piece.piece_y <= env->map.map_y)
	{
		if (x + env->piece.piece_x <= env->map.map_x)
		{
			l = checkarea(*env, x, y, map);
			if (l == 1)
				return (1);
		}
	}
	freeall(env, map);
	if (l != 1)
		return (0);
	return (0);
}

void	place_coords(int x, int y)
{
	ft_putnbr(y);
	ft_putchar(' ');
	ft_putnbr(x);
	ft_putchar('\n');
}

int		algo(t_env *env, t_raw_map **b)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (y < env->map.map_y)
	{
		while (x < env->map.map_x)
		{
			if (check(b[1], env, y, x) == 1)
			{
				place_coords(x, y);
				return (0);
			}
			x++;
		}
		x = 0;
		y++;
	}
	place_coords(0, 0);
	return (1);
}
