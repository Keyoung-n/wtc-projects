#include "lem_in.h"

int		final(t_env *e, t_links **tmp)
{
    int     b;

    b = 1;
    while (b && (e->x = -1))
    {
        b = 0;
        while (++e->x < e->ant_count)
            if (tmp[e->x] && (++b > 0))
            {
                if (tmp[e->x]->bar_code >= 0)
                {
                    b > 1 && ft_printf(" ");
                    ft_printf("L%d-%s", e->x + 1, e->a[tmp[e->x]->bar_code].name);
                }
                tmp[e->x] = tmp[e->x]->next;
            }
        b > 0 && ft_printf("\n");
    }
	return (0);
}
