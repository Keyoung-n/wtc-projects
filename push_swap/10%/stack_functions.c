/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knage <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/30 09:58:03 by knage             #+#    #+#             */
/*   Updated: 2016/07/02 14:31:17 by knage            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	s(t_stack *a, t_stack *b, t_env *env)
{
	int	temp;

	p(b, a);
	temp = a->stack[*a->top - 1];
	*a->top = pop(*a->top);
	p(a, b);
	*a->top = push(a->stack, temp, *a->top, env->nbr_count);
	temp = 0;
	env->nbr_count += 0;
}

void	r(t_stack *a, t_stack *b)
{
	int	temp;
	int	size;
	int	i;

	temp = a->stack[*a->top - 1];
	i = *a->top - 2;
	size = *a->top;
	*a->top -= 1;
	while (i != -1)
	{
		p(b, a);
		--i;
	}
	*a->top += 1;
	a->stack[0] = temp;
	i = 1;
	while (i != size)
	{
		p(a, b);
		pop(*b->top);
		++i;
	}
}

void	rr(t_stack *a)
{
	int	temp;
	int	i;

	temp = a->stack[0];
	i = 0;
	while (i != *a->top - 1)
	{
		a->stack[i] = a->stack[i + 1];
		i++;
	}
	a->stack[i] = temp;
}

void	p(t_stack *to, t_stack *from)
{
	to->stack[*to->top] = from->stack[*from->top - 1];
	*to->top += 1;
	*from->top -= 1;
}
