/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smahomed <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/15 09:37:07 by smahomed          #+#    #+#             */
/*   Updated: 2016/05/15 10:47:13 by smahomed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		v[2];
	char	*s3;

	s3 = (char *)ft_memalloc(sizeof(ft_strlen(s2) + ft_strlen(s1)));
	v[0] = -1;
	v[1] = -1;
	while (s1[++v[0]])
		s3[v[0]] = s1[v[0]];
	while (s2[++v[1]])
		s3[++v[0] - 1] = s2[v[1]];
	s3[v[0]] = '\0';
	return (s3);
}
