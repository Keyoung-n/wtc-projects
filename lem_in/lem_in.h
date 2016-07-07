/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knage <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/04 15:03:00 by knage             #+#    #+#             */
/*   Updated: 2016/07/07 09:28:53 by knage            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H

#include "libft/libft.h"

typedef struct	s_env
{
	long	ant_count;
	int		size;
	
}				t_env;

typedef struct	s_data
{
	char			*name;
	int				x;
	int				y;
	int				bar_code;
	char			*links;
	struct s_data	*next;
}				t_data;

typedef struct	s_room
{
	int		type;
}				t_room;

char			*build_str(char *str, int i, char limit);
void			get_ant_numbers(t_env *env);
void			get_link(char *str, t_data *room);
void			get_room(char *str, t_data *room);
int				check_special(char *line, int type);
int				is_valid_room(char *str);
int				what_type(char *line);
#endif
