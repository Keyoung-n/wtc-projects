/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knage <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/04 07:19:54 by knage             #+#    #+#             */
/*   Updated: 2016/07/04 08:27:37 by knage            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	command(char *line)
{
	char **input;

	input = ft_strsplit(line, ' ');
	if (ft_strcmp(input[0], "echo") == 0)
		echo(input);
	ft_putstr("$>");
}

void	minishell()
{
	char	*line;

	ft_putstr("$>");
	while (get_next_line(0, &line))
	{		
		command(line);
	}
}

int main(void)
{
	minishell();
	return (0);
}
