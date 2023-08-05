/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcosta-d < tcosta-d@student.42porto.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 18:17:51 by tcosta-d          #+#    #+#             */
/*   Updated: 2023/08/03 17:34:57 by tcosta-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*st_line;
	char		*line;
	
	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, &st_line, 0) < 0
		return (0);
	st_line = reader(st_line, fd)
	if (!st_line)
		return (NULL);
	line = get_line(st_line);
	st_line = trim(st_line);
	return (line);
}

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
			return (NULL);
		}
		buffer[bytes_read] = '\0';
		st_line = ft_strjoin(st_line, buffer);
	}
	free(buffer);
	return (st_line);
}

char	*get_line(char *st_line)
{
	char	*line;
	int		i;

	i = 0;
	if (st_line == '\0')
		return (NULL);
	while (st_line[i] != '\n' && st_line[i] != '\0')
		i++;
	line = (char *)malloc((i + 1) * sizeof(char));
	if (!line)
		return (NULL);
	i = 0;
	while (st_line[i] != '\n' && st_line[i] != '\0')
	{
		line[i] = st_line[i];
		i++;
	}
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
