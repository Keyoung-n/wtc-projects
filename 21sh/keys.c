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

char    *add_char(char **str, char c, int cur)
{
    char    *ret;
    int     i;
    int     j;
    
    i = 0;
    j = 0;
    cur -= 3;
    ret = (char *)malloc(sizeof(char*) * ft_strlen(*str) + 2);
    while (*str[i] != '\0')
    {
        ret[j] = *str[i];
        if (j + 1 == cur)
            j++;
        j++;
        i++;
    }
    ret[cur] = c;
    ret[cur + 1] = '\0';
    free(*str);
    return (ret);
}

int     keys(char **ret, char c, int cposition)
{
    char *str;
    
    str = *ret;
    *ret = add_char(&str, c, cposition);
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
    ret = ft_strnew(1);
    while ((read(0, buf, 4)) && buf[0] != '\n')
    {
        if (keys(&ret, buf[0], cposition))
        {
            tputs(tgetstr("cr", NULL), 1, ft_putchar_i);
            tputs(tgetstr("ce", NULL), 1, ft_putchar_i);
            ft_putstr("~> ");
            ft_putstr(ret);
            cposition++;
        }
        ft_bzero(buf, 4);
    }
    ft_putchar('\n');
    return (ret);
}
