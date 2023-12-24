/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vietnguy <vietnguy@student.42singapore.sg  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/20 19:11:29 by vietnguy          #+#    #+#             */
/*   Updated: 2023/12/23 09:55:08 by vietnguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_strdup(const char *s)
{
	char	*dup;
	size_t	slen;

	slen = ft_strlen(s);
	dup = (char *)malloc((slen + 1) * sizeof(char));
	if (dup == NULL)
		return (NULL);
	ft_strlcpy(dup, s, slen + 1);
	return (dup);
}

char	*ft_strdup_ignore(const char *s, char ignore)
{
	char	*dup;
	size_t	slen;
	size_t	i;

	slen = ft_strlen(s);
	i = ft_strchr_count(s, ignore);
	dup = (char *)malloc((slen - i + 1) * sizeof(char));
	if (dup == NULL)
		return (NULL);
	i = 0;
	while (*s)
	{
		if (*s != ignore)
		{
			dup[i] = *s;
			i++;
		}
		s++;
	}
	dup[i] = 0;
	return (dup);
}
