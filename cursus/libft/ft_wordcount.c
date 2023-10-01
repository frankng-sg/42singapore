/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wordcount.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vietnguy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/24 11:05:15 by vietnguy          #+#    #+#             */
/*   Updated: 2023/09/27 23:21:33 by vietnguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_wordcount(const char *s, const char c)
{
	char	sep[2];

	sep[0] = c;
	sep[1] = 0;
	return (ft_wordcount2(s, (const char *)sep));
}

int	ft_wordcount2(const char *s, const char *sep)
{
	int		issep[255];
	size_t	i;
	size_t	slen;
	size_t	count;

	if (s == NULL || sep == NULL)
		return (0);
	slen = ft_strlen(s);
	if (slen <= 0)
		return (0);
	i = 255;
	while (i > 0)
		issep[i--] = 0;
	while (*sep)
		issep[(int)(*sep++)] = 1;
	count = 0;
	while (++i < slen)
	{
		if (!issep[(int)s[i - 1]] && issep[(int)s[i]])
			count++;
	}
	if (!issep[(int)s[slen - 1]])
		count++;
	return (count);
}
