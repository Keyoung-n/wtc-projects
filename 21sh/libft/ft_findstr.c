/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_findstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcowle <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/04 11:44:17 by kcowle            #+#    #+#             */
/*   Updated: 2016/08/04 14:36:29 by kcowle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_findstr(char *find, char *str)
{
	int		in_word;
	int		i;
	int		j;
	int		find_len;

	i = 0;
	j = 0;
	find_len = ft_strlen(find);
	in_word = 0;
	while (str[i])
	{
		if (str[i] == find[j] && (j + 1 == find_len))
			return (1);
		else if (str[i] != find[j])
			j = 0;
		else
			j++;
		i++;
	}
	return (0);
}
