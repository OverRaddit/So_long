/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gshim <gshim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 13:00:01 by gshim             #+#    #+#             */
/*   Updated: 2021/10/08 00:52:39 by gshim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static int	handle_nl(char **retfd, char **line, int newline)
{
	char	*temp;

	(*retfd)[newline] = '\0';
	temp = *line;
	*line = ft_strdup(*retfd);
	free(temp);
	temp = *retfd;
	*retfd = ft_strdup(*retfd + newline + 1);
	free(temp);
	return (1);
}

static int	handle_eof(char **retfd, char **line)
{
	*line = ft_strjoinfree(*line, *retfd);
	free(*retfd);
	*retfd = 0;
	return (0);
}

static int	handle_fail(char **retfd)
{
	free(*retfd);
	return (-1);
}

static int	init(int fd, char **retfd, char **line)
{
	if (fd < 0 || fd > OPEN_MAX || !line || BUFFER_SIZE <= 0)
		return (-1);
	if (*retfd == 0)
		*retfd = ft_strdup("");
	if (*retfd == 0)
		return (-1);
	*line = ft_strdup("");
	if (*line == 0)
		return (-1);
	return (1);
}

int	get_next_line(int fd, char **line)
{
	static char	*ret[OPEN_MAX];
	char		buf[BUFFER_SIZE + 1];
	int			newline;
	int			readsize;

	if (init(fd, &(ret[fd]), line) == -1)
		return (-1);
	readsize = read(fd, buf, BUFFER_SIZE);
	while (readsize > 0)
	{
		buf[readsize] = '\0';
		ret[fd] = ft_strjoinfree(ret[fd], buf);
		newline = my_strchr(ret[fd]);
		if (newline != -1)
			return (handle_nl(&ret[fd], line, newline));
		readsize = read(fd, buf, BUFFER_SIZE);
	}
	if (readsize == -1)
		return (handle_fail(&ret[fd]));
	newline = my_strchr(ret[fd]);
	if (newline != -1)
		return (handle_nl(&ret[fd], line, newline));
	return (handle_eof(&ret[fd], line));
}
