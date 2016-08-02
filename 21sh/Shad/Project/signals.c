/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcowle <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/29 10:15:59 by kcowle            #+#    #+#             */
/*   Updated: 2016/08/02 08:28:33 by knage            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_env	ft_keep_struct(t_env env, int i)
{
	static t_env tmp;

	if (i == 0)
	{
		tmp = env;
		return (tmp);
	}
	else
	{
		return (tmp);
	}
}

void	ft_quit(void)
{
	t_env env;
	t_main w;

	env = ft_keep_struct(env, 1);
	if (env.father != 0)
	{
		kill(env.father, SIGTSTP);
		ft_putchar('\n');
		ft_doublecoms(&env, &w, 2);
	}
	exit(0);
}

void	sinno(int signall)
{
	if (signall == SIGTSTP)
		ft_quit();
}
