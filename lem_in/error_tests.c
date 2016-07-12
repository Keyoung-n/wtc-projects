/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_tests.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knage <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/05 08:10:00 by knage             #+#    #+#             */
/*   Updated: 2016/07/08 14:26:13 by knage            ###   ########.fr       */
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

int	is_copy(char *str, t_data *curr)
{
    while (curr)
    {
        if (ft_strcmp(curr->name, str) == 0)
            return (1);
        curr = curr->next;
    }
    return (0);
}

int is_valid_room(char *str, t_data *curr)
{
    int i;
    int spaces;

    i = 0;
    spaces = 0;
    if (is_copy(build_str(str, &i, ' '), curr) == 1)
        return (0);
    while (str[i] != ' ' && str[i] != '\0')
        i++;
    while (str[i])
    {
        if (str[i] == ' ')
        {
            spaces++;
            i++;
        }
        if (!ft_isnbr(str[i]))
            return (0);
        i++;
    }
    if (spaces != 1)
        return (0);
    return (1);
}

int is_valid_link(char *str, t_data *curr)
{
    while (curr)
    {
        if (ft_strcmp(str, curr->name) == 0)
            return (1);
        curr = curr->next;
    }
    return (0);
}