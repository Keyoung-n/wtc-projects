/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   terminal.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knage <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/25 09:57:16 by knage             #+#    #+#             */
/*   Updated: 2016/07/28 12:34:48 by knage            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "21sh.h"

int		ft_putchar_i(int c)
{
    return (write(2, &c, 1));
}

void	change_term(t_env *env)
{
    tgetent(NULL, getenv("TERM"));
    tcgetattr(0, &env->termios);
    env->termios.c_lflag &= ~(ECHO | ICANON);
    env->termios.c_cc[VMIN] = 1;
	env->termios.c_cc[VTIME] = 0;
	tcsetattr(0, TCSANOW, &env->termios);
    tputs(tgetstr("ti", NULL), 1, ft_putchar_i);
    tputs(tgetstr("ho", NULL), 1, ft_putchar_i);
}

t_env	*get_env(void)
{
    static t_env	env;
    
    return (&env);
}

void	change_back(void)
{
    t_env	*env;
    
    env = get_env();
    env->termios.c_lflag &= ~(ECHO | ICANON);
	tcsetattr(0, TCSANOW, &env->termios);
    tputs(tgetstr("te", NULL), 1, ft_putchar_i);
}
