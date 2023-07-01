/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcosta-d < tcosta-d@student.42porto.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 18:17:51 by tcosta-d          #+#    #+#             */
/*   Updated: 2023/06/22 19:02:48 by tcosta-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/get_next_line.h"

char	*get_next_line(int fd)
{
	static char 	*buffer;

	if (fd <0 || BUFFER_SIZE <= 0 || read(fd, &buffer, 0) < 0)
		return NULL;
	buffer = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return NULL;
	// verificar se o fd passado tem conteúdo
	if (read(fd, buffer, BUFFER_SIZE) == 0) 
		return NULL;
	// buffer[BUFFER_SIZE + 1] = 0;
	return buffer;
}
