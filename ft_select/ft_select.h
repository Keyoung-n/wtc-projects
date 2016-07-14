/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_select.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knage <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/11 17:36:49 by knage             #+#    #+#             */
/*   Updated: 2016/07/14 16:45:22 by knage            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SELECT_H
#define FT_SELECT_H

#include "libft/libft.h"
#include <termcap.h>
#include <termios.h>

typedef struct	s_list
{
	char			*choice;
	int				select;
	int				hover;
}				t_list;

typedef struct	s_env
{
	struct termios termios;
}				t_env;
#endif
