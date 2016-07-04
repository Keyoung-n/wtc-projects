/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knage <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/02 14:44:06 by knage             #+#    #+#             */
/*   Updated: 2016/07/02 14:44:09 by knage            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	commands3(t_stack *a, t_stack *b, t_env *env, int nbr)
{
	if (nbr == 8)
	{
		ft_putstr("rrr\n");
		rr(a);
		rr(b);
	}
	if (nbr == 9)
	{
		ft_putstr("rra\n");
		rr(a);
	}
	else if (nbr == 10)
	{
		ft_putstr("rrb\n");
		rr(b);
	}
	env->nbr_count += 0;
}

void	commands2(t_stack *a, t_stack *b, t_env *env, int nbr)
{
	if (nbr == 4)
	{
		ft_putstr("pb\n");
		p(b, a);
	}
	else if (nbr == 5)
	{
		ft_putstr("ra\n");
		r(a, b);
	}
	else if (nbr == 6)
	{
		ft_putstr("rb\n");
		r(b, a);
	}
	else if (nbr == 7)
	{
		ft_putstr("rr\n");
		r(a, b);
		r(b, a);
	}
	else
		commands3(a, b, env, nbr);
}

void	commands(t_stack *a, t_stack *b, t_env *env, int nbr)
{
	if (nbr == 0)
	{
		ft_putstr("sa\n");
		s(a, b, env);
	}
	else if (nbr == 1)
	{
		ft_putstr("sb\n");
		s(b, a, env);
	}
	else if (nbr == 2)
	{
		ft_putstr("ss\n");
		s(a, b, env);
		s(b, a, env);
	}
	else if (nbr == 3)
	{
		ft_putstr("pa\n");
		p(a, b);
	}
	else
		commands2(a, b, env, nbr);
}
