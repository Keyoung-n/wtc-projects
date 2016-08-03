/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Get_Next_Line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knage <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/17 07:04:21 by knage             #+#    #+#             */
/*   Updated: 2016/07/04 07:15:00 by knage            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_realloc(char *str, int i)
{
	char	*str2;
	int		j;
	int		k;

	j = 0;
	k = 0;
	str2 = (char*)malloc(sizeof(char*) * i + 1);
	while (j != i)
	{
		str2[j] = str[j];
		j++;
	}
	free(str);
	return (str2);
}

char	*readline(int fd, long int *i, int *ret, int j)
{
	char						*buf;
	char						*str;

	str = (char *)malloc(sizeof(char) * 1);
	buf = (char *)malloc(sizeof(char) * BUFF_SIZE);
	if (*i == 0)
		*ret = read(fd, buf, BUFF_SIZE);
	while (buf[*i] != '\n' && *ret)
	{
		str = ft_realloc(str, j);
		str[j] = buf[*i];
		(*i)++;
		j++;
		if (buf[*i] == '\0')
		{
			*ret = read(fd, buf, BUFF_SIZE);
			*i = 0;
		}
	}
	str[j] = '\0';
	(*i)++;
	if (buf[*i] == 0)
		*i = 0;
	free(buf);
	return (str);
}

int		get_next_line(const int fd, char **line)
{
	static long int				i;
	int							j;
	static char					*buf;
	static int					ret;

	j = 0;
	*line = NULL;
	if (i == 0)
		i = 0;
	buf = readline(fd, &i, &ret, j);
	if (ret > 0)
	{
		*line = buf;
		return (1);
	}
	if (ret == 0)
		return (0);
	return (-1);
}
