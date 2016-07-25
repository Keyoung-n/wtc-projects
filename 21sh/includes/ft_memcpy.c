/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knage <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/10 13:41:50 by knage             #+#    #+#             */
/*   Updated: 2016/07/10 13:42:02 by knage            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *s1, const void *s2, size_t n)
{
	char		*tmp;
	const char	*tmp2;
	size_t		i;

	i = 0;
	tmp = (char*)s1;
	tmp2 = (char*)s2;
	while (i < n)
	{
		tmp[i] = tmp2[i];
		i++;
	}
	return (s1);
}
