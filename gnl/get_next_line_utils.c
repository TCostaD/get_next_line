/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcosta-d < tcosta-d@student.42porto.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 18:17:48 by tcosta-d          #+#    #+#             */
/*   Updated: 2023/08/05 16:16:56 by tcosta-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
		i++;
	return (i);
}

char	*ft_strchr(const char *s, int c)
{
	size_t	i;
	char	*ptr;

	i = 0;
	if (!s)
		return (NULL);
	ptr = (char *)s;
	if ((char)c == '\0')
		return ((char *)&ptr[ft_strlen(s)]);
	while (ptr[i] != '\0')
	{
		if (ptr[i] == (char)c)
			return ((char *)&ptr[i]);
		i++;
	}
	return (NULL);
}

char	*ft_strjoin(char *s1, char const *s2)
{
	int		i;
	int		j;
	char	*end;

	i = -1;
	j = -1;
	if (!s1)
	{
		s1 = (char *)malloc(sizeof(char));
		s1[0] = '\0';
	}
	end = (char *) malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (end == NULL)
		return (NULL);
	while (s1[++i] != '\0')
		end[i] = s1[i];
	while (s2[++j] != '\0')
		end[i + j] = s2[j];
	end[i + j] = '\0';
	return (end);
}
