/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_tests.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knage <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/05 08:10:00 by knage             #+#    #+#             */
/*   Updated: 2016/07/06 16:08:10 by knage            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int	what_type(char *line)
{// error 0 // link 1 // point 2 // comment 3 // special 4
    int i;
    
    i = 0;
    if (line[0] == '#')
    {
        if (line[1] == '#')
            return (4);
        else
            return (3);
    }
    if (line[0] == ' ')
        return (0);
    else
    {
        while (line[i])
        {
            if (line[i] == '-')
                return (1);
            if (line[i] == ' ')
                return (2);
            i++;
        }
    }
    return (0);
}
