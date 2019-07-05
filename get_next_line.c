/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnaidoo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/27 16:06:10 by jnaidoo           #+#    #+#             */
/*   Updated: 2019/07/05 13:06:40 by jnaidoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	ft_store_line(int fd, char **a, char **line)
{
	char	*b;
	int		c;

	c = 0;
	while (a[fd][c] != '\n' && a[fd][c] != '\0')
		c++;
	if (a[fd][c] == '\n')
	{
		*line = ft_strsub(a[fd], 0, c);
		b = ft_strdup(a[fd] + c + 1);
		free(a[fd]);
		a[fd] = b;
	}
	else if (a[fd][c] == '\0')
	{
		*line = ft_strdup(a[fd]);
		ft_strdel(&a[fd]);
	}
}

int		ft_reader(char **a, int fd)
{
	char	buff[BUFF_SIZE + 1];
	char	*b;
	int		c;

	while ((c = (read(fd, buff, BUFF_SIZE))) > 0)
	{
		if (a[fd] == NULL)
			a[fd] = ft_strnew(1);
		buff[c] = '\0';
		b = ft_strjoin(a[fd], buff);
		free(a[fd]);
		a[fd] = b;
		if (ft_strchr(a[fd], '\n'))
			break ;
	}
	return (c);
}

int		get_next_line(int const fd, char **line)
{
	static char	*a[1024];
	int			c;

	if (fd < 0 || line == NULL)
		return (-1);
	c = ft_reader(a, fd);
	if (c < 0)
		return (-1);
	else if (c == 0 && (a[fd] == NULL || a[fd][0] == '\0'))
		return (0);
	else
		ft_store_line(fd, a, line);
	return (1);
}
