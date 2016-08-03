/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   terminal.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knage <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/16 09:32:18 by knage             #+#    #+#             */
/*   Updated: 2016/07/16 15:21:29 by knage            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void	change_term(t_env *env)
{
	tgetent(NULL, getenv("TERM"));
	tcgetattr(0, &env->termios);
	env->termios.c_lflag &= ~(ECHO | ICANON);
	env->termios.c_cc[VMIN] = 0;
	tcsetattr(0, TCSANOW, &env->termios);
	tputs(tgetstr("ti", NULL), 1, ft_putchar_i);
	tputs(tgetstr("ho", NULL), 1, ft_putchar_i);
	tputs(tgetstr("vi", NULL), 1, ft_putchar_i);
}

void	change_back(void)
{
	t_env	*env;

	env = get_env();
	env->termios.c_lflag &= ~(ECHO | ICANON);
	tcsetattr(0, 0, &env->termios);
	tputs(tgetstr("te", NULL), 1, ft_putchar_i);
	tputs(tgetstr("ve", NULL), 1, ft_putchar_i);
}

void	finish(t_list *list)
{
	int	i;

	i = 0;
	ft_putstr_fd("\033[39m", 2);
	while (list[i].choice)
	{
		if (list[i].select == 1)
			ft_printf("%s ", list[i].choice);
		i++;
	}
}

void	get_size(t_env *env)
{
	int	i;
	int	k;

	i = 0;
	k = 0;
	while (env->choices[i].choice)
	{
		if (env->choices[i].visible == 0)
		{
			if (ft_strlen(env->choices[i].choice) > env->col_max)
				env->col_max = ft_strlen(env->choices[i].choice);
			k++;
		}
		i++;
	}
	env->row_max = k;
}
