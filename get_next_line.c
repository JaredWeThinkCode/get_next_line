/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnaidoo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/08 18:14:06 by jnaidoo           #+#    #+#             */
/*   Updated: 2019/06/11 12:53:05 by jnaidoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	ft_next_line(char **a, char **line, int fd)
{
	char	*c;
	int		d;

	d = 0;
	while (a[fd][d] != '\n' && a[fd][d] != '\0')
		d++;
	if (a[fd][d] == '\n')
	{
		*line = ft_strsub(a[fd], 0, d);
		c = ft_strdup(a[fd] + d + 1);
		free(a[fd]);
		a[fd] = c;
		if (a[fd][0] == '\0')
			ft_strdel(&a[fd]);
	}
	else if (a[fd][d] == '\0')
	{
		*line = ft_strdup(a[fd]);
		ft_strdel(&a[fd]);
	}
	return (1);
}

int			get_next_line(const int fd, char **line)
{
	static char		*a[100];
	char			buf[BUFF_SIZE + 1];
	char			*b;
	int				c;

	if (fd < 0 || line == NULL)
		return (-1);
	while ((c = read(fd, buf, BUFF_SIZE)) > 0)
	{
		buf[c] = '\0';
		if (a[fd] == NULL)
			a[fd] = ft_strnew(1);
		b = ft_strjoin(a[fd], buf);
		free(a[fd]);
		a[fd] = b;
		if (ft_strchr(buf, '\n'))
			break ;
	}
	if (c < 0)
		return (-1);
	else if (c == 0 && (a[fd] == NULL || a[fd][0] == '\0'))
		return (0);
	return (ft_next_line(a, line, fd));
}
