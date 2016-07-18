/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knage <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/24 12:41:52 by knage             #+#    #+#             */
/*   Updated: 2016/06/24 12:42:05 by knage            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *dst, int c, size_t n)
{
	size_t			cmp;
	unsigned char	*ptrmem;

	cmp = 0;
	ptrmem = (unsigned char *)dst;
	while (cmp < n)
	{
		ptrmem[cmp] = (unsigned char)c;
		cmp++;
	}
	return (dst);
}
