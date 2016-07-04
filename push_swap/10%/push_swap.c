/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knage <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/23 13:14:27 by knage             #+#    #+#             */
/*   Updated: 2016/07/02 14:28:43 by knage            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	bsort(int *arr, int int_size)
{
	int		i;
	int		j;
	int		t;

	j = 0;
	i = 0;
	while (++i < int_size || (++j < int_size - 1 && (i = j + 1) >= 0))
		if (arr[i] < arr[j] && (t = arr[j]) >= 0)
		{
			arr[j] = arr[i];
			arr[i] = t;
		}
}

void	find_indexs(int *input, t_env *env, char **av)
{
	int	*sorted;
	int	i;

	env->i_helper = env->nbr_count - 1;
	sorted = (int*)malloc(sizeof(int*) * env->nbr_count);
	load_numbers(sorted, av, env->nbr_count + 1);
	bsort(sorted, env->nbr_count);
	while (env->i_helper != -1)
	{
		i = env->nbr_count - 1;
		while (i != -1)
		{
			if (input[env->i_helper] == sorted[i])
				break ;
			i--;
		}
		env->a[env->i_helper] = i + 1;
		env->i_helper--;
	}
	free(sorted);
}

int		is_stacksorted(t_env *env)
{
	int	i;

	i = env->nbr_count - 1;
	while (i != 0)
	{
		if (env->a[i] > env->a[i - 1])
			return (0);
		--i;
	}
	return (1);
}

void	sort(int *input, t_env *env, char **av)
{
	find_indexs(input, env, av);
	env->a_count = env->nbr_count;
	env->b_count = 0;
	while (is_stacksorted(env) == 0 && env->b_count == 0)
		algo(env);
}

int		main(int ac, char **av)
{
	int		input[ac];
	int		a[ac];
	int		b[ac];
	t_env	env;

	env.a = a;
	env.b = b;
	if (ac > 2 && error_tests(ac, av) == 1)
	{
		env.nbr_count = ac - 1;
		load_numbers(input, av, ac);
		sort(input, &env, av);
	}
	else
		ft_putchar('\n');
	return (0);
}
