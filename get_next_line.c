/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnaidoo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/08 18:14:06 by jnaidoo           #+#    #+#             */
/*   Updated: 2019/06/14 08:21:01 by jnaidoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	ft_next_line(int fd, char **a, char **line)
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
	static char		*a[0];
	char			buff[BUFF_SIZE + 1];
	char			*b;
	int				c;

	if (fd < 0 || line == NULL)
		return (-1);
	if (a[fd] == NULL)
		a[fd] = ft_strnew(1);
	while ((c = read(fd, buff, BUFF_SIZE)) > 0)
	{
		buff[c] = '\0';
		b = ft_strjoin(a[fd], buff);
		free(a[fd]);
		a[fd] = b;
		if (ft_strchr(buff, '\n'))
			break ;
	}
	if (c < 0)
		return (-1);
	else if (c == 0 && a[fd][0] == '\0')
		return (0);
	return (ft_next_line(fd, a, line));
}
