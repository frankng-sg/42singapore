/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vietnguy <vietnguy@student.42singapore.sg  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/20 15:27:56 by vietnguy          #+#    #+#             */
/*   Updated: 2023/09/28 20:04:26 by vietnguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*d;
	unsigned char	*s;

	if (dest < src)
		return (ft_memcpy(dest, src, n));
	if (dest > src)
	{
		d = (unsigned char *)dest;
		s = (unsigned char *)src;
		while (n-- > 0)
			d[n] = s[n];
	}
	return (dest);
}
