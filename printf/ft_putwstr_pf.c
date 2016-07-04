/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putwstr_pf.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knage <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/06 08:33:24 by knage             #+#    #+#             */
/*   Updated: 2016/06/06 08:33:32 by knage            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putwstr_pf(va_list ap, int nbb)
{
	size_t	i;
	wchar_t	*str;

	i = 0;
	str = va_arg(ap, wchar_t *);
	printf("\n%S\n\n", str);
	exit(-1);
	while (i++ < nbb - ft_wcslen(str))
		ft_putchar(' ');
	if (str)
	{
		ft_putwstr(str);
		return (ft_wcslen(str) + i);
	}
	else
	{
		ft_putstr("(null)");
		return (6 + i);
	}
}
