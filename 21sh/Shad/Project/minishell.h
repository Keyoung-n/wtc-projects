/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcowle <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/10 14:07:10 by kcowle            #+#    #+#             */
/*   Updated: 2016/08/01 15:29:06 by smahomed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H
# include <stdlib.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <string.h>
# include "libft/libft.h"
# include <dirent.h>
# include <libc.h>
# include <stdlib.h>
# include <unistd.h>
# include <termcap.h>
# include <string.h>
# include <termios.h>
# include <sys/ioctl.h>
# include <signal.h>

typedef struct      s_21line_l
{
    char            *line;
    int             buff;//number of chars in string
    int             x;
}                   t_21line_l;

typedef struct	s_env
{
	pid_t			father;
	char            *path;
	char            **cmd;
	char            **args;
	char            **env;
	char            **enviro;
	char            **envirobk;
	int             cont;
	int             i;
	char            **history;
}                   t_env;

typedef struct	s_echo
{
	int				state;
	int				state2;
	int				newline;
	char			**line2;
	int				e;
	int				o;
	int				i;
}					t_echo;

typedef struct		s_main
{
    struct termios  term;
	char			*line;
	char			**line2;
	int				comcount;
    int				v[4];
    t_21line_l      *a;
    int             buffsize;
    int             cursor;
    int             y_cursor;
    int             cp_cursor;
    char            *cp;//copied
    int             y;
    int				start; //k
    int				end; //k
    char			*clip; //k
}					t_main;

int             ft_selectremalloc(t_main *e);
int             ft_cursor(char c);
int             ft_selectdelete(t_main *e);
int             ft_selectinsert(t_main *e, char c);
int             ft_selectbackspace(t_main *e);
int             ft_printstring(t_main *e);
int             ft_select(t_main *e, char **line);
int             ft_init(t_main *e, char *node);
int             ft_ft_putchar(int c);
int             ft_selectinit(t_main *env);
int             ft_selectend(t_main *env);
void			ft_fdfuncs(char *line);
void			ft_doublecoms(t_env *env, t_main *w, int read);
void			ft_echo(char *line);
char			*get_path(t_env *env);
t_env			*set_env(char **line2, t_env *env);
t_env			*ft_unsetenv(t_env *env);
int				ft_isbuiltin(t_env *env, t_main *w, char *line);
void			ft_cd(char *line);
t_env			get_dir(t_env *env, char **line);
void			ft_minishell(t_env *env, t_main m);
void			print_env(t_env *env);
t_env			ft_excecute(char **line2, int comcount, t_env *env);
int				oct_dec(int n);
void			ft_printoct(char *line, int *i);
void			ft_handle2(char *line, t_echo *ec);
int				ft_handle1(char *line, char **line2, int *e, int *o);
void			ft_handle3(t_echo *ec, char *line);
void			init_echo(char *line, t_echo *ec);
int				ft_pow(int i, int x);
void			ft_pipes(t_env *env, char **coms, int i, t_main *w);
char            **ft_insert(t_env *env, char *com);
void            ft_copy(t_main *env);
void            ft_paste(t_main *env);
void            ft_cut(t_main *env);
void			sinno(int signall);
void			ft_free2d(char **array);
t_env			ft_keep_struct(t_env env, int i);
#endif
