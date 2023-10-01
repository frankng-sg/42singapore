/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vietnguy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 15:29:54 by vietnguy          #+#    #+#             */
/*   Updated: 2023/10/01 16:38:17 by vietnguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(char *s)
{
	size_t	len;

	if (s == NULL)
		return (0);
	len = 0;
	while (*s++)
		len++;
	return (len);
}

char	*ft_strchr(char *s, int c)
{
	while (*s)
	{
		if (*s == (char)c)
			return ((char *)s);
		s++;
	}
	return (NULL);
}

char	*ft_strjoin(char *line, char *buff)
{
	size_t	i;
	size_t	j;
	char	*str;

	if (!line)
	{
		line = (char *)malloc(1 * sizeof(char));
		line[0] = '\0';
	}
	if (!line || !buff)
		return (NULL);
	str = malloc(sizeof(char) * ((ft_strlen(line) + ft_strlen(buff)) + 1));
	if (str == NULL)
		return (NULL);
	i = -1;
	j = 0;
	if (line)
		while (line[++i] != '\0')
			str[i] = line[i];
	while (buff[j] != '\0')
		str[i++] = buff[j++];
	str[ft_strlen(line) + ft_strlen(buff)] = '\0';
	free(line);
	return (str);
}

char	*ft_strdup(char *s)
{
	char	*dup;
	size_t	slen;
	size_t	i;

	slen = ft_strlen(s);
	dup = (char *)malloc((slen + 1));
	if (dup == NULL)
		return (NULL);
	dup[slen] = 0;
	i = 0;
	while (i < slen)
	{
		dup[i] = s[i];
		i++;
	}
	return (dup);
}
