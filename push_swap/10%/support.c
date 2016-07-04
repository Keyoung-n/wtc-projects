/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   support.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knage <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/02 14:47:06 by knage             #+#    #+#             */
/*   Updated: 2016/07/02 14:47:11 by knage            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		check(char **av, char *number, int k)
{
	int			i;
	long int	l;

	i = 0;
	l = ft_atoil(number);
	if (l > 2147483647 || l < -2147483648)
		return (0);
	while (i != k)
	{
		if (ft_strcmp(av[i], number) == 0)
			return (0);
		i++;
	}
	return (1);
}

int		error_tests(int ac, char **av)
{
	int	x;
	int	y;

	y = 1;
	while (y != ac)
	{
		x = 0;
		if (av[y][x] == '-' || av[y][x] == '+')
			x++;
		while (av[y][x])
		{
			if (av[y][x] < '0' || av[y][x] > '9')
				return (0);
			x++;
		}
		if (check(av, av[y], y) == 0)
			return (0);
		y++;
	}
	return (1);
}

void	load_numbers(int *input, char **av, int ac)
{
	int	i;
	int	j;

	i = 1;
	j = ac - 2;
	while (i != ac)
	{
		input[j] = ft_atoi(av[i]);
		i++;
		j--;
	}
}
