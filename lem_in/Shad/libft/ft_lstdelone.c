/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smahomed <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/15 10:20:30 by smahomed          #+#    #+#             */
/*   Updated: 2016/05/15 10:20:48 by smahomed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdelone(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*a;

	a = (t_list *)&(alst);
	if (alst != 0 && del != 0)
	{
		del((void *)a->content, (size_t)a->content_size);
		a->content = 0;
		a->content_size = 0;
	}
}
