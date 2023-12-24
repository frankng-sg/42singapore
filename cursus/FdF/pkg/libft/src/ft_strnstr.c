/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vietnguy <vietnguy@student.42singapore.sg  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/04 20:38:45 by vietnguy          #+#    #+#             */
/*   Updated: 2023/09/24 15:00:27 by vietnguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	blen;
	size_t	llen;

	llen = ft_strlen(little);
	if (llen <= 0)
		return ((char *)big);
	blen = ft_min_sizet(ft_strlen(big), len);
	if (blen < llen)
		return (NULL);
	blen = blen - llen + 1;
	i = 0;
	while (i < blen)
	{
		if (big[i] == little[0] && ft_strncmp(&big[i], little, llen) == 0)
			return ((char *)&big[i]);
		i++;
	}
	return (NULL);
}
