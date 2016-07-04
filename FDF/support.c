/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   support.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knage <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/30 12:15:27 by knage             #+#    #+#             */
/*   Updated: 2016/06/05 10:41:58 by knage            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	sizematters(t_env *env, int length)
{
	if (length < 25)
		env->size = 20;
	else if (length < 50)
		env->size = 15;
	else if (length < 100)
		env->size = 10;
	else if (length >= 100 && length <= 300)
		env->size = 5;
	else if (length > 300)
		env->size = 2;
}

void	support(t_env *env, char **line)
{
	int	length;

	length = 0;
	while (line[length] != '\0')
		length++;
	if (length == env->x || length)
	{
		sizematters(env, length);
		env->x = 0;
	}
	else
		env->size = -1;
}
