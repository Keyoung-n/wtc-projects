/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str2d.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcowle <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/12 10:22:56 by kcowle            #+#    #+#             */
/*   Updated: 2016/08/12 10:23:01 by kcowle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen2D(char **str)
{
	size_t i;

	i = 0;
	if (str[0] != NULL)
	{
		while (str[i] != NULL)
		{
			i++;
		}
	}
	return (i);
}
