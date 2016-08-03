#include "minishell.h"

int		ft_selectremalloc(t_main *e)
{
    char    *tmp;
    int     x;
    
    x = -1;
    e->a[e->y].buff += 1024;
    tmp = (char *)malloc(sizeof(char) * e->a[e->y].buff);
    while (e->a[e->y].line[++x])
        tmp[x] = e->a[e->y].line[x];
    if (e->a[e->y].line)
        free(e->a[e->y].line);
    e->a[e->y].line = tmp;
    return (0);
}
