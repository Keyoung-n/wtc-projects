/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knage <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/25 12:37:35 by knage             #+#    #+#             */
/*   Updated: 2016/07/28 15:48:32 by knage            ###   ########.fr       */
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
    int     cposition;

    cposition = 3;
    ret = ft_strnew(1);
    tputs(tgetstr("ve", NULL), 1, ft_putchar_i);
    tputs(tgetstr("sc", NULL), 1, ft_putchar_i);
    while ((read(0, buf, 4)) && buf[0] != '\n')
    {
        str = ret;
        if (buf[0] == 27 && buf[2] == 67)
        {
            cposition += 1;
        }
        else if (buf[0] == 27 && buf[2] == 68)
        {
            ft_putstr("\b\b\b\b");
            if (cposition != 3)
            {
                tputs(tgetstr("ce", NULL), 1, ft_putchar_i);
                tputs(tgetstr("le", NULL), 1, ft_putchar_i);
                cposition -= 1;
            }
            else
            {
                ft_putstr("    ");
                tputs(tgetstr("rc", NULL), 1, ft_putchar_i);
            }
        }
        else
        {
            ret = ft_strjoin(str, buf);
            free(str);
            cposition++;
        }
    }
    return (ret);
}
