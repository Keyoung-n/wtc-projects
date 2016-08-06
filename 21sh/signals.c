/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcowle <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/29 10:15:59 by kcowle            #+#    #+#             */
/*   Updated: 2016/08/04 13:20:50 by kcowle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "21sh.h"

t_main	ft_keep_main(t_main w, int i)
{
	static t_main m;

	if (i == 0)
	{
		m = w;
		return (m);
	}
	else
		return (m);
}

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
	t_env	env;
	t_main	w;

	env = ft_keep_struct(env, 1);
	w = ft_keep_main(w, 1);
	if (env.father != 0)
	{
		w.line = NULL;
		w.start = -2;
		w.clip = NULL;
		w.buffsize = 0;
		w.a = 0;
		w.y = -1;
		ft_selectinit(&w);
		ft_init(&w, 0);
		kill(env.father, SIGINT);
		ft_doublecoms(&env, &w, 2);
	}
    ft_exit(&env, &w);
}

void	sinno(int signall)
{
	if (signall == SIGINT)
		ft_quit();
}
