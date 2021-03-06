/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcowle <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/07 15:59:48 by kcowle            #+#    #+#             */
/*   Updated: 2016/08/07 15:59:58 by kcowle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "twentyonesh.h"

void	ft_free2d(char **array)
{
	int i;

	i = 0;
	if (array)
	{
		while (array[i] != NULL)
		{
			free(array[i]);
			i++;
		}
		free(array);
	}
}

void	ft_free(t_env *env)
{
	int i;

	i = 0;
	while (env->enviro[i] != NULL)
	{
		free(env->enviro[i]);
		i++;
	}
	free(env->enviro[i]);
	i = 0;
	while (env->envirobk[i] != NULL)
	{
		free(env->envirobk[i]);
		i++;
	}
	free(env->envirobk[i]);
}
