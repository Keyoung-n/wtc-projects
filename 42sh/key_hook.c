/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knage <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/25 09:52:47 by knage             #+#    #+#             */
/*   Updated: 2016/08/30 08:46:45 by knage            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fortytwosh.h"

t_keyhook *key_hook_init(t_keyhook *env)
{
    env->buffsize = 0;
    env->cursor = 0;
    env->buff = 1024;
    env->line = ft_strnew(1024);
    env->x = 0;
    env->start = -2;
    env->end = -2;
    env->pro = NULL;
    env->clip = NULL;
    env->ctrl_v = 0;
    env->lineprom = 0;
    env->ret = 0;
    return (env);
}
void    remove_last_char(t_keyhook *env)
{
    int		i;
    
    i = env->cursor;
    while (i < env->x)
    {
        env->line[i] = env->line[i + 1];
        i++;
    }
    env->line[env->x] = '\0';
}

void		remove_char(t_keyhook *env)
{
    int		i;
    
    i = --env->cursor;
    while (i < env->x)
    {
        env->line[i] = env->line[i + 1];
        i++;
    }
    env->line[env->x] = '\0';
}

void		insert_char(t_keyhook *env, char c)
{
   	int		x;
    
    x = ++env->x;
    while (--x >= env->cursor)
    {
        env->line[x + 1] = env->line[x];
    }
    env->line[x + 1] = c;
}

void	malloc_buff(t_keyhook *env)
{
    char	*tmp;
    int		i;
    
    i = 0;
    env->buff += 1024;
    tmp = (char *)malloc(sizeof(char) * env->buff);
    while (env->line[i])
    {
        tmp[i] = env->line[i];
        i++;
    }
    if (env->line)
        free(env->line);
    env->line = tmp;
}

void		linextention(t_keyhook *env)
{
    tputs(tgetstr("dl", 0), 1, ft_ft_putchar);
    while (env->lineprom > 0 && ((env->lineprom -= 1) || 1))
    {
        tputs(tgetstr("dl", 0), 1, ft_ft_putchar);
        tputs(tgetstr("up", 0), 1, ft_ft_putchar);
        tputs(tgetstr("cr", 0), 1, ft_ft_putchar);
    }
    tputs(tgetstr("cr", 0), 1, ft_ft_putchar);
    ft_putstr(env->pro);
}

void	printline(t_keyhook *env)
{
    struct winsize	win;
    int				i;
    int				t[3];
    
    ioctl(0 * ((t[0] = win.ws_col) || 1), TIOCGWINSZ, &win);
    i = 0;
    linextention(env);
    t[1] = 7;
    env->lineprom = 0;
    while (i <= env->x && ((t[1] += 1) || 1))
    {
        env->lineprom += (t[1] == t[0]);
        t[1] = t[1] * (t[1] < t[0]);
        if (env->line[i])
        {
            if (env->start != -2 && i > env->start && i < env->end)
                select_c(env->line[i]);
            else if (env->start != -2 && i < env->start && i > env->end)
                select_c(env->line[i]);
            else if (i == env->cursor)
			{
			//	ft_putstr("!!!\n");
                ft_cursor(env->line[i]);
			}
            else
            {
                if (env->line[i] == '\t')
                    write(1, "    ", 4);
                else
                    ft_putchar(env->line[i]);
            }
        }
        i++;
    }
    ft_cursor(' ');
}
