/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdfuncs.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcowle <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/07 15:59:48 by kcowle            #+#    #+#             */
/*   Updated: 2016/08/07 15:59:58 by kcowle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "twentyonesh.h"

void	ft_fdfuncs(char *line)
{
	int			i;
	static int	fd;

	i = 0;
	while (line[i] != '>')
		i++;
	if (ft_isdigit(line[i - 1]) == 1 && line[i] == '>' && line[i + 1] == '&'
			&& ft_isdigit(line[i + 2]) == 1)
	{
		if (ft_atoi(&line[i + 2]) == fd)
			dup2(fd, ft_atoi(&line[i - 1]));
		else
			fd = dup2(ft_atoi(&line[i - 1]), ft_atoi(&line[i + 2]));
	}
	else if (ft_isdigit(line[i - 1]) == 1 && line[i] == '>'
			&& line[i + 1] == '&' && line[i + 2] == '-')
		close(ft_atoi(&line[i - 1]));
}
