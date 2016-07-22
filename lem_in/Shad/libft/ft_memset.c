/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smahomed <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/11 15:59:48 by smahomed          #+#    #+#             */
/*   Updated: 2016/05/14 17:34:30 by smahomed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
    unsigned char	*i;

    i = (unsigned char *)b;
    while (len-- > 0 && ((*i = (unsigned char)c) || 1 == 1))
        (len && ++i);
    return (b);
}
