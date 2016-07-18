/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_select.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knage <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/11 17:36:49 by knage             #+#    #+#             */
/*   Updated: 2016/07/16 15:16:28 by knage            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SELECT_H
# define FT_SELECT_H
# include "libft/libft.h"
# include <termcap.h>
# include <termios.h>
# include <sys/ioctl.h>

typedef struct	s_list
{
	char			*choice;
	int				visible;
	int				select;
	int				hover;
}				t_list;

typedef struct	s_env
{
	struct termios	termios;
	t_list			*choices;
	int				finish;
	int				error;
	int				col_max;
	int				row_max;
	int				remove;
	int				max;
	int				place;
	int				active;
}				t_env;

void			move(t_list *list, t_env *env, int move);
void			select_item(t_list *list, t_env *env);
void			remove_item(t_list *list, t_env *env);
void			print_list(t_list *list);
void			window_small(t_env *env);
void			change_term(t_env *env);
void			finish(t_list *list);
void			get_size(t_env *env);
void			change_back();
void			signals();
int				ft_putchar_i(int c);
int				ft_resize();
t_env			*get_env();
#endif
