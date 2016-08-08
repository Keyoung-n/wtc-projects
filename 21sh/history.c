/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   history.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcowle <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/07 15:59:48 by kcowle            #+#    #+#             */
/*   Updated: 2016/08/07 15:59:58 by kcowle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "twentyonesh.h"

char	**ft_insert(t_env *env, char *com)
{
	int		i;
	int		k;
	char	**array;

	i = 0;
	k = 0;
	array = (char **)malloc(sizeof(char **) + 1);
	array[0] = ft_strnew(1);
	if (env->history[0] != NULL)
	{
		while (env->history[i] != NULL)
			i++;
		array = (char **)malloc(sizeof(char **) * i + 1);
		while (env->history[k] != NULL)
		{
			array[k] = (char *)malloc(sizeof(char *)
					* ft_strlen(env->history[k]));
			ft_strcpy(array[k], env->history[k]);
			k++;
		}
		array[k] = (char *)malloc(sizeof(char *) * ft_strlen(com));
		ft_strcpy(array[k], com);
	}
	return (array);
}
