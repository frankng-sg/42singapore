/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vietnguy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 21:23:49 by vietnguy          #+#    #+#             */
/*   Updated: 2023/10/04 14:26:01 by vietnguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_strdup(char *s)
{
	char	*out;
	char	*p;

	if (s == NULL)
		return (NULL);
	out = (char *)malloc(ft_strlen(s) + 1);
	if (out == NULL)
		return (NULL);
	p = out;
	while (*s)
		*p++ = *s++;
	*p = *s;
	return (out);
}

char	*ft_strchr(char *s, char c)
{
	if (s == NULL)
		return (NULL);
	if (c == 0)
		return (s);
	while (*s && *s != c)
		s++;
	if (*s == 0)
		return (NULL);
	return (s);
}

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

char	*ft_substr(char *s, size_t start, size_t n)
{
	size_t	slen;
	char	*out;
	size_t	i;

	if (s == NULL)
		return (NULL);
	slen = ft_strlen(&s[start]);
	if (slen > n)
		slen = n;
	out = (char *)malloc(slen + 1);
	if (out == NULL)
		return (NULL);
	i = 0;
	while (i < slen)
	{
		out[i] = s[start + i];
		i++;
	}
	out[i] = 0;
	return (out);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*out;
	char	*p;

	if (s1 == NULL)
		return (ft_strdup(s2));
	if (s2 == NULL)
		return (ft_strdup(s1));
	out = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (out == NULL)
		return (NULL);
	p = out;
	while (*s1)
		*p++ = *s1++;
	while (*s2)
		*p++ = *s2++;
	*p = 0;
	return (out);
}
