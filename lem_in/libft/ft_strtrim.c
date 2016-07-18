/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knage <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/24 12:41:54 by knage             #+#    #+#             */
/*   Updated: 2016/06/24 12:42:06 by knage            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

char	*ft_strtrim(char const *s)
{
	size_t	start;
	size_t	end;
	char	*new;

	start = 0;
	end = ft_strlen(s);
	while (ft_iswhitespace(s[start]))
		start++;
	while (ft_iswhitespace(s[end - 1]))
		end--;
	if (end < start)
		end = start;
	new = ft_strnew(end - start);
	if (new == NULL)
		return (NULL);
	return (ft_strncpy(new, s + start, end - start));
}
