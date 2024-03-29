/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnaidoo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/24 10:54:36 by jnaidoo           #+#    #+#             */
/*   Updated: 2019/06/06 09:17:20 by jnaidoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striter(char *s, void (*f)(char *))
{
	size_t	a;

	a = 0;
	if (s != NULL && f != NULL)
	{
		while (s[a] != '\0')
		{
			f(&s[a]);
			a++;
		}
	}
}
