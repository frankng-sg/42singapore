/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vietnguy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 19:52:43 by vietnguy          #+#    #+#             */
/*   Updated: 2023/09/24 15:25:32 by vietnguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		s1len;
	int		s2len;
	char	*s;
	char	*p;

	s1len = ft_strlen(s1);
	s2len = ft_strlen(s2);
	s = (char *)malloc((s1len + s2len + 1) * sizeof(char));
	if (s == NULL)
		return (NULL);
	p = s;
	while (*s1)
		*p++ = *s1++;
	while (*s2)
		*p++ = *s2++;
	*p = 0;
	return (s);
}
