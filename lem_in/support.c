/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   support.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knage <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/07 08:14:58 by knage             #+#    #+#             */
/*   Updated: 2016/07/07 16:50:19 by knage            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

char	*build_str(char *str, int i, char limit)
{
	char	*ret;
	int		size;

	size = 0;
	while (str[size] != limit && str[size] != '\0')
		size++;
	ret = (char*)malloc(sizeof(char*) * size + 1);
	while (str[i] != limit && str[i] != '\0')
	{
		ret[i] = str[i];
		i++;
	}
	ret[i] = '\0';
	return (ret);
}
