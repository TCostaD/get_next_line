/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcosta-d < tcosta-d@student.42porto.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 17:40:21 by tcosta-d          #+#    #+#             */
/*   Updated: 2023/06/22 19:00:57 by tcosta-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/get_next_line.h"
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main (void)
{
	char *file;
	char *str;
	file = "text2.txt";
	int fd;

	fd = open(file, O_RDONLY);
	//printf("%d\n", fd);
	//printf("%s\n", get_next_line(fd));

	// while(1)
	// {
		str = get_next_line(fd);
		// if (str == NULL)
		// 	break;
		// int i = 0;
		// while(str[i])
		// 	printf("%c\n", str[i++]);
		printf("%s", str);
		//free(str);
	// }
	
	close(fd);
	return (0);
}