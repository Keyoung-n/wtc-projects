/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smahomed <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/13 09:23:00 by smahomed          #+#    #+#             */
/*   Updated: 2016/07/18 15:08:47 by smahomed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd(t_list **alst, t_list *new)
{
	t_list	*t;

	t = (t_list *)&alst;
	new->next = t;
	t = new;
//	t->next = new;
//	t->content = new->content;
//	t->content_size = new->content_size;
//	t->next = new->next;
}
