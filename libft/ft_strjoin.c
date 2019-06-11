/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnaidoo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/28 08:13:02 by jnaidoo           #+#    #+#             */
/*   Updated: 2019/05/31 14:53:35 by jnaidoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*a;
	size_t	b;
	size_t	c;
	size_t	d;

	if (!s1 || !s2)
		return (NULL);
	b = ft_strlen(s1) + ft_strlen(s2);
	c = 0;
	d = 0;
	if (!(a = ft_memalloc(b + 1)))
		return (NULL);
	while (c < ft_strlen(s1))
	{
		a[c] = s1[c];
		c++;
	}
	while (d < ft_strlen(s2))
	{
		a[c] = s2[d];
		c++;
		d++;
	}
	a[b + 1] = '\0';
	return (a);
}
