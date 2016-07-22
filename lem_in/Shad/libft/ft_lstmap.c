/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smahomed <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/13 09:25:11 by smahomed          #+#    #+#             */
/*   Updated: 2016/05/15 13:30:33 by smahomed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*a[3];

	a[1] = f(lst);
	while (a[1] && (lst = lst->next))
	{
		a[0] = (t_list *)ft_memalloc(sizeof(t_list));
		a[0] = f(lst);
		a[0]->next = a[1];
		a[1] = a[0];
	}
	a[0] = 0;
	while (a[1])
	{
		a[2] = a[1]->next;
		a[1]->next = a[0];
		a[0] = a[1];
		a[1] = a[2];
	}
	return (a[0]);
}
