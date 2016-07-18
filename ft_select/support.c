/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   support.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knage <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/16 15:03:04 by knage             #+#    #+#             */
/*   Updated: 2016/07/16 15:20:18 by knage            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void	window_small(t_env *env)
{
	struct winsize	w;

	get_size(env);
	ioctl(0, TIOCGWINSZ, &w);
	tputs(tgetstr("te", NULL), 1, ft_putchar_i);
	tputs(tgetstr("ti", NULL), 1, ft_putchar_i);
	tputs(tgetstr("ho", NULL), 1, ft_putchar_i);
	ft_putstr_fd("Window too small\n", 2);
	while (env->col_max > w.ws_col || env->row_max > w.ws_row)
		ioctl(0, TIOCGWINSZ, &w);
	tputs(tgetstr("te", NULL), 1, ft_putchar_i);
	tputs(tgetstr("ti", NULL), 1, ft_putchar_i);
	tputs(tgetstr("ho", NULL), 1, ft_putchar_i);
	env->error = 1;
}

int		ft_putchar_i(int c)
{
	return (write(2, &c, 1));
}

t_env	*get_env(void)
{
	static t_env	env;

	return (&env);
}
