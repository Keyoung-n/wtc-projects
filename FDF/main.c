/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knage <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/23 08:16:42 by knage             #+#    #+#             */
/*   Updated: 2016/08/31 06:58:54 by knage            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "stdio.h"

int		escape(int keycode)
{
	if (keycode == 53)
		exit(0);
	return (0);
}

t_map	*reverse(t_map *head_ref)
{
	t_map	*prev;
	t_map	*current;
	t_map	*next;

	prev = NULL;
	current = head_ref;
	while (current != NULL)
	{
		next = current->next;
		current->next = prev;
		prev = current;
		current = next;
	}
	head_ref = prev;
	return (head_ref);
}

void	savepoints(int x, int y, t_env *env)
{
	env->x = x;
	env->y = y;
	env->area = x * y;
}

t_map	*getmapsize(char **line, int fd, t_map *curr, t_env *env)
{
	t_env	temp;

	temp.y = 0;
	temp.map = NULL;
	get_next_line(fd, line);
//	while (get_next_line(fd, line) == 1 && temp.x != -1)
//	{
		line = ft_strsplit(*line, ' ');
		support(&temp, line);
		while (line[temp.x] != '\0' && temp.x != -1)
		{
			curr = (t_map *)malloc(sizeof(t_map));
			curr->z = temp.y;
			curr->x = (1 / sqrt(6)) * ((sqrt(3.0) * temp.x) \
					+ (-(sqrt(3.0) * curr->z))) * temp.size;
			curr->y = (1 / sqrt(6)) * (temp.x + (2 * \
					(-ft_atoi(line[temp.x]))) + curr->z) * temp.size;
			curr->next = temp.map;
			temp.map = curr;
			temp.x++;
		}
		temp.y++;
//	}
	curr = temp.map;
	savepoints(temp.x, temp.y, env);
	return (reverse(curr));
}

int		main(int argc, char **argv)
{
	char	*line;
	t_map	*points;
	t_env	env;
	int		fd;

	if (argc == 2)
	{
		fd = open(argv[1], O_RDONLY);
		if (fd != -1)
		{
			points = getmapsize(&line, fd, env.map, &env);
			if (line && env.x != -1)
			{
				env.mlx = mlx_init();
				env.win = mlx_new_window(env.mlx, 1500, 1000, "fdf");
				draw(points, env);
				mlx_key_hook(env.win, escape, 0);
				mlx_loop(env.mlx);
			}
		}
		close(fd);
	}
	return (0);
}
