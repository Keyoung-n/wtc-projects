/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smahomed <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/13 09:25:11 by smahomed          #+#    #+#             */
/*   Updated: 2016/05/15 11:15:46 by smahomed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t		x;
	char		*v[2];

	x = -1;
	v[0] = (char *)dst;
	v[1] = (char *)src;
	while (v[1][++x] && v[1][x - 1] != c && x < n)
		v[0][x] = v[1][x];
	if (v[1][x - 1] == c)
		return (&v[0][x]);
	return (0);
}
