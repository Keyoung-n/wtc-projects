/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knage <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/12 16:54:35 by knage             #+#    #+#             */
/*   Updated: 2016/06/12 16:54:37 by knage            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H
# define S env.piece.piece[p.i][p.j] == '*' && (p.l == 1 && map[y][x] != '.')

typedef struct	s_map
{
	int	map_y;
	int	map_x;
	int	area;
}				t_map;

typedef struct	s_piece
{
	char	**piece;
	int		piece_y;
	int		piece_x;
	int		piece_a;
}				t_piece;

typedef struct	s_raw_map
{
	char				point;
	struct s_raw_map	*next;
}				t_raw_map;

typedef struct	s_env
{
	t_map	map;
	t_piece	piece;
	char	n;
	char	p;
	int		player;
}				t_env;

typedef struct	s_points
{
	int	k;
	int	i;
	int	j;
	int	l;
}				t_points;

int				play(t_env *env, char *line, char **line2, t_raw_map **b);
int				get_player_number(char **line);
void			getmap(t_env *env, t_raw_map **map, char **line);
void			getpiece(t_env *env, char **line, char **line2);
void			getmapsize(t_env *env, char *line, char **line2);
int				get_map(t_env env);
void			insert_line(char *line, t_raw_map **b);
void			insert_piece(char *line, t_env *env);
int				algo(t_env *env, t_raw_map **b);
void			freeall(t_env *env, char **map);
char			**create_two_d(int y);
void			link_to_twoda(char **map, int x, int y, t_raw_map *m);
#endif
