/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcosta-d < tcosta-d@student.42porto.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/05 18:22:35 by tcosta-d          #+#    #+#             */
/*   Updated: 2023/08/05 18:33:04 by tcosta-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include <stdlib.h>
# include <unistd.h>

char	*get_next_line(int fd);
char	*reader(char *st_line, int fd);
char	*obtain_line(char *st_line);
char	*trim(char *st_line);
size_t	ft_strlen(const char *s);
char	*ft_strchr(const char *str, int c);
char	*ft_strjoin(char *s1, char const *s2);

#endif
