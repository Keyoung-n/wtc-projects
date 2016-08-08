/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_arf.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcowle <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/07 15:59:48 by kcowle            #+#    #+#             */
/*   Updated: 2016/08/08 12:24:53 by knage            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "twentyonesh.h"

void	ft_links(char *line)
{
	if (ft_isdigit(line[0]) && line[1] == '>' &&
			line[2] == '&' && ft_isdigit(line[3]))
	{
		dup2(ft_atoi(&line[3]), ft_atoi(&line[0]));
		close(ft_atoi(&line[3]));
	}
	else if (ft_isdigit(line[0]) && line[1] == '>' &&
			line[2] == '&' && line[3] == '-')
		close(ft_atoi(&line[0]));
}
