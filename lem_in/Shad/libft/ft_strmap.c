/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smahomed <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/11 15:44:37 by smahomed          #+#    #+#             */
/*   Updated: 2016/05/11 18:09:49 by smahomed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	int		x;
	char	*t;

	x = -1;
	t = (char *)malloc(sizeof(char) * ft_strlen(s));
	while (s[++x])
		t[x] = f(s[x]);
	return (t);
}
