/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vietnguy <vietnguy@student.42singapore.sg  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/20 18:58:03 by vietnguy          #+#    #+#             */
/*   Updated: 2023/09/24 15:19:10 by vietnguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	unsigned char	*v;

	if (nmemb == 0 || size == 0)
		return (NULL);
	v = (unsigned char *)malloc(nmemb * size);
	if (v == NULL)
		return (NULL);
	ft_bzero(v, nmemb * size);
	return (v);
}
