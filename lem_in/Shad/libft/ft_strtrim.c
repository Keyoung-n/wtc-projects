/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smahomed <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/15 08:14:24 by smahomed          #+#    #+#             */
/*   Updated: 2016/05/15 13:34:50 by smahomed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	int		w;
	int		x;
	int		y;
	char	*t;

	x = 0;
	w = -1;
	y = 0;
	y = ft_strlen(s);
	t = (char *)ft_memalloc(ft_strlen(s));
	while (s[x] && (s[x] == ' ' || s[x] == '\t' || s[x] == '\n'))
		x++;
	while (s[y - 1] == ' ' || s[y - 1] == '\t' || s[y - 1] == '\n')
		t[y--] = '\0';
	while (s[++x - 1] && x - 1 <= y)
		t[++w] = s[x - 1];
	return (t);
}
