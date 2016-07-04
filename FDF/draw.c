/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knage <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/30 16:26:47 by knage             #+#    #+#             */
/*   Updated: 2016/06/05 11:37:38 by knage            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	draw_line(t_vect p1, t_vect p2, t_env env)
{
	double	m;
	double	c;
	float	x;
	int		end;
	int		y_end;

	x = p1.x;
	end = p2.x;
	y_end = p2.y;
	if (p2.x == p1.x)
		m = 0;
	else
		m = (p2.y - p1.y) / (double)(p2.x - p1.x);
	c = p1.y - m * p1.x;
	if (p2.x < p1.x && (x = p2.x))
		end = p1.x;
	while (x <= end && m != 0 && (x = x + 0.1))
		mlx_pixel_put(env.mlx, env.win, x + 600, m * (x - 0.1) + c - 50, W);
	while (p1.y <= y_end && m == 0 && (p1.y = p1.y + 0.1))
		mlx_pixel_put(env.mlx, env.win, x + 600, p1.y - 0.1 - 50, W);
}

t_map	*ft_p2place(t_map *curr, t_env env)
{
	int		i;
	t_map	*temp;

	i = 0;
	temp = curr;
	while (i < env.x && temp != NULL)
	{
		temp = temp->next;
		i++;
	}
	return (temp);
}

void	draw_rows(t_map *curr, t_env env)
{
	t_map		*temp;
	t_map		*temp2;
	t_vect		point1;
	t_vect		point2;
	long int	i;

	i = 1;
	temp = curr;
	temp2 = curr;
	temp2 = temp2->next;
	while (temp2)
	{
		point1.x = (temp->x) + (800 - (8 * 20)) / 20;
		point1.y = (temp->y) + (800 / 2);
		point2.x = (temp2->x) + (800 - (8 * 20)) / 20;
		point2.y = (temp2->y) + (800 / 2);
		if (i < env.x)
			draw_line(point1, point2, env);
		else
			i = 0;
		temp = temp->next;
		i++;
		temp2 = temp2->next;
	}
}

void	draw_columns(t_map *curr, t_env env)
{
	t_map	*temp;
	t_map	*temp2;
	t_vect	point1;
	t_vect	point2;

	temp = curr;
	temp2 = ft_p2place(curr, env);
	while (temp2 != NULL)
	{
		point1.x = (temp->x) + (800 - (8 * 20)) / 20;
		point1.y = (temp->y) + (800 / 2);
		point2.x = (temp2->x) + (800 - (8 * 20)) / 20;
		point2.y = (temp2->y) + (800 / 2);
		draw_line(point1, point2, env);
		temp = temp->next;
		temp2 = temp2->next;
	}
}

void	draw(t_map *curr, t_env env)
{
	draw_columns(curr, env);
	draw_rows(curr, env);
}
