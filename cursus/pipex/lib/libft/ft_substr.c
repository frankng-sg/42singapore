/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vietnguy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 19:52:01 by vietnguy          #+#    #+#             */
/*   Updated: 2023/09/24 14:51:13 by vietnguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	size_t	slen;
	size_t	sublen;
	char	*substr;
	char	*ptr;

	slen = ft_strlen(s);
	if (start >= slen)
		sublen = 0;
	else
		sublen = ft_min_uint(slen - start, len);
	substr = (char *)malloc((sublen + 1) * sizeof(char));
	if (substr == NULL)
		return (NULL);
	ptr = substr;
	s += start;
	while (sublen--)
		*ptr++ = *s++;
	*ptr = 0;
	return (substr);
}
