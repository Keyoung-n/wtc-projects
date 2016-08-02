#include "minishell.h"

void	ft_doublecoms(t_env *env, t_main *w, int getl)
{
	char **coms;
	int y;
	int i;
	static int k;
	char *com;
	char *str;
	char *temp;
	int x;

	w->line = temp;
	x = 1;
	y = 0;
	i = 0;
	while (ft_select(w, &(w->line)))
		;
	if (ft_strchr(w->line, ';') == 0 && ft_strchr(w->line, '|') == 0)
		ft_minishell(env, *w);
	//THIS HANDLES THE ';'
	else if (ft_strchr(w->line, '|') == 0 && ft_strchr(w->line, ';') != 0)
	{
		coms = ft_strsplit(w->line, ';');
		while (coms[y] != NULL)
		{
			w->line = coms[y];
			ft_minishell(env, *w);
			y++;
		}
	}
	//THIS IS GONNA HANDLE THE '|' NAD THE ';'
	else if (ft_strchr(w->line, '|') != 0)
	{
		coms = ft_strsplit(w->line, ';');
		while (coms[i] != NULL)
		{
			if (ft_strchr(coms[i], '|') == 0)
			{
				w->line = coms[i];
				ft_minishell(env, *w);
			}
			else if (ft_strchr(coms[i], '|') != 0)
			{
				ft_pipes(env, coms, i, w);
				ft_bzero(w->line, ft_strlen(w->line));
				k = 1;
			}
			i++;
		}
	}
	k = 1;
	ft_doublecoms(env, w, 0); 
}
