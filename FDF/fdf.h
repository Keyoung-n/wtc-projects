/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knage <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/24 17:26:11 by knage             #+#    #+#             */
/*   Updated: 2016/06/05 11:19:51 by knage            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# define W 0xFFFFFF

# include <math.h>
# include <stdlib.h>
# include "mlx.h"
# include "libft/libft.h"

typedef struct	s_map
{
	double			x;
	double			y;
	int				z;
	struct s_map	*next;
}				t_map;

typedef	struct	s_points
{
	float	x;
	float	y;
}				t_vect;

typedef	struct	s_environment
{
	void		*mlx;
	void		*win;
	void		*img;
	t_map		*map;
	long int	x;
	long int	y;
	long int	area;
	double		size;
}				t_env;

t_map			*reverse(t_map *head_ref);
void			draw(t_map *curr, t_env env);
void			support(t_env *env, char **line);
#endif
