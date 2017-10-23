/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen2d.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcowle <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/12 10:25:08 by kcowle            #+#    #+#             */
/*   Updated: 2016/08/23 16:07:08 by kcowle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen2D(char **str)
{
	size_t i;

	i = 0;
	if (str != NULL)
	{
		while (str[i] != NULL)
		{
			i++;
		}
	}
	return (i);
}