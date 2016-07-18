/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extract.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knage <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/04 16:11:16 by knage             #+#    #+#             */
/*   Updated: 2016/07/18 16:09:04 by knage            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void    add_room(t_data **curr)
{
	t_data *head;
	t_data *temp;

	temp = *curr;
	if (*curr == NULL)
		head = NULL;
	else
		head = temp;
	temp = (t_data *)malloc(sizeof(t_data));
	temp->next  = head;
	head = temp;
	temp = head;
	*curr = temp;
}

void	get_ant_numbers(t_env *env)
{
	char	*line;
	long	ant_numbers;

	get_next_line(0, &line);
	ft_putstr(line);
	ft_putchar('\n');
	ant_numbers = ft_atoi(line);
	if (ant_numbers != 0)
		env->ant_count = ant_numbers;
	else
	{
		ft_putstr("error: invalid input for number of ants");
		exit(0);
	}
}

void	get_room(char *str, t_data **room, t_env *env)
{
	int 	i;
	t_data *temp;

	i = 0;
	temp = *room;
	if (is_valid_room(str, temp))
	{
		add_room(&temp);
		temp->name = build_str(str, &i, ' ');
		temp->x = ft_atoi(build_str(str, &i, ' '));
		temp->y = ft_atoi(build_str(str, &i, ' '));
		if (env->type)
		{
			temp->type = env->type;
			env->type = 0;
		}
		else
			temp->type = 0;
	}
	else
	{
		ft_putstr("error: invalid room");
		exit(0);
	}
	*room = temp;
}

void	get_link(char *str, t_data *room)
{
	char	*temp;
	char	*linkto;
	t_data	*re;
	int		i;

	i = 0;
	temp = build_str(str, &i, '-');
	linkto = build_str(str, &i, '-');
	i = 0;
	re = room;
	while (room && i == 0)
	{
		if (ft_strcmp(room->name, temp) == 0)
		{
			if (is_valid_link(linkto, re))
			{
				add_link(&room);
				room->links->link = linkto;
				i = 1;
			}
		}
		room = room->next;
	}
	if (i != 1)
	{
		ft_putstr("error: bad link");
		exit(0);
	}
}

int    check_special(char *line, t_env *env)
{
	if (env->type != 0)
		env->type = -1;
	if (!(ft_strcmp(line, "##start")))
	{
		if (env->special[0] != 1 && (env->special[0] = 1))
			return (1);
		env->type = -1;
	}
	else if (!(ft_strcmp(line, "##end")))
	{
		if (env->special[1] != 1 && (env->special[1] = 1))
			return (2);
		env->type = -1;
	}
	if (env->type == -1)
	{
		ft_putstr("error");
		exit(0);
	}
	return (0);
}
