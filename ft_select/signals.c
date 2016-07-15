/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knage <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/15 12:41:46 by knage             #+#    #+#             */
/*   Updated: 2016/07/15 14:55:26 by knage            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	close(t_env *env)
{
	tgetent(NULL, getenv("TERM"));
	tcgetattr(0, &env->termios);
	env->termios.c_lflag &= ~(ECHO | ICANON);
	tcsetattr(0, TCSANOW, &env->termios);
	env->term.c_lflag |= (ICANON | ECHO);
	tputs(tgetstr("te", NULL), 1, ft_putchar_i);
	tputs(tgetstr("ve", NULL), 1, ft_putchar_i);
}

void	signals(t))
{
	signal(SIGTSTP, close);
}
