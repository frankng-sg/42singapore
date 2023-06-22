/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vietnguy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/24 10:49:02 by vietnguy          #+#    #+#             */
/*   Updated: 2023/09/27 23:28:45 by vietnguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	**malloc_error(char **tab)
{
	unsigned int	i;

	i = 0;
	while (tab[i])
		free(tab[i++]);
	free(tab);
	return (NULL);
}

static char	*getword(const char *s, char c, size_t *loc)
{
	size_t	start;

	start = *loc;
	while (s[start] == c)
		start++;
	*loc = start;
	while (s[*loc] && s[*loc] != c)
		*loc += 1;
	return (ft_substr(s, start, *loc - start));
}

char	**ft_split(const char *s, char c)
{
	char	**out;
	size_t	nwords;
	size_t	i;
	size_t	loc;

	if (s == NULL)
		return (NULL);
	nwords = ft_wordcount(s, c);
	out = (char **)malloc((nwords + 1) * sizeof(char *));
	if (out == NULL)
		return (NULL);
	i = 0;
	loc = 0;
	while (i < nwords)
	{
		out[i] = getword(s, c, &loc);
		if (out[i] == NULL)
			return (malloc_error(out));
		i++;
	}
	out[i] = 0;
	return (out);
}
