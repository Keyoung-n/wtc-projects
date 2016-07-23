#include "lem_in.h"

int		final(t_env *e, t_links **tmp)
{
    int     b;
    
    b = 1;
    while (b && (e->helper = -1))
    {
        b = 0;
        while (++e->helper < e->ant_count)
            if (tmp[e->helper] && (++b > 0))
            {
                if (tmp[e->helper]->bar_code >= 0)
                {
                    b > 1 && ft_printf(" ");
                    ft_printf("L%d-%s", e->helper + 1,\
                              e->maze[tmp[e->helper]->bar_code].name);
                }
                tmp[e->helper] = tmp[e->helper]->next;
            }
        b > 0 && ft_printf("\n");
    }
    return (0);
}
