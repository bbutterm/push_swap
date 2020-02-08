/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarti <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/25 19:50:33 by mmarti            #+#    #+#             */
/*   Updated: 2019/05/06 17:31:25 by mmarti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	ft_get_line(char **fd_lines, char **line)
{
	char	*tmp;
	int		i;

	i = 0;
	tmp = *fd_lines;
	while (tmp[i] != '\n')
	{
		if (!tmp[i++])
			return (0);
	}
	tmp[i] = 0;
	*line = ft_strdup(*fd_lines);
	*fd_lines = ft_strdup(&tmp[i + 1]);
	free(tmp);
	tmp = 0;
	return (1);
}

static int	ft_readline(int fd, char **fd_lines, char *buf, char **line)
{
	char *tmp;

	while (read(fd, buf, BUFF_SIZE))
	{
		if (!*fd_lines)
			*fd_lines = ft_strdup(buf);
		else if (*fd_lines)
		{
			tmp = *fd_lines;
			*fd_lines = ft_strjoin(*fd_lines, buf);
			free(tmp);
		}
		if ((ft_get_line(fd_lines, line)) == 1)
			return (1);
		ft_bzero(buf, BUFF_SIZE);
	}
	if (*fd_lines && *fd_lines[0] != 0 && ft_strchr(*fd_lines, '\n') == 0)
	{
		*line = ft_strdup(*fd_lines);
		free(*fd_lines);
		*fd_lines = 0;
		return (1);
	}
	return (0);
}

int			get_next_line(const int fd, char **line)
{
	static char	*fd_lines[MAX_FD];
	char		buf[BUFF_SIZE + 1];
	int			ret;

	if (fd < 0 || fd >= MAX_FD || BUFF_SIZE <= 0)
		return (-1);
	ft_bzero(buf, BUFF_SIZE + 1);
	if (read(fd, buf, 0) < 0)
		return (-1);
	if (fd_lines[fd] && ft_strchr(fd_lines[fd], '\n'))
		return (ft_get_line(&fd_lines[fd], line));
	ret = ft_readline(fd, &fd_lines[fd], buf, line);
	return (ret);
}
