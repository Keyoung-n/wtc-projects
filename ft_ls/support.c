/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   support.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knage <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/19 14:24:10 by knage             #+#    #+#             */
/*   Updated: 2016/06/19 14:24:19 by knage            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		search_twod(char **str, int i, char c)
{
	int	y;
	int	x;

	y = 1;
	while (y < i)
	{
		x = 0;
		while (str[y][x] != '\0')
		{
			if (str[y][x] != c)
				return (y);
			x++;
		}
		y++;
	}
	return (0);
}

void	print_list(t_list *root)
{
	while (root)
	{
		ft_printf("%s\n", root->file_name);
		root = root->next;
	}
}

void	print(t_list *root, int l)
{
	if (l == 0)
		print_list(root);
	else
		ft_lsl(root);
}

void	checkflags(char c, char *str, t_env *env)
{
	if (c == 'a')
		env->show = 1;
	else if (c == 't')
		env->t = 1;
	else if (c == 'r')
		env->r = 1;
	else if (c == 'R')
		env->ur = 1;
	else if (c == 'l')
		env->printl = 1;
	else
		ft_printf("ft_ls: illegal option '%s'\n", str);
}

void	add_element(t_list **list, char *value)
{
	t_list	*add;

	add = (t_list *)malloc(sizeof(t_list *));
	add->file_name = value;
	while (*list != 0)
	{
		if (ft_strcmp((*list)->file_name, add->file_name) > 0)
			break ;
		list = &(*list)->next;
	}
	add->next = *list;
	*list = add;
}
