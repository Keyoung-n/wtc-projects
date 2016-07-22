/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smahomed <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/10 12:43:55 by smahomed          #+#    #+#             */
/*   Updated: 2016/07/10 12:44:05 by smahomed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_realloc(void *ptr, size_t size)
{
	void	*t;
	char	*u;
	char	*v;
	size_t	x;

	x = -1;
	t = (void *)malloc(sizeof(void) * size);
	u = (char *)t;
	v = (char *)ptr;
	while (++x < size)
		u[x] = v[x];
	if (v)
		free(ptr);
	ptr = t;
	return ((void *)t);
}
