/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vietnguy <vietnguy@student.42singapore.sg  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/20 19:11:29 by vietnguy          #+#    #+#             */
/*   Updated: 2023/09/24 14:36:43 by vietnguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strndup(const char *s, size_t n)
{
	char	*dup;

	if (s == NULL || n <= 0)
		return (NULL);
	n = ft_min_sizet(ft_strlen(s), n);
	dup = (char *)malloc((n + 1) * sizeof(char));
	ft_strlcpy(dup, s, n + 1);
	return (dup);
}
