#ifndef LEMIN_H
# define LEMIN_H
# include "libft/libft.h"

typedef struct	s_links
{
    int 			bar_code;
    int             counter;
    struct s_links  *path;
    struct s_links	*next;
}				t_links;

typedef struct	s_data
{
    char			*name;
    int				x;
    int				y;
    int				type;
    int				bar_code;
    t_links			*links;
    struct s_data	*next;
}				t_data;

typedef struct	s_env
{
    long    ant_count;
    long    room_count;
    t_data  *a;
    int     special[2];
    int     type;
    int     size;
    int     *o;//room_occupied?
    int      nodes_count[2];
    int      x;
    t_links  **fpaths;
    t_links  *start;
    t_links  *n[2];
}				t_env;

int     ft_init4(t_env *e);
int     ft_init3(t_env *e, t_links *t, int node);
int     init2(t_env *e);
t_links *ft_init1(t_links *a, int node);
int     ft_init(t_env *e, int node);
t_links *ft_sync2lstrev(t_links **path);
int     ft_sync(t_list **a, t_env *e);
int     ft_leminalg(t_env *e)
#endif
