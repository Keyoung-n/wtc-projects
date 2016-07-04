/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knage <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/30 15:05:27 by knage             #+#    #+#             */
/*   Updated: 2016/07/02 14:43:48 by knage            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		push(int *stack, int data, int s_count, int size)
{
	if (s_count == size)
		return (s_count);
	s_count += 1;
	stack[s_count - 1] = data;
	return (s_count);
}

int		pop(int count)
{
	if (count == 0)
		return (count);
	return (--count);
}

void	set1(t_stack *a, t_stack *b, t_env *env)
{
	if (a->stack[*a->top - 1] > a->stack[*a->top - 2])
		commands(a, b, env, 0);
	else if (a->stack[*a->top - 1] > a->stack[0])
		commands(a, b, env, 5);
	else if (a->stack[0] == a->stack[*a->top - 2] - 1)
	{
		commands(a, b, env, 9);
		commands(a, b, env, 0);
	}
	else if (a->stack[*a->top - 1] - 1 == a->stack[0])
		commands(a, b, env, 9);
	else if (is_stacksorted(env) == 1 && b->top != 0)
		commands(a, b, env, 3);
	else if (is_stacksorted(env) == 0)
		commands(a, b, env, 4);
}

void	algo(t_env *env)
{
	t_stack a;
	t_stack b;

	a.stack = env->a;
	a.top = &env->a_count;
	b.stack = env->b;
	b.top = &env->b_count;
	set1(&a, &b, env);
}
