/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knage <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/04 15:03:00 by knage             #+#    #+#             */
/*   Updated: 2016/07/19 13:07:18 by knage            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H

#include "libft/libft.h"

typedef struct	s_env
{
	long	ant_count;
	int		special[2];
	int		start;
	int		end;
	int		room_count;
	int		type;
	int		size;	
}				t_env;

typedef struct	s_links
{
	int				code;
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

typedef struct	s_room
{
	int		ant;
	int		score;
	char	*name;
	t_links	*links;	
}				t_room;

char			*build_str(char *str, int *i, char limit);
void			get_ant_numbers(t_env *env);
void			add_link(t_data **curr);
void			get_link(char *str, t_data *room);
void			get_room(char *str, t_data **room, t_env *env);
t_room			*ant_hill(t_data *curr, int i);
int				is_valid_link(char *str, t_data *curr);
int				check_special(char *line, t_env *env);
int				is_valid_room(char *str, t_data *curr);
int				what_type(char *line);
#endif
