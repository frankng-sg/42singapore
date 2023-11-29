/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vietnguy <vietnguy@student.42singapore.sg  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/06 23:00:49 by vietnguy          #+#    #+#             */
/*   Updated: 2023/08/07 13:22:25 by vietnguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t maxlen)
{
	size_t	i;
	size_t	dlen;
	size_t	slen;

	dlen = ft_strlen(dst);
	i = dlen;
	slen = ft_strlen(src);
	if (dlen > maxlen)
		dlen = maxlen;
	while (i + 1 < maxlen && *src)
		dst[i++] = *src++;
	dst[i] = 0;
	return (dlen + slen);
}
