/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vietnguy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/25 09:57:33 by vietnguy          #+#    #+#             */
/*   Updated: 2023/06/26 22:42:26 by vietnguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_strlen(char *s)
{
	unsigned int	len;

	len = 0;
	while (*s++ != 0)
		len++;
	return (len);
}

char	*ft_memcpy(char *dest, char *src, unsigned int len)
{
	char	*destaddr;

	destaddr = dest;
	while (len-- > 0)
		*dest++ = *src++;
	return (destaddr);
}

unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size)
{
	const unsigned int	srclen = ft_strlen(src);

	if (srclen + 1 < size)
	{
		ft_memcpy(dest, src, srclen + 1);
	}
	else if (size != 0)
	{
		ft_memcpy(dest, src, size - 1);
		dest[size - 1] = 0;
	}
	return (srclen);
}
