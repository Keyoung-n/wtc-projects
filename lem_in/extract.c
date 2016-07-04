/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extract.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knage <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/04 16:11:16 by knage             #+#    #+#             */
/*   Updated: 2016/07/04 16:38:22 by knage            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	get_ant_numbers(int fd, t_env *env)
{
	char	*line;
	long	ant_numbers;

	get_next_line(fd, &line);
	ant_numbers = ft_atoil(line);
	if (ant_numbers != 0)
	{
		env->ant_count = ant_numbers;
	}
	else
	{
		ft_putstr("error");
		exit(0);
	}
}
