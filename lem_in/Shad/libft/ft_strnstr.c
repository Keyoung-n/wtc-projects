/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smahomed <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/11 15:44:37 by smahomed          #+#    #+#             */
/*   Updated: 2016/05/15 09:40:41 by smahomed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	int		x;
	int		v[3];

	v[0] = (int)ft_strlen(little);
	v[1] = -1;
	if (v[0] <= (int)ft_strlen(big))
		while (big[++v[1]] && (x = -1))
		{
			while (little[++x] && big[v[1] + x] && little[x] == big[v[1] + x])
				;
			if (x == v[0] && x <= (int)len)
				return ((char *)&big[v[1]]);
		}
	return ((char *)&big[0]);
}
