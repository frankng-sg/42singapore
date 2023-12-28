/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vietnguy <vietnguy@student.42singapore.sg  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 13:22:34 by vietnguy          #+#    #+#             */
/*   Updated: 2023/09/24 14:05:21 by vietnguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	slen;

	slen = (size_t)ft_strlen(src);
	if (slen + 1 < size)
		ft_memcpy(dst, src, slen + 1);
	else if (size)
	{
		ft_memcpy(dst, src, size);
		dst[size - 1] = 0;
	}
	return (slen);
}
