/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knage <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/25 12:37:35 by knage             #+#    #+#             */
/*   Updated: 2016/07/29 10:45:23 by knage            ###   ########.fr       */
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

//char    *keys(char *ret, char *buf, int *cposition)
//{
 //       return (ret);
//}

char    *ft_get_line()
{
    char    *ret;
    char    *str;
    char    buf[10];
    int     cur;
    int     max;
    int     pos;

    cur = 3;
    max = 3;
    ret = ft_strnew(1);
    ft_bzero(buf, 4);
    while ((read(0, buf, 4)) && buf[0] != '\n')
    {
        pos = max;
        if (buf[0] == 27 && buf[2] == 67)
        {
        }
        else if (buf[0] == 27 && buf[2] == 68)
        {
            if (cur != 3)
                cur--;
        }
        else
        {
            str = ret;
            ret = ft_strjoin(str, buf);
            free(str);
            cur++;
            max++;
        }
        ft_putstr("\33[2K\r");
        ft_putstr("~> ");
        ft_putstr(ret);
        while (pos != cur)
        {
            tputs(tgetstr("le", NULL), 1, ft_putchar_i);
            --pos;
        }
        ft_bzero(buf, 4);
        
    }
    return (ret);
}
