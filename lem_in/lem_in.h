/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knage <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/04 15:03:00 by knage             #+#    #+#             */
/*   Updated: 2016/07/23 14:27:27 by knage            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H
# include "libft/libft.h"

typedef struct	s_links
{
	int				bar_code;
	int				counter;
	struct s_links	*path;
	struct s_links	*next;
}				t_links;

typedef struct	s_data
{
	char			*name;
	int				x;
	int				y;
	int				type;
	int				bar_code;
	t_links			*links;
	struct s_data	*next;
}				t_data;

typedef struct	s_env
{
	long	ant_count;
	long	room_count;
	t_data	*maze;
	int		special[4];
	int		type;
	int		size;
	int		*room;
	int		nodes_count[2];
	int		helper;
	t_links	**fpaths;
	t_links	*start;
	t_links	*stack[2];
}				t_env;

char			*build_str(char *str, int *i, char limit);
void			get_ant_numbers(t_env *env);
void			add_link(t_data **curr);
void			ant_hill(t_data *curr, t_data *rooms, int total);
void			get_link(char *str, t_data *room);
void			ft_initrooms(t_env *env);
void			check_type(t_env *env, t_data *temp);
void			get_room(char *str, t_data **room, t_env *env);
int				is_valid_link(char *str, t_data *curr);
int				check_special(char *line, t_env *env);
int				is_valid_room(char *str, t_data *curr);
int				what_type(char *line);
int				final(t_env *e, t_links **tmp);
int				is_valid_map(t_env *env);
void			algo(t_env *env);
void			setnode(t_env *env, int node);
void			print_links(t_links *curr);
void			fill_room(t_env *env, t_links *temp, int node);
void			ant_wait(t_env *env);
int				is_end(t_env env);
#endif
