/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   non_canonical.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcowle <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/04 16:18:33 by kcowle            #+#    #+#             */
/*   Updated: 2016/08/06 13:25:53 by knage            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "21sh.h"

void	select_c(char c)
{
	tputs(tgetstr("so", 0), 1, ft_ft_putchar);
	ft_putchar(c);
	tputs(tgetstr("se", 0), 1, ft_ft_putchar);
}

int		ft_printstring(t_main *e)
{
	int		x;

	x = -1;
	if (e->lineprom == 0)
		ft_putstr("\33[2K\r<<^>>: ");
	if (e->lineprom == 1)
		ft_putstr("\33[2k\r");
	while (++x <= e->a[e->y].x)
	{
		if (e->a[e->y].line[x] && ft_isprint(e->a[e->y].line[x]))
		{
			if (e->start != -2 && x > e->start && x < e->end)
				select_c(e->a[e->y].line[x]);
			else if (e->start != -2 && x < e->start && x > e->end)
				select_c(e->a[e->y].line[x]);
			else if (x == e->cursor)
				ft_cursor(e->a[e->y].line[x]);
			else
				ft_putchar(e->a[e->y].line[x]);
		}
	}
	return (1 + 0 * (e->cursor == e->a[e->y].x + 1 && ft_cursor(' ')));
}

int		ft_init(t_main *e, char *node)
{
	t_21line_l	*tmp;
	int			x;

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
	e->a[e->y].buff = 1024;
	e->a[e->y].line = (char *)malloc(sizeof(char) * e->a[e->y].buff);
	ft_strclr(e->a[e->y].line);
	return (1);
}

int		ft_selectinit(t_main *env)
{
    static int  n;
    
    n += (n < 2);
    if (n == 1)
    {
        tcgetattr(0 * tgetent(NULL, getenv("TERM")), &env->term);
        tputs(tgetstr("ti", NULL), 1, ft_ft_putchar);
        tputs(tgetstr("ho", NULL), 1, ft_ft_putchar);
    }
    env->term.c_lflag &= ~(ECHO | ICANON);
	env->term.c_cc[VMIN] = 1;
	env->term.c_cc[VTIME] = 0;
	tcsetattr(0, 0, &env->term);
	tputs(tgetstr("vi", NULL), 1, ft_ft_putchar);
	return (1);
}

int		ft_selectend(t_main *env)
{
	env->term.c_lflag &= ~(ICANON | ECHO);
	tcsetattr(0, 0, &env->term);
	tputs(tgetstr("ve", NULL), 1, ft_ft_putchar);
	return (1);
}
