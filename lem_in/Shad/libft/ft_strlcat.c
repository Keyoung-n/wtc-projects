/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smahomed <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/15 09:34:27 by smahomed          #+#    #+#             */
/*   Updated: 2016/05/15 09:35:38 by smahomed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	int		v[2];
	char	*s;

	*(v + 0) = -1;
	*(v + 1) = -1;
	s = (char *)ft_memalloc(size);
	while (*(dst + (++v[0])))
		*(s + v[0]) = *(dst + v[0]);
	while ((++v[0] <= (int)size) && *(src + (++v[1])))
		*(s + v[0] - 1) = *(src + v[1]);
	*(s + v[0]) = '\0';
	dst = s;
	return ((size_t)s);
}
