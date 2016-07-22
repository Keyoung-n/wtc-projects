/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smahomed <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/18 15:22:09 by smahomed          #+#    #+#             */
/*   Updated: 2016/07/18 15:23:37 by smahomed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		get_next_line(int fd, char **line)
{
	static int	n;
	int			y;
	char		*l;
	char		c;

	if (fd < 0)
		return (-1);
	if ((y = read(fd, &c, 1)) && y && ++n &&\
			(c != '\n' || (n == 1 && c == '\n')))
		y = get_next_line(fd, line);
	else
	{
		l = (char *)malloc(sizeof(char *) * n);
		*line = l;
	}
	l = *line;
	--n;
	n = 0 * (n < 0) + n * (n >= 0);
	l[n] = '\0' * (c == '\n' && n > 0) + c * (!(c == '\n' && n > 0));
	*line = l;
	return (y > 0);
}
