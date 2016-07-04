/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knage <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/24 12:35:30 by knage             #+#    #+#             */
/*   Updated: 2016/06/24 12:35:40 by knage            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF_H
# define WOLF_H
# include "mlx.h"
# define W 800
# define H 800

typedef	struct		s_env{
	int				map_y;
	int				map_x;
	char			**worldmap;
	int				drawend;
	int				drawstart;
	int				color;
	int				bpp;
	int				x;
	int				endian;
	int				i;
	int				sizeline;
	int				pixel_nbr;
	void			*mlx;
	void			*win;
	int				*img;
	char			*data;
	double			posx;
	double			posy;
	double			dirx;
	double			diry;
	double			planex;
	double			planey;
	double			camerax;
	double			rayposx;
	double			rayposy;
	double			raydirx;
	double			raydiry;
	int				mapx;
	int				mapy;
	double			sidedistx;
	double			sidedisty;
	double			deltadistx;
	double			deltadisty;
	double			perpwalldist;
	int				stepx;
	int				stepy;
	int				hit;
	int				side;
	int				lineheight;
}					t_env;

int					redx(t_env *env);
t_env				get_distances(t_env *env);
t_env				cast_until_hit(t_env *env);
t_env				dda(t_env *env);
t_env				draw_skybox(t_env *env);
t_env				draw_floor(t_env *env);
t_env				we_wall(t_env *env);
t_env				ns_wall(t_env *env);
t_env				look_left(t_env *env);
t_env				look_right(t_env *env);
t_env				move_backwards(t_env *env);
t_env				move_forward(t_env *env);
t_env				insert_map(char *line, t_env *env);
void				get_map_size(t_env *env, char *argv);
void				redo(t_env *env);
int					get_key_event(int keycode, t_env *env);
void				wolf(t_env *env);
#endif
