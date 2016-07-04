/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knage <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/19 14:24:09 by knage             #+#    #+#             */
/*   Updated: 2016/06/19 14:24:19 by knage            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_list	*ft_lst(t_list *root)
{
	t_list *new;

	new = NULL;
	while (root)
	{
		add_element_by_time(&new, root->file_name);
		root = root->next;
	}
	return (new);
}

t_list	*reverse(t_list *head_ref)
{
	t_list	*prev;
	t_list	*current;
	t_list	*next;

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

t_list	*ft_ls(char *str, int show_hidden)
{
	DIR				*dir;
	struct dirent	*dp;
	t_list			*root;

	root = NULL;
	dir = opendir(str);
	if (dir != NULL)
	{
		while ((dp = readdir(dir)) != NULL)
		{
			if (show_hidden == 0)
			{
				if (ft_strncmp(".", dp->d_name, 1) != 0)
					add_element(&root, dp->d_name);
			}
			else
				add_element(&root, dp->d_name);
		}
		closedir(dir);
	}
	else
		perror("ft_ls");
	return (root);
}

void	print_permissions(struct stat buf)
{
	if (S_ISDIR(buf.st_mode))
		ft_printf("d");
	else if (buf.st_mode == S_IFBLK)
		ft_printf("b");
	else if (S_IFCHR == buf.st_mode)
		ft_printf("c");
	else if (S_IFIFO == buf.st_mode)
		ft_printf("P");
	else if (S_IFLNK == buf.st_mode)
		ft_printf("l");
	else if (S_IFSOCK == buf.st_mode)
		ft_printf("s");
	else
		ft_printf("-");
	ft_printf((buf.st_mode & S_IRUSR) ? "r" : "-");
	ft_printf((buf.st_mode & S_IWUSR) ? "w" : "-");
	ft_printf((buf.st_mode & S_IXUSR) ? "x" : "-");
	ft_printf((buf.st_mode & S_IRGRP) ? "r" : "-");
	ft_printf((buf.st_mode & S_IWGRP) ? "w" : "-");
	ft_printf((buf.st_mode & S_IXGRP) ? "x" : "-");
	ft_printf((buf.st_mode & S_IROTH) ? "r" : "-");
	ft_printf((buf.st_mode & S_IWOTH) ? "w" : "-");
	ft_printf((buf.st_mode & S_IXOTH) ? "x  " : "-  ");
	ft_printf("%d ", buf.st_nlink);
}

void	ft_lsl(t_list *root)
{
	struct stat		buf;
	struct passwd	*pwd;
	struct group	*grp;
	char			*tme;

	while (root != NULL)
	{
		stat(root->file_name, &buf);
		print_permissions(buf);
		pwd = getpwuid(buf.st_uid);
		if (pwd == NULL)
			ft_printf("unknown  ");
		else
			ft_printf("%s  ", pwd->pw_name);
		grp = getgrgid(buf.st_gid);
		if (pwd == NULL)
			ft_printf("unknown  ");
		else
			ft_printf("%s  ", grp->gr_name);
		ft_printf("%lld ", buf.st_size);
		tme = ctime(&buf.st_mtime);
		print_rest(&(tme[4]), root->file_name);
		root = root->next;
	}
}
