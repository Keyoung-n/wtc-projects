/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knage <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/24 12:41:54 by knage             #+#    #+#             */
/*   Updated: 2016/06/24 12:42:06 by knage            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *s1, const char *s2)
{
	size_t		inner;

	if (s2[0] == '\0')
		return ((char*)s1);
	while (*s1)
	{
		inner = 0;
		while (s1[inner] == s2[inner])
		{
			if (s2[inner + 1] == '\0')
				return ((char*)s1);
			inner++;
		}
		s1++;
	}
	return (0);
}
