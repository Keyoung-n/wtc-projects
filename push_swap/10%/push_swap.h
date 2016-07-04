/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knage <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/23 13:17:10 by knage             #+#    #+#             */
/*   Updated: 2016/07/02 14:59:28 by knage            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "libft/libft.h"

typedef struct	s_group
{
	int	*numbers;
	int	group_size;
	int	is_sorted;
}				t_group;

typedef struct	s_stack
{
	int	*stack;
	int	*top;
}				t_stack;

typedef struct	s_env
{
	int	nbr_count;
	int	nbr_n_count;
	int	a_count;
	int	b_count;
	int	i_helper;
	int	*a;
	int	*b;
}				t_env;

void			commands(t_stack *a, t_stack *b, t_env *env, int nbr);
void			algo(t_env *env);
void			s(t_stack *a, t_stack *b, t_env *env);
void			p(t_stack *to, t_stack *form);
void			r(t_stack *a, t_stack *b);
void			rr(t_stack *a);
int				check(char **av, char *number, int k);
int				push(int *stack, int data, int s_count, int size);
int				pop(int count);
int				is_stacksorted(t_env *env);
int				error_tests(int ac, char **av);
void			load_numbers(int *input, char **av, int ac);
#endif
