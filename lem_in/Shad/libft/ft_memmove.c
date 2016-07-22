/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smahomed <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/15 10:33:47 by smahomed          #+#    #+#             */
/*   Updated: 2016/05/15 10:36:38 by smahomed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	int		x;
	char	*s[2];

	s[0] = (char *)dst;
	s[1] = (char *)src;
	x = -1;
	while (++x < (int)len && s[1][x])
		s[0][x] = s[1][x];
	return (s[0]);
}
