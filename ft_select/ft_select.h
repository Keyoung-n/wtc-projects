/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_select.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knage <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/11 17:36:49 by knage             #+#    #+#             */
/*   Updated: 2016/07/11 17:37:34 by knage            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SELECT_H
#define FT_SELECT_H

#include "libft/libft.h"
#include <termcap.h>
#include <termios.h>

typedef struct	s_choice
{
	char		*choice;
	s_choice	*next;
}				t_choice;
#endif
