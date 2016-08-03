
#include "minishell.h"

void	select_c(char c)
{
    tputs(tgetstr("so", 0), 1, ft_ft_putchar);
    ft_putchar(c);
    tputs(tgetstr("se", 0), 1, ft_ft_putchar);
}

int     ft_printstring(t_main *e)
{
    int     x;
    
    x = -1;
    ft_putstr("\33[2K\r\033[1;32m<<^>>\033[00m: ");//erases the terminal line.
    while (++x <= e->a[e->y].x)
    {
        if (e->a[e->y].line[x] && ft_isprint(e->a[e->y].line[x]))
        {
            if (e->start != -2 && x > e->start && x < e->end)
                select_c(e->a[e->y].line[x]);
            else if (e->start != -2 && x < e->start && x > e->end)
                select_c(e->a[e->y].line[x]);
            else if (x == e->cursor)// && e->cursor != e->a[e->y].x)
                ft_cursor(e->a[e->y].line[x]);
            else
                ft_putchar(e->a[e->y].line[x]);
        }
    }
    return (1 + 0 * (e->cursor == e->a[e->y].x + 1 && ft_cursor(' ')));
}

int     ft_init(t_main *e, char *node)
{
    t_21line_l  *tmp;
    int         x;
    
    if ((x = -1) && !e->a)
    {
        e->a = (t_21line_l *)malloc(sizeof(t_21line_l) * e->buffsize);
        while (++x < e->buffsize)
            e->a[x].line = 0;
    }
    if (e->y < e->buffsize && (e->buffsize += 1024 * (e->y + 1 >= e->buffsize)))
    {
        tmp = (t_21line_l *)malloc(sizeof(t_21line_l) * e->buffsize);
        while (e->a && ++x < e->buffsize && e->a[x].line)
            tmp[x] = e->a[x];
        if (e->a)
            free(e->a);
        e->a = tmp;
    }
    e->cursor = 0;
    e->a[++e->y].x = -1;
    e->y_cursor = e->y;
    e->a[e->y].buff = 1024;//increments later
    e->a[e->y].line = (char *)malloc(sizeof(char) * e->a[e->y].buff);
    ft_strclr(e->a[e->y].line);
    return (1);
}

int     ft_selectinit(t_main *env)
{
    tgetent(NULL, getenv("TERM"));
    tcgetattr(0, &env->term);
    env->term.c_lflag &= ~(ECHO | ICANON);
    env->term.c_cc[VMIN] = 1;
    env->term.c_cc[VTIME] = 0;
    tcsetattr(0, 0, &env->term);
    tputs(tgetstr("ti", NULL), 1, ft_ft_putchar);
    tputs(tgetstr("ho", NULL), 1, ft_ft_putchar);
    tputs(tgetstr("vi", NULL), 1, ft_ft_putchar);
    return (1);
}

int			ft_selectend(t_main *env)
{
    env->term.c_lflag &= ~(ECHO | ICANON);
    tcsetattr(0, 0, &env->term);
    tputs(tgetstr("te", NULL), 1, ft_ft_putchar);
    tputs(tgetstr("ve", NULL), 1, ft_ft_putchar);
    return (1);
}
