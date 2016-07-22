/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smahomed <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/15 09:31:42 by smahomed          #+#    #+#             */
/*   Updated: 2016/05/15 09:33:22 by smahomed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *s1, const char *s2, size_t n)
{
	int		v[3];
	char	*s3;

	s3 = (char *)ft_memalloc(sizeof(ft_strlen(s2) + ft_strlen(s1)));
	v[0] = -1;
	v[1] = -1;
	v[2] = -1;
	while (s1[++v[0]])
		s3[v[0]] = s1[v[0]];
	while (s2[++v[1]] && v[1] < (int)n)
		s3[++v[0] - 1] = s2[v[1]];
	s3[v[0]] = '\0';
	while (s3[++v[2]] || s3[v[2] - 1])
		s1[v[2]] = s3[v[2]];
	return (s1);
}
