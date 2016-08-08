/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quote.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcowle <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/07 15:59:48 by kcowle            #+#    #+#             */
/*   Updated: 2016/08/07 15:59:58 by kcowle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "twentyonesh.h"

void	is_quote(t_main *main, char *str)
{
	if (str[0] == 34 && str[1] == 0)
		main->quote++;
	else if (str[0] == 96 && str[1] == 0)
		main->quote++;
	else if (str[0] == 39 && str[1] == 0)
		main->quote++;
	else if (main->quote % 2 == 0)
	{
		if (str[0] == 123 && str[1] == 0)
			main->open++;
		else if (str[0] == 125 && str[1] == 0)
			main->open--;
		else if (str[0] == 40 && str[1] == 0)
			main->open++;
		else if (str[0] == 41 && str[1] == 0)
			main->open--;
	}
}
