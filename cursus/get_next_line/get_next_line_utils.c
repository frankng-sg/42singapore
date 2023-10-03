/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vietnguy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 21:23:49 by vietnguy          #+#    #+#             */
/*   Updated: 2023/10/03 14:24:49 by vietnguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strjoin(char *s1, char *s2)
{
	int		s1len;
	int		s2len;
	char	*out;
	char	*ptr;

	if (s1 == NULL && s2 == NULL)
		return (NULL);
	if (s1 == NULL)
		return (ft_strdup(s2));
	if (s2 == NULL)
		return (ft_strdup(s1));
	s1len = ft_strlen(s1);
	s2len = ft_strlen(s2);
	out = (char *)malloc(s1len + s2len + 1);
	if (out == NULL)
		return (NULL);
	ptr = out;
	while (*s1)
		*ptr++ = *s1++;
	while (*s2)
		*ptr++ = *s2++;
	*ptr = 0;
	return (out);
}

char	*ft_strchr(char *s, int c)
{
	if (s == NULL)
		return (NULL);
	if (c == 0)
		return (s);
	while (*s && *s != (char)c)
		s++;
	if (*s == (char)c)
		return ((char *)s);
	return (NULL);
}

char	*ft_substr(char *s, unsigned int start, size_t len)
{
	size_t	slen;
	size_t	sublen;
	char	*substr;
	char	*ptr;

	slen = ft_strlen(s);
	if (start >= slen)
		sublen = 0;
	else if (slen - start < len)
		sublen = slen - start;
	else
		sublen = len;
	substr = (char *)malloc(sublen + 1);
	if (substr == NULL)
		return (NULL);
	ptr = substr;
	s += start;
	while (sublen --)
		*ptr++ = *s++;
	*ptr = 0;
	return (substr);
}

char	*ft_strdup(char *s)
{
	char	*dup;
	char	*addr;
	size_t	slen;

	if (s == NULL)
		return (NULL);
	slen = ft_strlen(s);
	dup = (char *)malloc(slen + 1);
	if (dup == NULL)
		return (NULL);
	addr = dup;
	while (*s)
		*dup++ = *s++;
	*dup = 0;
	return (addr);
}

size_t	ft_strlen(char *s)
{
	size_t	len;

	if (s == NULL)
		return (0);
	len = 0;
	while (*s++ != 0)
		len++;
	return (len);
}
