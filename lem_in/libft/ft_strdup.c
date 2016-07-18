/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knage <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/24 12:41:53 by knage             #+#    #+#             */
/*   Updated: 2016/06/24 12:42:05 by knage            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strdup(const char *src)
{
	char	*new;

	new = malloc(ft_strlen(src) + 1);
	if (new == 0)
		return (0);
	ft_strcpy(new, src);
	return (new);
}
