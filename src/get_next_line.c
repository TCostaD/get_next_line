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
	static t_list	*stash = NULL;
	char			*line;
	int				len;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, &stash, 0) < 0)
		return (NULL);
	stash = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!stash)
		return (NULL);
	if (read(fd, stash, BUFFER_SIZE) == 0) 
		return (NULL);
	return (stash);
}
