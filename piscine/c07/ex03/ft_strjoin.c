/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vietnguy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 18:36:15 by vietnguy          #+#    #+#             */
/*   Updated: 2023/06/30 15:49:42 by vietnguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

unsigned long	ft_strlen(char *str)
{
	unsigned long	len;

	len = 0;
	while (*str != 0)
	{
		len++;
		str++;
	}
	return (len);
}

unsigned long	ft_arrsize(int size, char **strs, char *sep)
{
	int				i;
	unsigned long	slen;

	i = 0;
	slen = 0;
	while (i < size)
	{
		slen += ft_strlen(strs[i]);
		i++;
	}
	slen += (size - 1) * ft_strlen(sep) + 1;
	return (slen);
}	

char	*ft_strcpy(char *dest, char *src)
{
	*dest = 0;
	while (*src != 0)
	{
		*dest = *src;
		dest++;
		src++;
	}
	return (dest);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	int				i;
	char			*buf;
	char			*bufaddr;
	unsigned long	slen;

	if (size <= 0)
	{
		buf = (char *)malloc(1);
		*buf = 0;
		return (buf);
	}
	slen = ft_arrsize(size, strs, sep);
	buf = (char *)malloc(slen * sizeof(char));
	bufaddr = buf;
	i = 0;
	while (i < size)
	{
		buf = ft_strcpy(buf, strs[i]);
		if (i < size - 1)
			buf = ft_strcpy(buf, sep);
		i++;
	}
	*buf = 0;
	return (bufaddr);
}
