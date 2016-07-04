/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knage <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/15 09:41:26 by knage             #+#    #+#             */
/*   Updated: 2016/05/15 09:41:32 by knage            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t	i;
	char	*strs[2];

	i = -1;
	strs[0] = dst;
	strs[1] = (char*)src;
	while (++i < n && strs[1])
		strs[0][i] = strs[1][i];
	return (dst);
}
