/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knage <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/12 16:55:05 by knage             #+#    #+#             */
/*   Updated: 2016/06/12 16:55:20 by knage            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *big, const char *little)
{
	int	count_i;
	int	count_j;
	int	count_c;

	count_i = 0;
	if (little[0] == '\0')
		return ((char*)(big));
	while (big[count_i] != '\0')
	{
		count_j = count_i;
		count_c = 0;
		while (big[count_j] == little[count_c])
		{
			count_j += 1;
			count_c += 1;
			if (little[count_c] == '\0')
				return ((char*)(&big[count_i]));
		}
		count_i += 1;
	}
	return (NULL);
}
