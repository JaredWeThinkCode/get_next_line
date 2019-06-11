/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnaidoo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/28 13:02:45 by jnaidoo           #+#    #+#             */
/*   Updated: 2019/06/06 09:25:58 by jnaidoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_istrim(char const *s)
{
	size_t	a;

	a = 0;
	while (s[a] == ' ' || s[a] == ',' || s[a] == '\n' || s[a] == '\t')
	{
		a++;
	}
	return (a);
}

char			*ft_strtrim(char const *s)
{
	char	*a;
	size_t	b;
	size_t	d;

	if (s != NULL)
	{
		b = ft_istrim((char *)s);
		if (b == ft_strlen((char *)s))
			return (ft_strnew(1));
		if (!(d = ft_strlen((char *)s) - b - ft_istrim(ft_strrev((char *)s))))
			return (NULL);
		if (!(a = ft_memalloc(d + 1)))
			return (NULL);
		if (!(ft_strncpy(a, &s[b], d)))
			return (NULL);
		return (a);
	}
	return (NULL);
}
