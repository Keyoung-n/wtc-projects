/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knage <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/19 14:26:49 by knage             #+#    #+#             */
/*   Updated: 2016/06/19 14:26:51 by knage            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H
# include "includes/libft.h"
# include <dirent.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <pwd.h>
# include <uuid/uuid.h>
# include <grp.h>
# include <time.h>

typedef	struct			s_list
{
	char				*file_name;
	struct s_list		*next;
}						t_list;

typedef struct			s_env
{
	char	*dir;
	int		show;
	int		printl;
	int		t;
	int		r;
	int		ur;
	int		y;
	int		all_dirs;
}						t_env;

typedef struct			s_dirs
{
	char			*dir_name;
	struct s_dirs	*next;
}						t_dirs;

t_list					*ft_ls(char *str, int show_hidden);
t_list					*reverse(t_list *head_ref);
t_list					*ft_lst(t_list *root);
int						search_twod(char **str, int i, char c);
void					add_element(t_list **list, char *value);
void					add_element_by_time(t_list **list, char *value);
void					ft_lsl(t_list *root);
void					print(t_list *root, int l);
void					checkflags(char c, char *str, t_env *env);
void					print_list(t_list *root);
void					print_rest(char *str, char *file_name);
#endif
