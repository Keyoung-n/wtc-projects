#include "lemin.h"

t_links     *ft_sync2lstrev(t_links **path)
{
    t_links *a[3];

    a[1] = *path;
    *path = 0;
    while (a[1])
    {
        a[2] = a[1]->next;
        a[1]->next = *path;
        *path = a[1];
        a[1] = a[2];
    }
    return (*path);
}

int     ft_sync1(int y, char *s, t_env *e)
{
    t_links     *tmp;
    int         x;

    x = -1;
    while (++x < e->room_count)
        if (ft_strcmp(e->a[x].name, s) == 0)
        {
            tmp = (t_links *)malloc(sizeof(t_links));
            tmp->bar_code = x;
            tmp->next = e->a[y].links;
            e->a[y].links = tmp;
            //ft_printf("T %d %d\n", y, e->a[y].links->bar_code);
        }
    return (0);
}

int     ft_sync(t_list **a, t_env *e)
{
    int     x;
    char    *s;
    
    while (a[1] && (x = -1))
    {
        //ft_printf("%s ", (char *)a[1]->content);
        s = ft_strstr(a[1]->content, "-");
        s[0] = '\0';
        s = &s[1];
        while (++x < e->room_count)
            if (ft_strcmp(e->a[x].name, (char *)a[1]->content) == 0)
                ft_sync1(x, s, e);
        a[0] = a[1]->next;
        free(a[1]);
        a[1] = a[0];
    }
    return (0);
}