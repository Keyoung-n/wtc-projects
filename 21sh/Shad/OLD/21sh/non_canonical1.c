#include "minishell.h"

int		ft_ft_putchar(int c)
{
    return (write(2, &c, 1));
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
    
    x = ++e->a[e->y].x;
    while (--x >= e->cursor)
        e->a[e->y].line[x + 1] = e->a[e->y].line[x];
    e->a[e->y].line[x + 1] = c;
    return (1);
}

void     ft_select5(t_main *e, char **line, char b[4])
{
    if (b[0] == -30 && b[1] == -119 && b[2] == -92) //left select
    {
        if (e->start == -2)
        {
            e->start = e->cursor;
            e->end = e->cursor - 1;
        }
        e->cursor--;
        e->end--;
        if (e->start == e->end - 1 && (e->end = -2))
            e->start = -2;
    }
    if (b[0] == -30 && b[1] == -119 && b[2] == -91) //right select
    {
        if (e->start == -2)
        {
            e->start = e->cursor - 1;
            e->end = e->cursor;
        }
		if (e->cursor != e->a[e->y].x)
        	e->cursor++;
        e->end++;
        if (e->start == e->end - 1 && (e->end = -2))
            e->start = -2;
    }
}

int     ft_select4(t_main *e, char **line, char b[4])
{
    if (b[0] == -30 && b[1] == -119 && b[2] == -120 && !b[3])
        ft_cut(e);
    if (b[0] == -61 && b[1] == -89 && !b[2] && !b[3])
        ft_copy(e);
    if (b[0] == -30 && b[1] == -120 && b[2] == -102 && !b[3])
        ft_paste(e);//cntrl v paste
    ft_select5(e, line, b);
    return (1);
}

int     ft_select3(t_main *e, char **line, char b[4])
{
    if (b[0] == 27 && b[1] == 91 && b[2] == 53 && b[3] == 126 && e->a[e->y].x > -1)
        e->cursor = 0;//home
    if (b[0] == 27 && b[1] == 91 && b[2] == 54 && b[3] == 126)
        e->cursor = e->a[e->y].x + 1;//end
    if (b[0] == 27 && b[1] == 91 && b[2] == 72 && !b[3])
    {//cntrl LEFT
        while (e->cursor > 0 && e->a[e->y].line[e->cursor - 1] == ' ')
            e->cursor -= 1;
        while (e->cursor > 0 && e->a[e->y].line[e->cursor - 1] != ' ')
        e->cursor -= 1;
    }
    if (b[0] == 27 && b[1] == 91 && b[2] == 70 && !b[3])
    {//down/ cntrl RIGHT
        while (e->cursor <= e->a[e->y].x &&  e->a[e->y].line[e->cursor + 1] == ' ')
            e->cursor += 1;
        while (e->cursor <= e->a[e->y].x && e->a[e->y].line[e->cursor + 1] != ' ')
            e->cursor += 1;
        e->cursor = e->cursor * (e->cursor >= e->a[e->y].x)\
            + (e->cursor + 2) * (e->cursor < e->a[e->y].x);
    }
    return (ft_select4(e, line, b));
}

int     ft_select2(t_main *e, char **line, char b[4])
{
    if (b[0] == 27 && b[1] == 91 && b[2] == 51 && b[3] == 126)//delete
        if (e->a[e->y].x > -1 && e->cursor <= e->a[e->y].x && ft_selectdelete(e))
            --e->a[e->y].x;
    if (b[0] == 27 && b[1] == 91 && b[2] == 65 && !b[3] && e->y_cursor > 0)
    {
        ft_strclr(e->a[e->y].line);
        ft_strcat(e->a[e->y].line, e->a[--e->y_cursor].line);
        e->a[e->y].buff = e->a[e->y_cursor].buff;
        e->a[e->y].x = ft_strlen(e->a[e->y].line);
        e->cursor = e->a[e->y].x + 1;
        
    }
    if (b[0] == 27 && b[1] == 91 && b[2] == 66 && !b[3] && e->y_cursor < e->y)
    {
        e->y_cursor + 1 != e->y && (e->a[e->y].line[0] = '\0');
        if (e->y_cursor + 1 == e->y)
            ft_strclr(e->a[e->y].line);
        ft_strcat(e->a[e->y].line, e->a[++e->y_cursor].line);
        e->a[e->y].buff = e->a[e->y_cursor].buff;
        e->a[e->y].x = ft_strlen(e->a[e->y].line);
        e->cursor = e->a[e->y].x + 1;
    }
    return (ft_select3(e, line, b));
}


int     ft_select(t_main *e, char **line)
{//should store the specific charecters in memory and point at them
    char        b[4];
    int         tmp;
    
    ft_printstring(e);
    //write(1, " | ", 3);
    //if (e->cp) ft_putstr(e->cp);
    ft_bzero(b, 4);
    read(0, b, 4);
    if (((b[0] == 32 && !b[1]) || (ft_isprint(b[0]) && !b[1])) \
        && (ft_selectinsert(e, b[0])))//user inputs
        ++e->cursor;
    //if (ft_isprint(b[0]))
    //ft_putnbr((int)b[0]);write(1, " ", 1);ft_putnbr((int)b[1]);write(1, " ", 1);
    //ft_putnbr((int)b[2]);write(1, " ", 1);ft_putnbr((int)b[3]);ft_putchar('\n');
    if (b[0] == 127 && e->a[e->y].x > -1 && e->cursor > 0 && ft_selectbackspace(e))//backspace
        tmp += 0 * (--e->a[e->y].x);
    if (b[0] == 27 && b[1] == 91 && b[2] == 67 && b[3] == 0 && (e->start = -2))
        tmp += 0 * (e->cursor += (e->cursor < e->a[e->y].x + 1));//right arrow.
    if (b[0] == 27 && b[1] == 91 && b[2] == 68 && b[3] == 0 && (e->start = -2))
        e->cursor -= (e->cursor > 0);//left arrow.
    if (b[0] == 27 && !b[1] && ft_selectend(e))//esc key
        exit(0);//exits loop; thus ends the programme.
    if (b[0] == 10 && !b[1] && ft_printstring(e + 0 * (e->cursor = -2)))
        return (0 * (!(*line = e->a[e->y].line) + ft_init(e, 0) + write(1, "\n", 1)));
    //send the string line to minishell; enter key^
    return (ft_select2(e, line, b));
}
