/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knage <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/25 12:37:35 by knage             #+#    #+#             */
/*   Updated: 2016/07/25 12:37:49 by knage            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "21sh.h"

char    *add_char(char *str, char c, int slide)
{
    char    *ret;
    int     i;
    
    i = slide + 1;
    ret = (char *)malloc(sizeof(char*) * ft_strlen(str) + 2);
    ret[i] = c;
    ret[i + 1] = '\0';
    free(str);
    return (ret);
}

int     keys(char c)
{
    char k;
    
    k = c;
    return (1);
}

char    *ft_get_line()
{
    char    *ret;
    char    buf[10];
    int     cposition;
    int     size;
    
    size = 0;
    cposition = 0;
    ret = (char*)malloc(sizeof(char*) * 1);
    while ((read(0, buf, 4)) && buf[0] != '\n')
    {
        ft_putstr(ret);
        if (keys(buf[0]))
        {
            size++;
            ret = add_char(ret, buf[0], size);
        }
 //       tputs(tgetstr("cd", NULL), 1, ft_putchar_i);
   //     ft_putstr(ret);
    }
    ft_putchar('\n');
    return (ret);
}
