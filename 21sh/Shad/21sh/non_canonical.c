#include "minishell.h"

int     ft_cursor(char c)
{
	tputs(tgetstr("so", 0), 1, ft_ft_putchar);
	ft_putstr("\033[1;36m");
	ft_putchar(c);
	ft_putstr("\033[00m");
	tputs(tgetstr("se", 0), 1, ft_ft_putchar);
	return (0);
}


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
		if (e->start != -2 && x > e->start && x < e->end)
			select_c(e->a[e->y].line[x]);
		else if (e->start != -2 && x < e->start && x > e->end)
			select_c(e->a[e->y].line[x]);
		else if (x == e->cursor)// && e->cursor != e->a[e->y].x)
			ft_cursor(e->a[e->y].line[x]);
		else
			ft_putchar(e->a[e->y].line[x]);
	}
	x +=  (e->cursor == e->a[e->y].x + 1 && ft_cursor(' '));
	return (1);
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
	else
	{
		e->buffsize += 1024 * (e->y + 1 >= e->buffsize);
		tmp = (t_21line_l *)malloc(sizeof(t_21line_l) * e->buffsize);
		while (e->a && ++x < e->buffsize && e->a[x].line)
			tmp[x] = e->a[x];
		tmp[++e->y].buff = 1024;//increments
		tmp[e->y].x = -1;
		e->cursor = 0;
		e->cp_cursor = -2;//unused.
		e->y_cursor = e->y;
		tmp[e->y].line = (char *)malloc(sizeof(char) * tmp[e->y].buff);
		if (e->a)
			free(e->a);
		e->a = tmp;
	}
	return (1);
}

int     ft_selectinit(t_main *e)
{
	struct winsize	win;

	tgetent(0, getenv("TERM"));
	tcgetattr(0, &(e->term));
	e->term.c_lflag &= ~(ICANON | ECHO);
	e->term.c_cc[VMIN] = 1;
	e->term.c_cc[VTIME] = 0;
	ioctl(0, TIOCGWINSZ, &win);
	e->v[2] = win.ws_col;
	e->v[3] = win.ws_row;
	tcsetattr(0, 0, &(e->term));
	tputs(tgetstr("ti", 0), 1, ft_ft_putchar);
	tputs(tgetstr("vi", 0), 1, ft_ft_putchar);
	return (1);
}

int			ft_selectend(t_main *e)
{
	e->term.c_lflag |= (ICANON | ECHO);
	tputs(tgetstr("te", 0), 1, ft_ft_putchar);
	tputs(tgetstr("ve", 0), 1, ft_ft_putchar);
	tcsetattr(0, 0, &(e->term));
	return (1);
}
