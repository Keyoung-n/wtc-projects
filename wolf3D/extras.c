/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extras.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knage <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/24 12:34:19 by knage             #+#    #+#             */
/*   Updated: 2016/06/24 12:34:34 by knage            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "wolf.h"
#include <stdlib.h>

int		redx(t_env *env)
{
	mlx_destroy_image(env->mlx, env->img);
	exit(0);
}

t_env	move_forward(t_env *env)
{
	mlx_clear_window(env->mlx, env->win);
	mlx_destroy_image(env->mlx, env->img);
	env->img = mlx_new_image(env->mlx, 800, 800);
	env->data = \
	mlx_get_data_addr(env->img, &env->bpp, &env->sizeline, &env->endian);
	if (env->worldmap[(int)(env->posx +\
				env->dirx * 0.1)][(int)(env->posy)] == '0')
		env->posx += env->dirx * 0.1;
	if (env->worldmap[(int)(env->posx)][(int)(env->posy +\
				env->diry * 0.1)] == '0')
		env->posy += env->diry * 0.1;
	return (*env);
}

t_env	move_backwards(t_env *env)
{
	mlx_clear_window(env->mlx, env->win);
	mlx_destroy_image(env->mlx, env->img);
	env->img = mlx_new_image(env->mlx, 800, 800);
	env->data = \
	mlx_get_data_addr(env->img, &env->bpp, &env->sizeline, &env->endian);
	if (env->worldmap[(int)(env->posx -\
				env->dirx * 0.1)][(int)(env->posy)] == '0')
		env->posx -= env->dirx * 0.1;
	if (env->worldmap[(int)(env->posx)][(int)(env->posy -\
				env->diry * 0.1)] == '0')
		env->posy -= env->diry * 0.1;
	return (*env);
}

t_env	look_left(t_env *env)
{
	double olddirx;
	double oldplanex;

	mlx_clear_window(env->mlx, env->win);
	mlx_destroy_image(env->mlx, env->img);
	env->img = mlx_new_image(env->mlx, 800, 800);
	env->data = \
	mlx_get_data_addr(env->img, &env->bpp, &env->sizeline, &env->endian);
	olddirx = env->dirx;
	env->dirx = env->dirx * cos(-0.1) - env->diry * sin(-0.1);
	env->diry = olddirx * sin(-0.1) + env->diry * cos(-0.1);
	oldplanex = env->planex;
	env->planex = env->planex * cos(-0.1) - env->planey * sin(-0.1);
	env->planey = oldplanex * sin(-0.1) + env->planey * cos(-0.1);
	return (*env);
}

t_env	look_right(t_env *env)
{
	double olddirx;
	double oldplanex;

	mlx_clear_window(env->mlx, env->win);
	mlx_destroy_image(env->mlx, env->img);
	env->img = mlx_new_image(env->mlx, 800, 800);
	env->data = \
	mlx_get_data_addr(env->img, &env->bpp, &env->sizeline, &env->endian);
	olddirx = env->dirx;
	env->dirx = env->dirx * cos(0.1) - env->diry * sin(0.1);
	env->diry = olddirx * sin(0.1) + env->diry * cos(0.1);
	oldplanex = env->planex;
	env->planex = env->planex * cos(0.1) - env->planey * sin(0.1);
	env->planey = oldplanex * sin(0.1) + env->planey * cos(0.1);
	return (*env);
}
