/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knage <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/29 09:42:46 by knage             #+#    #+#             */
/*   Updated: 2016/07/29 09:42:47 by knage            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "21sh.h"

void	ft_suspend(void)
{
    t_env	env;
    char	copy[2];
    
    tcgetattr(0, &env.termios);
    copy[0] = env.termios.c_cc[VSUSP];
    copy[1] = 0;
    env.termios.c_lflag &= ~(ECHO | ICANON);
    signal(SIGTSTP, SIG_DFL);
    tcsetattr(0, 0, &env.termios);
    tputs(tgetstr("te", NULL), 1, ft_putchar_i);
    ioctl(0, TIOCSTI, copy);
}

void	ft_continue(void)
{
    t_env *env;
    
    env = get_env();
    change_term(env);
}

void	catch(int signal)
{
    if (signal == SIGTSTP)
        ft_suspend();
    else if (signal == SIGCONT)
        ft_continue();
    else if (signal == SIGINT)
    {
        change_back();
        exit(0);
    }
}

void	signals(void)
{
    signal(SIGINT, catch);
    signal(SIGTSTP, catch);
    signal(SIGCONT, catch);
}
