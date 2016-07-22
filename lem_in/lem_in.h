/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knage <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/04 15:03:00 by knage             #+#    #+#             */
/*   Updated: 2016/07/21 15:39:27 by knage            ###   ########.fr       */
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
    long    ant_count;
    long    room_count;
    t_data  *a;
    int     special[4];
    int     type;
    int     size;
    int     *o;
    int      nodes_count[2];
    int      x;
    t_links  **fpaths;
    t_links  *start;
    t_links  *n[2];
}				t_env;

char			*build_str(char *str, int *i, char limit);
void			get_ant_numbers(t_env *env);
void			add_link(t_data **curr);
void			ant_hill(t_data *curr, t_data *rooms);
void			get_link(char *str, t_data *room);
void			get_room(char *str, t_data **room, t_env *env);
int				is_valid_link(char *str, t_data *curr);
int				check_special(char *line, t_env *env);
int				is_valid_room(char *str, t_data *curr);
int				what_type(char *line);
int				is_valid_map(t_env *env);
int             ft_init(t_env *e, int node);
int             ft_init4(t_env *e);
int             init2(t_env *e);
int             ft_leminalg(t_env *e);
int             ft_init3(t_env *e, t_links *t, int node);
t_links         *ft_init1(t_links *a, int node);
#endif
