/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knage <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/19 14:24:09 by knage             #+#    #+#             */
/*   Updated: 2016/06/19 14:24:19 by knage            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	find_dir(t_env *env, int ac, char **av)
{
	int	i;

	i = 0;
	if ((i = search_twod(av, ac, '-')))
		env->dir = av[i];
	else
		env->dir = ".";
}

void	getflags(int ac, char **av, t_env *env)
{
	int	x;
	int	out;

	env->y = 0;
	out = 1;
	while (env->y < ac && out == 1)
	{
		x = 0;
		while (av[env->y][x] != '\0' && av[env->y][0] == '-' && out == 1)
		{
			if (x != 0)
			{
				checkflags(av[env->y][x], av[env->y], env);
			}
			x++;
		}
		if (env->y + 1 < ac && av[env->y + 1][0] != '-')
			out = 0;
		env->y++;
	}
}

t_dirs	*getdirs(int ac, char **av, t_env *env)
{
	t_dirs	*curr;
	t_dirs	*head;

	head = NULL;
	if (env->y < ac)
		while (env->y < ac)
		{
			curr = (t_dirs *)malloc(sizeof(t_dirs));
			curr->dir_name = av[env->y];
			curr->next = head;
			head = curr;
			env->y++;
			env->all_dirs++;
		}
	else
	{
		curr = (t_dirs *)malloc(sizeof(t_dirs));
		curr->dir_name = ".";
		curr->next = head;
		head = curr;
		env->all_dirs = 1;
	}
	curr = head;
	return (curr);
}

void	useflags(t_env *env, char *dir_name)
{
	t_list	*root;

	root = ft_ls(dir_name, env->show);
	if (env->t == 1)
		root = ft_lst(root);
	if (env->r == 1)
		root = reverse(root);
	print(root, env->printl);
}

int		main(int ac, char **av)
{
	t_env		env;
	t_dirs		*dirs;

	getflags(ac, av, &env);
	dirs = getdirs(ac, av, &env);
	if (env.all_dirs > 1)
		while (dirs)
		{
			ft_printf("%s:\n", dirs->dir_name);
			useflags(&env, dirs->dir_name);
			if (dirs->next != NULL)
				ft_printf("\n");
			dirs = dirs->next;
		}
	else
		useflags(&env, dirs->dir_name);
	return (0);
}
