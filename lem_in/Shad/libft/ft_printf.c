/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smahomed <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/24 12:41:39 by smahomed          #+#    #+#             */
/*   Updated: 2016/06/09 16:55:08 by smahomed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdarg.h>

char	*ft_c(long long unsigned int n, int b, char c, char d)
{
	char	*ptr;
	char	e;

	e = c;
	if (e == '#' && (ft_tolower(d) == 'o' && (c = d)))
		d = 3;
	if (e == '#' && (ft_tolower(d) == 'x' && (c = d)))
		d = 5;
	b = (2 * (d == 0)) + (10 * (d > 0)) + (-2 * (d > 2)) + (8 * (d > 4));
	ptr = (char *)malloc(sizeof(char) * 49);
	if (n == 0)
		*--ptr = '0';
	while ((c < 96) && (n != 0) && (*--ptr = "0123456789ABCDEF"[n % b]))
		n /= b;
	while ((c > 96) && (n != 0) && (*--ptr = "0123456789abcdef"[n % b]))
		n /= b;
	if (e == '#' && ((d <= 4) || (d > 4 && (*--ptr = c))))
		*--ptr = '0';
	return (ptr);
}

int		f2(va_list a, const char *s, int x, int b)
{
	long int	y[2];
	char		*p;

	p = (char *)ft_memalloc(sizeof(char) * 49);
	if ((y[1] = 10000000) && (s[x] == 'h' && s[x + 1] == 'h'))
		ft_putstr(va_arg(a, char *) + 0 * (b = 3));
	if ((s[x] == 'l' && s[x + 1] != 'l') && (b = 2))
		ft_putstr(ft_c(va_arg(a, long long unsigned int), 0, s[x], 1));
	if ((s[x] == 'l' && s[x + 1] == 'l') && (b = 3))
		ft_putstr(ft_c(va_arg(a, long long unsigned int), 0, s[x], 1));
	if (s[x] == '#' && (b = 3))
		ft_putstr(ft_c(va_arg(a, long long unsigned int), 0, '#', s[x + 1]));
	if (s[x] == 'f' && (y[0] = (long int)(va_arg(a, double) * y[1])))
	{
		while (y[0] % 10 == 0 && (y[1] /= 10))
			y[0] /= 10;
		while (y[1] > 1 && y[0] > 0 && (*--p = (y[0] % 10) + 48))
			if ((y[1] /= 10))
				y[0] /= 10;
		if (y[1] == 1 && y[0] != 0 && (*--p = '.'))
			while (y[0] > 0 && (*--p = (y[0] % 10) + 48))
				y[0] /= 10;
		ft_putstr(p + 0 * ((b = 2) == 1));
	}
	return (b);
}

int		f3(va_list a, const char *s, int x, char c)
{
	char	*v[2];
	int		n[4];

	n[3] = 0;
	n[2] = va_arg(a, int);
	if (s[x] == '0' && (n[2] < 0 && (n[3] = -1)))
		n[2] = -n[2];
	n[1] = -1;
	v[0] = ft_itoa(n[2]);
	n[0] = ft_atoi(&s[x + 1]) - (int)ft_strlen(v[0]);
	v[1] = (char *)ft_memalloc(sizeof(char) * n[0] + 2);
	if (s[x] == '0' && !(s[x] == '+' && (*--v[++n[1]] = '+')))
		c = '0';
	*--v[1] = '\0';
	while (++n[1] < (n[0] + n[3]))
		*--v[1] = c;
	if (s[x] == '0' && n[3] == -1)
		*--v[1] = '-';
	if (s[x] == '+' || s[x] == '0' || s[x] == ' ')
		ft_putstr(ft_strcat(v[1], v[0]));
	if (s[x] == '-')
		ft_putstr(ft_strcat(v[0], v[1]));
	return (3 + ((int)ft_strlen(ft_itoa(ft_atoi(&s[x + 1])))));
}

int		f1(va_list a, const char *s, int x, int b)
{
	int		y;

	y = -1;
	if ((s[x] == 's' || s[x] == 'S') && (b = 2))
		ft_putstr(va_arg(a, char *));
	if ((s[x] == 'c' || s[x] == 'C') && (b = 2))
		ft_putchar((char)va_arg(a, int));
	if ((s[x] == 'i' || ft_tolower(s[x]) == 'd') && (b = 2))
		ft_putstr(ft_itoa(va_arg(a, int)));
	while ("buUoOxX"[++y])
		if (s[x] == "buUoOxX"[y] && (b = 2))
			ft_putstr(ft_c(va_arg(a, long long unsigned int), 0, s[x], y));
	if ((s[x] == 'p') && (b = 2))
		ft_putstr(ft_strcat("0x7fff", ft_c(va_arg(a, int), 0, s[x], 5)));
	y = -1;
	while ("-+0 "[++y])
		if (s[x] == "-+0 "[y])
			b = f3(a, s, x, ' ');
	if ((s[x] == '%') && (b = 2))
		ft_putstr("%");
	if (((s[x] == 'h' && (s[x] != 'h')) || s[x] == 'j' || s[x] == 'z'))
		ft_putnbr(va_arg(a, int) + 0 * ((b = 2)));
	if (b <= 0)
		b = f2(a, s, x, b);
	return (b);
}

int		ft_printf(const char *s, ...)
{
	va_list		a;
	int			x;

	x = 0;
	va_start(a, s);
	while (s[x])
		if (s[x] == '%')
			x += f1(a, s, x + 1, 0);
		else if (s[x] && s[x] != '%')
			write(1, &s[++x - 1], 1);
	va_end(a);
	return (1);
}
