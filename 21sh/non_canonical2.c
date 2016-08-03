#include "minishell.h"

int		ft_ft_putchar(int c)
{
    return (write(2, &c, 1));
}

int     ft_cursor(char c)
{
    tputs(tgetstr("so", 0), 1, ft_ft_putchar);
    ft_putstr("\033[1;36m");
    ft_putchar(c);
    ft_putstr("\033[00m");
    tputs(tgetstr("se", 0), 1, ft_ft_putchar);
    return (0);
}

int     ft_selectdelete(t_main *e)
{
    int     x;
    
    x = e->cursor - 1;
    while (++x < e->a[e->y].x)
        e->a[e->y].line[x] = e->a[e->y].line[x + 1];
    e->a[e->y].line[e->a[e->y].x] = '\0';
    return (1);
}

int     ft_selectbackspace(t_main *e)
{
    int     x;
    
    x = --e->cursor - 1;
    while (++x < e->a[e->y].x)
        e->a[e->y].line[x] = e->a[e->y].line[x + 1];
    e->a[e->y].line[e->a[e->y].x] = '\0';
    return (1);
}

int     ft_selectinsert(t_main *e, char c)
{
    int     x;
    
    //    if (c == ' ')
    //        e->a[e->y].line = ft_strtrim(e->a[e->y].line);
    x = ++e->a[e->y].x;
    while (--x >= e->cursor)
        e->a[e->y].line[x + 1] = e->a[e->y].line[x];
    e->a[e->y].line[x + 1] = c;
    return (1);
}
