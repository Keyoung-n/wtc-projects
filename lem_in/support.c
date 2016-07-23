/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   support.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knage <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/07 08:14:58 by knage             #+#    #+#             */
/*   Updated: 2016/07/23 14:20:12 by knage            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	add_link(t_data **curr)
{
	t_links	*head;
	t_links	*temp;
	t_data	*new;

	new = *curr;
	temp = new->links;
	if (temp == NULL)
		head = NULL;
	else
		head = temp;
	temp = (t_links *)malloc(sizeof(t_links));
	temp->next = head;
	head = temp;
	temp = head;
	new->links = temp;
}

char	*build_str(char *str, int *i, char limit)
{
	int		temp;
	int		size;
	char	*ret;

	temp = *i;
	size = 0;
	while (str[temp] != limit && str[temp] != '\0')
	{
		temp++;
		size++;
	}
	ret = (char*)malloc(sizeof(char*) * size + 1);
	temp = 0;
	while (str[*i] != limit && str[*i] != '\0')
	{
		ret[temp] = str[*i];
		(*i)++;
		temp++;
	}
	ret[temp] = '\0';
	(*i)++;
	return (ret);
}

void	check_type(t_env *env, t_data *temp)
{
	if (env->type)
	{
		temp->type = env->type;
		if (env->type == 1)
			env->special[0] = env->room_count;
		if (env->type == 2)
			env->special[1] = env->room_count;
		env->type = 0;
	}
	else
		temp->type = 0;
}
