#include "fortytwosh.h"

int     tab_getdir(t_main *e)//  touc  touccon  toucnoul
{
	char    t[1024];
	int     x;
	int     ib;

	ib = 1;
	x = e->cursor;
	while (e->a[e->y].line[--x])
	{//extract chars?//either change bools or x counter stops
		//if (e->a[e->y].line[x] == '/' && )
		//    }
		//if there is a dir then copy it into tabs
		//get directory and criteria
	}
	return (0);
}

void     is_tab_auto_complete(t_main *env)
{
	int i;
	int j;

	i = env->cursor;
	j = env->cursor;
	ft_printf("%c: i = %i j = %i\n",env->a[env->y].line[i], i, j);
	if (env->t.pos == NULL)
		env->t.pos = env->t.list;
	else
	{
		if (env->t.pos->next != NULL)
			env->t.pos = env->t.pos->next;
		else
			env->t.pos = env->t.list;
		while (env->a[env->y].line[i] != ' ' && env->a[env->y].line[i] != '\t' && i != 0)
			i--;
	}
	while (env->a[env->y].line[i] != ' ' && env->a[env->y].line[i] != '\t' && i != 0)
		i--;
	while (env->a[env->y].line[i] != ' ' && env->a[env->y].line[i] != '\t' && env->a[env->y].line[i] != '\0')
		j++;
	ft_printf("%c, i = %i j = %i\n", env->a[env->y].line[i], i, j);
	ft_printf("%s\n", env->t.pos->name);	
}

int     is_tab_printed(t_main *e)
{
	//return (0); if not printed then we will print and return 0;
	return (1);
}

int     is_tab_auto_fill(t_main *e)
{
	return (1);
}

t_main	*load_list(t_main *env)
{
	int i;
	t_tablst	*curr;
	t_tablst	*head;

	i = 0;
	head = NULL;
	ft_putchar('\n');
	while (i != 5 && env->a[i].line != NULL)
	{
		ft_printf("	%i	%s\n", i, env->a[i].line);
		curr = (t_tablst*)malloc(sizeof(t_tablst) * 1);
		curr->name = ft_strdup(env->a[i].line);
		curr->next = head;
		head = curr;
		i++;
	}
	curr = head;
	env->t.list = curr;
	return (env);
}

int     ft_tab(t_main *e)
{
	int     x;

	x = -1;
	while ( e->a[e->y].line[++x] == '\t' || e->a[e->y].line[++x] == ' ')
		;
	e->t.is_tab = (e->cursor < x || e->t.ctrl_v == 1) + e->t.is_tab * (e->cursor >= x);
	if (e->t.is_tab && (ft_selectinsert(e, '\t')))//then mode to add tab spaces is activated.
		e->cursor += (e->cursor < e->a[e->y].x + 1);//thus add \t to string
	if (!e->t.ctrl_v && !e->t.is_tab)//then we need to print the list
	{
		tab_getdir(e);//+ get criteria
		if (is_tab_auto_fill(e))
			if (is_tab_printed(e))
			{
				e = load_list(e);
				is_tab_auto_complete(e);
			}
	}
	e->t.is_tab = 0;
	e->t.ctrl_v = 0;//always false until cntrl v is clicked.
	return (1);
}
