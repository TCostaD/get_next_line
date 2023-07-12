/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcosta-d < tcosta-d@student.42porto.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 18:17:51 by tcosta-d          #+#    #+#             */
/*   Updated: 2023/07/12 17:11:35 by tcosta-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/get_next_line.h"

char	*get_next_line(int fd)
{
	static char 	*line;

	if (fd <0 || BUFFER_SIZE <= 0 || read(fd, &line, 0) < 0)
		return NULL;
	line = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!line)
		return NULL;
	// verificar se o fd passado tem conteúdo
	if (read(fd, line, BUFFER_SIZE) == 0) 
		return NULL;
	// buffer[BUFFER_SIZE + 1] = 0;
	return (line);
}
