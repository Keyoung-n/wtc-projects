/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knage <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/04 14:58:40 by knage             #+#    #+#             */
/*   Updated: 2016/07/04 17:51:16 by knage            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	extract_data(int fd)
{
	t_env env;

	get_ant_numbers(fd, &env);
	get_data(fd, &env);
}

int main(int ac, char **av)
{
	int fd;

	fd = open(av[1], O_RDONLY);
	if (ac == 2)
	{
		extract_data(fd);
	}
	return (0);
}
