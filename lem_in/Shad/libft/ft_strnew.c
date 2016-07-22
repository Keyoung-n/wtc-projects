/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smahomed <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/11 15:44:37 by smahomed          #+#    #+#             */
/*   Updated: 2016/05/14 07:17:53 by smahomed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char	*s;

	s = (char *)malloc(sizeof(char) * size);
	if (s == 0)
		return (s);
	ft_bzero(s, size);
	s[size] = '\0';
	return (s);
}
