/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vietnguy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 15:59:14 by vietnguy          #+#    #+#             */
/*   Updated: 2023/06/29 16:16:51 by vietnguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_strlen(char *str)
{
	int	len;

	len = 0;
	while (*str++ != 0)
		len++;
	return (len);
}

char	*ft_strcpy(char *dest, char *src)
{
	char	*destaddr;

	destaddr = dest;
	while (*src != 0)
		*dest++ = *src++;
	*dest = 0;
	return (destaddr);
}

char	*ft_strdup(char *src)
{
	char	*dest;
	int		srclen;

	srclen = ft_strlen(src);
	dest = (char *)malloc(srclen * sizeof(char));
	return (ft_strcpy(dest, src));
}
