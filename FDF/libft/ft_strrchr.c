/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knage <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/15 09:18:49 by knage             #+#    #+#             */
/*   Updated: 2016/05/15 14:19:00 by knage            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*fct;

	fct = NULL;
	while (*s)
	{
		if (*s == (char)c)
			fct = (char *)s;
		s++;
	}
	if (*s == (char)c)
		fct = (char *)s;
	return (fct);
}
