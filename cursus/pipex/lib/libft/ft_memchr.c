/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vietnguy <vietnguy@student.42singapore.sg  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/20 14:59:03 by vietnguy          #+#    #+#             */
/*   Updated: 2023/08/20 15:16:46 by vietnguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*v;
	unsigned char	key;

	if (n == 0)
		return (NULL);
	v = (unsigned char *)s;
	key = (unsigned char)c;
	while (--n > 0 && *v != key)
	{
		v++;
	}
	if (*v == key)
	{
		return (v);
	}
	return (NULL);
}
