#include "lem_in.h"

int     ft_leminalg3(t_env *e)
{
	t_links		*a[3];
    t_links		*tmp[e->ant_count];

	e->x = -1;
	ft_init4(e);
	while (++e->x < e->ant_count && (a[0] = e->fpaths[e->x]->path) >= 0)
	{
        a[1] = a[0];
        tmp[e->x] = 0;
        while (a[1])//paths for specific ant
		{
			a[0] = (t_links *)malloc(sizeof(t_links));
			a[0]->bar_code = a[1]->bar_code;
			a[0]->next = tmp[e->x];
			tmp[e->x] = a[0];
			a[1] = a[1]->next;
		}
	}
	return (final(e, tmp));
}

int     ft_leminalg2(t_env *e)//assigns nodes from current nodes.
{
	t_links     *tmp;
	t_links     *tmp1;

	tmp = e->n[e->nodes_count[1]];
	while (tmp)
	{
		tmp1 = e->a[tmp->bar_code].links;
		while (tmp1)//creates new nodes
		{
			e->o[tmp1->bar_code] == 0 && ft_init3(e, tmp, tmp1->bar_code);
			tmp1 = tmp1->next;
		}
		e->o[tmp->bar_code] = 0;//previous room empties.
		tmp->bar_code == e->special[1] && (e->fpaths[++e->x] = tmp);
		tmp = tmp->next;
	}
	return (0);
}

int     ft_leminalg1(t_env *e)//assigns nodes from start node
{
	t_links     *tmp;

	tmp = e->a[e->special[0]].links;
	while (tmp)
	{
		e->o[tmp->bar_code] == 0 && ft_init(e, tmp->bar_code);
		tmp->bar_code == e->special[1] && (e->fpaths[++e->x] = tmp);
		tmp = tmp->next;
	}
	return (0);
}

int     ft_leminalg(t_env *e)
{
	t_links     *a[e->ant_count];
	int         x;

	x = 1;
	e->x = -1;
	ft_init4(e);
	e->n[0] = 0;
	e->n[1] = 0;
	e->start = 0;
	e->fpaths = a;
	e->nodes_count[0] = 0;//empty waiting for links
	e->nodes_count[1] = 1;//has links to loop through
	while (e->x < e->ant_count)//
	{
		e->nodes_count[0] = (e->nodes_count[0] == 0);
		e->nodes_count[1] = (e->nodes_count[1] == 0);
		ft_leminalg2(e);//other nodes
		ft_leminalg1(e);//start
		((x = (x == 0)) || 1 == 1) && x == 0 && ft_init2(e);//start gains a -1
		e->n[e->nodes_count[1]] = 0;
	}
	return (ft_leminalg3(e));//here prove what came out.
}
