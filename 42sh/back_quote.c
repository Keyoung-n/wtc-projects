/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   back_quote.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcowle <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/22 10:26:42 by kcowle            #+#    #+#             */
/*   Updated: 2016/08/22 10:38:55 by kcowle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fortytwosh.h"

void	back_quots(t_env *env, t_main *w)
{
	int i;
	int x;
	int num;
	char *line;
	char *com;
	
	line = (char *)malloc(sizeof(char *) * ft_strlen(w->line));
	ft_strcpy(line, w->line);
	i = ft_ifindstr(w->line, "`");
	w->line[i] = '*';
	x = ft_ifindstr(w->line, "`");
	w->line[i] = '`';
	i++;
	x--;
	num = 0;
	com = (char *)maloc(sizeof(char *) * x - i + 1);
	while (i <= x)
	{
		com[num] = w->line[i];
		num++;
		i++;
	}
	ft_doublecoms()
}
