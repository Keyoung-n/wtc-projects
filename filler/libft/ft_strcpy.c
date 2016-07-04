/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knage <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/12 16:55:05 by knage             #+#    #+#             */
/*   Updated: 2016/06/12 16:55:20 by knage            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcpy(char *dst, const char *src)
{
	int	count;

	count = 0;
	while (src[count] != '\0')
	{
		*(dst + count) = src[count];
		count += 1;
	}
	*(dst + count) = '\0';
	return (dst);
}
