/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcowle <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/07 15:59:48 by kcowle            #+#    #+#             */
/*   Updated: 2016/08/07 15:59:58 by kcowle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "twentyonesh.h"

void	ft_printoct(char *line, int *i)
{
	int		x;
	int		n;
	int		j;
	char	*str;

	x = 0;
	j = *i;
	str = (char *)malloc(sizeof(char *) * 5);
	while (x < 4)
	{
		str[x] = line[j];
		x++;
		j++;
	}
	n = ft_atoi(str);
	ft_putchar(oct_dec(n));
	*i += 8;
}

int		oct_dec(int n)
{
	int	i;
	int	dec;
	int	rem;

	i = 0;
	dec = 0;
	while (n != 0)
	{
		rem = n % 10;
		n /= 10;
		dec += rem * ft_pow(8, i);
		++i;
	}
	return (dec);
}
