/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smahomed <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/15 10:45:30 by smahomed          #+#    #+#             */
/*   Updated: 2016/07/10 12:44:54 by smahomed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			x;
	unsigned char	*t;

	x = 0;
	t = (unsigned char *)s;
	while (x < n && (unsigned char)t[x] != c)
		x += 1;
	if (t[x] == c)
		return (&t[x]);
	return (0);
}
