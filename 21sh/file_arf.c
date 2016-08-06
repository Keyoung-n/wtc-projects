/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_arf.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcowle <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/04 11:46:32 by kcowle            #+#    #+#             */
/*   Updated: 2016/08/04 14:41:17 by kcowle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "21sh.h"

void	ft_links(char *line, t_env *env)
{
	if (ft_isdigit(line[0]) && line[1] == '>' && line[2] == '&' && ft_isdigit(line[3]))
	{
		dup2(ft_atoi(&line[3]), ft_atoi(&line[0]));
		close(ft_atoi(&line[3]));
	}
	else if (ft_isdigit(line[0]) && line[1] == '>' && line[2] == '&' && line[3] == '-')
		close(ft_atoi(&line[0]));
}
