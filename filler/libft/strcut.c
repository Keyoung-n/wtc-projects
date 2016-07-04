/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strcut.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knage <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/12 16:55:05 by knage             #+#    #+#             */
/*   Updated: 2016/06/12 16:55:29 by knage            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*strcut(char *str, int n)
{
	char	*str2;
	int		i;
	int		total;

	total = ft_strlen(str) - n;
	str2 = malloc(sizeof(char *) * n);
	i = 0;
	while (i < total && str[i] != '\0')
	{
		str2[i] = str[i];
		++i;
	}
	return (str2);
}
