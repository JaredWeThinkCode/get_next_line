/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhutchin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/27 13:52:30 by rhutchin          #+#    #+#             */
/*   Updated: 2019/06/04 15:08:41 by jnaidoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del) (void *, size_t))
{
	t_list *a;
	t_list *b;

	a = *alst;
	while (a->next != NULL)
	{
		b = a->next;
		del(a, a->content_size);
		a = b;
	}
	del(a, a->content_size);
	*alst = NULL;
}
