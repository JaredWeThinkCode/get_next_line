/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhutchin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/27 15:34:51 by rhutchin          #+#    #+#             */
/*   Updated: 2019/06/04 15:13:43 by jnaidoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstmap(t_list *lst, t_list *(*f) (t_list *elem))
{
	t_list *a;
	t_list *b;

	if (lst == NULL || f == NULL)
		return (NULL);
	b = f(lst);
	a = b;
	while (lst->next != NULL)
	{
		b->next = f(lst->next);
		b = b->next;
		lst = lst->next;
	}
	return (a);
}
