/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vietnguy <vietnguy@student.42singapore.sg  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/20 11:34:58 by vietnguy          #+#    #+#             */
/*   Updated: 2023/09/24 14:23:12 by vietnguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*v1;
	unsigned char	*v2;

	if (n <= 0)
		return (0);
	v1 = (unsigned char *)s1;
	v2 = (unsigned char *)s2;
	while (n-- > 0 && *v1 == *v2)
	{
		v1++;
		v2++;
	}
	return (*v1 - *v2);
}
