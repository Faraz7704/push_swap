/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkhan <fkhan@student.42abudhabi.ae>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 17:06:22 by fkhan             #+#    #+#             */
/*   Updated: 2022/09/13 23:25:23 by fkhan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_savebuff(char *buffer)
{
	int		len;
	int		linelen;
	char	*newbuff;

	linelen = strlen_sep(buffer, '\n');
	len = strlen_sep(buffer, '\0') - linelen;
	if (len <= 0 || !buffer[0])
	{
		free(buffer);
		return (0);
	}
	newbuff = malloc(sizeof(char) * (len + 1));
	if (!newbuff)
		return (0);
	strlcpy_sep(newbuff, &buffer[linelen + 1], len, '\0');
	if (!newbuff[0])
	{
		free(newbuff);
		newbuff = NULL;
	}
	free(buffer);
	return (newbuff);
}

char	*ft_readline(int fd, char *buffer)
{
	char	*localbuff;
	char	*newbuff;
	int		result;

	localbuff = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!localbuff)
		return (0);
	localbuff[0] = '\0';
	result = 1;
	while (result != 0 && !ft_strchr(localbuff, '\n'))
	{
		result = read(fd, localbuff, BUFFER_SIZE);
		if (result < 0)
			break ;
		localbuff[result] = '\0';
		newbuff = gnl_strjoin(buffer, localbuff);
		free(buffer);
		buffer = newbuff;
	}
	free(localbuff);
	return (buffer);
}

char	*get_next_line(int fd)
{
	static char	*buffer[MAX_FD];
	char		*line;

	if (fd < 0 || fd >= MAX_FD || BUFFER_SIZE <= 0)
		return (0);
	buffer[fd] = ft_readline(fd, buffer[fd]);
	if (!buffer[fd])
		return (0);
	line = strdup_sep(buffer[fd], '\n');
	buffer[fd] = ft_savebuff(buffer[fd]);
	return (line);
}
