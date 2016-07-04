/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knage <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/04 15:03:00 by knage             #+#    #+#             */
/*   Updated: 2016/07/04 16:37:35 by knage            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H

#include "libft/libft.h"

typedef struct	s_env
{
	long	ant_count;
	
}				t_env;

void			get_ant_numbers(int fd, t_env *env);
#endif
