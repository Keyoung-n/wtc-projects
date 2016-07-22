/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smahomed <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/15 08:43:02 by smahomed          #+#    #+#             */
/*   Updated: 2016/05/15 08:43:47 by smahomed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*t;
	size_t	y;

	y = 0;
	t = (char *)ft_memalloc(sizeof(char) * (len - ((size_t)start)));
	while ((*(s + (++start) - 1) || *(s + start - 1))\
			&& start - 1 <= (unsigned int)len)
		*(t + y++) = *(s + start - 1);
	return (t);
}
