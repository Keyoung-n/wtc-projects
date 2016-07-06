/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knage <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/04 15:03:00 by knage             #+#    #+#             */
/*   Updated: 2016/07/06 16:12:34 by knage            ###   ########.fr       */
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
	int				type;
	char			*name;
	int				bar_code;
	char			*links;
	struct s_room	*next;
}				t_data;

typedef struct	s_room
{
	int		type;
}				t_room;

void			get_ant_numbers(t_env *env);
void			get_link(char *str, t_data *room);
void			get_room(char *str, t_data *room);
int				check_special(char *line, int type);
int				what_type(char *line);
#endif
