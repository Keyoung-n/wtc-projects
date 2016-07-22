/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smahomed <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/12 09:48:47 by smahomed          #+#    #+#             */
/*   Updated: 2016/05/15 13:32:43 by smahomed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*a;

	a = (t_list *)ft_memalloc(sizeof(t_list));
	a->content = (void *)content;
	a->content_size = content_size;
	a->next = 0;
	return (a);
}
