/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knage <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/15 10:46:37 by knage             #+#    #+#             */
/*   Updated: 2016/05/15 14:26:14 by knage            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strnstr(const char *big, const char *little, size_t len)
{
	int	cmp;
	int	cmp2;

	cmp = 0;
	cmp2 = 0;
	if (!little[0])
		return ((char *)(big));
	while (big[cmp] && cmp < (int)len)
	{
		if (big[cmp] == little[cmp2])
			cmp2++;
		else
		{
			cmp -= cmp2;
			cmp2 = 0;
		}
		if (!little[cmp2])
			return ((char *)(big + cmp - cmp2 + 1));
		cmp++;
	}
	return (NULL);
}
