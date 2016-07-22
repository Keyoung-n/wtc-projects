#include "lem_in.h"

int     ft_init4(t_env *e)
{
    int     x;
    
    x = -1;
    while (++x < e->room_count)
        e->o[x] = 0;
    return (0);
}

int     ft_init3(t_env *e, t_links *t, int node)//assigns new nodes from current nodes.
{
    t_links     *tmp;
    
    e->o[node] = (node != e->special[1]);//room is officially occupied.
    tmp = (t_links *)malloc(sizeof(t_links));
    tmp->bar_code = node;
    tmp->counter += 1;//because we are about to attach a new link.
    tmp->path = ft_init1(t->path, node);//attach path to new node to path
    tmp->next = e->n[e->nodes_count[0]];
    e->n[e->nodes_count[0]] = tmp;
    return (0);
}

int     init2(t_env *e)
{
    t_links *tmp;
    
    tmp = (t_links *)malloc(sizeof(t_links));
    tmp->bar_code = -1;
    tmp->next = e->start;
    e->start = tmp;
    return (0);
}

t_links     *ft_init1(t_links *a, int node)
{
    t_links     *tmp;

    tmp = (t_links *)malloc(sizeof(t_links));
    tmp->bar_code = node;
    tmp->next = a;
    a = tmp;
    return (a);
}

int     ft_init(t_env *e, int node)//start init
{
    t_links     *tmp;

    e->o[node] = (node != e->special[1]);//room is officially occupied.
    tmp = (t_links *)malloc(sizeof(t_links));
    tmp->bar_code = node;
    tmp->counter = 1;//because we are about to attach a new link.
    tmp->path = e->start;
    tmp->path = ft_init1(tmp->path, node);//attach start path to path
    tmp->next = e->n[e->nodes_count[0]];
    e->n[e->nodes_count[0]] = tmp;
    return (0);
}
