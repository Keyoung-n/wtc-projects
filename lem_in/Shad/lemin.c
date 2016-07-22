#include "lemin.h"

int     main4(t_list **a, t_env *e)
{
    t_data  r[e->room_count];
    int     o[e->room_count];
    char    *s[2];
    int     x;

    x = -1;
    e->a = r;
    e->o = o;
    e->start = 0;
    a[1] = ft_lstrev(a[0]);
    while (a[1] && ++x < e->room_count)
    {
        e->a[x].links = 0;
        e->a[x].bar_code = x;
        s[0] = ft_strstr((char *)a[1]->content, " ");
        e->a[x].x = ft_atoi(s[0]);
        e->a[x].y = ft_atoi(ft_strstr(&s[0][1], " "));
        s[0][0] = '\0';
        e->a[x].name = (char *)a[1]->content;
        a[0] = a[1]->next;
        free(a[1]);
        a[1] = a[0];
    }
    return (ft_sync(a, e) * ft_leminalg(e));
}

int     main3(t_env *e, char *line)
{
    if (ft_strcmp(line, "##start") == 0)
        e->special[0] = e->room_count;
    if (ft_strcmp(line, "##end") == 0)
        e->special[1] = e->room_count;
    if (ft_strcmp(line, "##end") == 0 || ft_strcmp(line, "##start") == 0)
        free(line);
    return (0);
}

int     main2(t_env *e, char *line)
{
    int     x;
    int     y;
    int     z;

    z = 0;
    y = 1;
    x = -1;
    while (line[++x])
        ((line[x] == '-' && (++z)) || (line[x] == ' ' && (++y)));
    e->room_count += (z <= 0);
    return (-z * (z > 0) + y * (z <= 0));
}

int     main1(t_env *e)
{
    t_list  *a[4];
    char    *line;

    a[1] = 0;
    a[3] = 0;
    get_next_line(0, &line);
    if(!line)
        return (-1);
    ft_printf("%d\n", e->ant_count = (long)ft_atoi(line));
    while (get_next_line(0, &line))
    {
        if (line[0] != '#' && line[0] != 'L')
        {
            //ft_lstadd(&a[1], ft_lstnew(line, main2(e, line)));
            a[0] = ft_lstnew(line, main2(e, line));
            a[0]->next = a[1];
            a[1] = a[0];
        }
        ft_printf("%s\n", (char *)line);
        main3(e, line);
    }
    return (0 * main4(a, e));
}

int     main(void)
{
    t_env   e;

    e.special[0] = -1;
    e.special[0] = -1;
    e.room_count = 0;
    main1(&e);
    return (0);
}
