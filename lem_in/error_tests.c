/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_tests.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knage <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/05 08:10:00 by knage             #+#    #+#             */
/*   Updated: 2016/07/23 13:08:54 by knage            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		what_type(char *line)
{
	int	i;

	i = 0;
	if (line[0] == '#')
	{
		if (line[1] == '#')
			return (4);
		else
			return (3);
	}
	if (line[0] == ' ')
		return (0);
	else
	{
		while (line[i])
		{
			if (line[i] == '-')
				return (1);
			if (line[i] == ' ')
				return (2);
			i++;
		}
	}
	return (0);
}

int		is_copy(char *str, t_data *curr)
{
	while (curr)
	{
		if (ft_strcmp(curr->name, str) == 0)
			return (1);
		curr = curr->next;
	}
	return (0);
}

int		is_valid_room(char *str, t_data *curr)
{
	int	i;
	int	spaces;

	i = 0;
	spaces = 0;
	if (is_copy(build_str(str, &i, ' '), curr) == 1)
		return (0);
	while (str[i] != ' ' && str[i] != '\0')
		i++;
	while (str[i])
	{
		if (str[i] == ' ')
		{
			spaces++;
			i++;
		}
		if (!ft_isnbr(str[i]))
			return (0);
		i++;
	}
	if (spaces != 1)
		return (0);
	return (1);
}

int		is_valid_link(char *str, t_data *curr)
{
	while (curr)
	{
		if (ft_strcmp(str, curr->name) == 0)
			return (curr->bar_code);
		curr = curr->next;
	}
	return (-1);
}

int     is_end(t_env env)
{
	int i;
	int	j;
	t_links *temp;

	ft_initrooms(&env);
	i = -1;
	env.room[env.special[0]] = 2;
	while (++i != env.room_count && (j = -1))
		while (++j != env.room_count)
			if (env.room[j] == 2)
			{
				temp = env.maze[j].links;
				while (temp)
				{
					env.room[temp->bar_code] != 1 && (env.room[temp->bar_code] = 2);
					if (temp->bar_code == env.special[1])
						return (1);
					temp = temp->next;
				}
				env.room[j] = 1;
			}
	return (0);
}
