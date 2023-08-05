/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcosta-d < tcosta-d@student.42porto.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/05 18:22:33 by tcosta-d          #+#    #+#             */
/*   Updated: 2023/08/05 18:37:16 by tcosta-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*reader(char *st_line, int fd)
{
	char	*buffer;
	int		bytes_read;

	buffer = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (NULL);
	bytes_read = 1;
	while (!ft_strchr(st_line, '\n') && bytes_read != 0)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read == -1)
		{
			free(buffer);
			free(st_line);
			return (NULL);
		}
		buffer[bytes_read] = '\0';
		st_line = ft_strjoin(st_line, buffer);
	}
	free(buffer);
	return (st_line);
}

char	*obtain_line(char *st_line)
{
	char	*line;
	int		i;

	i = 0;
	if (*st_line == '\0')
		return (NULL);
	while (st_line[i] != '\n' && st_line[i] != '\0')
		i++;
	line = (char *)malloc((i + 2) * sizeof(char));
	if (!line)
		return (NULL);
	i = 0;
	while (st_line[i] != '\n' && st_line[i] != '\0')
	{
		line[i] = st_line[i];
		i++;
	}
	if (st_line[i] == '\n')
		line[i++] = '\n';
	line[i] = '\0';
	return (line);
}

char	*trim(char *st_line)
{
	char	*tmp;
	int		i;
	int		j;

	i = 0;
	while (st_line[i] != '\n' && st_line[i] != '\0')
		i++;
	if (st_line[i] == '\0')
	{
		free(st_line);
		return (NULL);
	}
	tmp = (char *)malloc((ft_strlen(st_line) - i + 1) * sizeof(char));
	if (!tmp)
		return (NULL);
	i++;
	j = 0;
	while (st_line[i] != '\0')
		tmp[j++] = st_line[i++];
	tmp[j] = '\0';
	free(st_line);
	return (tmp);
}

char	*get_next_line(int fd)
{
	static char	*st_line[1024];
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	st_line[fd] = reader(st_line[fd], fd);
	if (!st_line[fd])
		return (NULL);
	line = obtain_line(st_line[fd]);
	st_line[fd] = trim(st_line[fd]);
	return (line);
}
