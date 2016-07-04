/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_pf2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knage <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/06 08:33:24 by knage             #+#    #+#             */
/*   Updated: 2016/06/06 08:33:32 by knage            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_putz_pf(va_list ap, const char *format, int *i)
{
	size_t	nb;

	if (format[*i + 1] != 'd' && format[*i + 1] != 'i')
	{
		return (0);
	}
	*i += 1;
	nb = va_arg(ap, size_t);
	return (ft_putnbr_base(nb, "0123456789"));
}

int		ft_puthexa_min_pf(va_list ap, int nbb)
{
	int		i;
	int		nb;
	int		nb2;

	i = 0;
	nb = va_arg(ap, unsigned int);
	nb2 = ft_return_nb_nb(nb, "0123456789abcdef");
	while (i++ < nbb - nb2)
		ft_putchar(' ');
	return (ft_putnbr_base_u(nb, "0123456789abcdef") + i);
}

int		ft_puthexa_max_pf(va_list ap, int nbb)
{
	int		i;
	int		nb;
	int		nb2;

	i = 0;
	nb = va_arg(ap, unsigned int);
	nb2 = ft_return_nb_nb(nb, "0123456789ABCDEF");
	while (i++ < nbb - nb2)
		ft_putchar(' ');
	return (ft_putnbr_base_u(nb, "0123456789ABCDEF") + i);
}

int		ft_puthexa_pf(va_list ap, int nbb)
{
	void		*nb;
	int			i;
	int			nb2;

	i = 0;
	nb = va_arg(ap, void*);
	nb2 = ft_return_nb_nb((long)nb, "0123456789abcdef") + 2;
	while (i++ < nbb - nb2)
		ft_putchar(' ');
	ft_putstr("0x");
	return (ft_putnbr_base((long)nb, "0123456789abcdef") + i + 2);
}

int		ft_putwchar_pf(va_list ap, int nbb)
{
	int			i;
	int			size;
	wchar_t		*s;

	i = 0;
	s = va_arg(ap, wchar_t *);
	size = 0;
	while (s[size])
		size++;
	while (i++ < nbb - size)
		ft_putchar(' ');
	if (s)
	{
		sft_putwchar(s);
		return (size + i);
	}
	else
	{
		ft_putstr("(null)");
		return (6 + i);
	}
}
