/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extra.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knage <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/19 14:24:09 by knage             #+#    #+#             */
/*   Updated: 2016/06/19 14:24:19 by knage            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	print_rest(char *str, char *file_name)
{
	char *cpy;

	cpy = (char*)malloc(sizeof(char*) * ft_strlen(str));
	ft_strncpy(cpy, str, ft_strlen(str) - 1);
	ft_printf("	%s", cpy);
	ft_printf(" %s\n", file_name);
	free(cpy);
}
