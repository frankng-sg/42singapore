/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strsplit.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vietnguy <vietnguy@student.42singapore.sg  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/08 09:18:18 by vietnguy          #+#    #+#             */
/*   Updated: 2023/07/08 14:25:30 by vietnguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "rush02.h"

int	issep(char c, char *sep)
{
	while (*sep != 0 && c != *sep)
		sep++;
	return (*sep == c);
}

int	ft_count_words(char *str, char *sep)
{
	int	newword;
	int	count;

	count = 0;
	newword = 1;
	while (*str != 0)
	{
		if (issep(*str, sep))
			newword = 1;
		else if (newword)
		{
			newword = 0;
			count++;
		}
		str++;
	}
	return (count);
}

char	**ft_split(char *str, char *sep)
{
	char	**list;
	int		size;
	int		i;
	int		j;
	int		k;

	size = ft_count_words(str, sep);
	list = (char **)malloc((size + 1) * sizeof(char *));
	i = 0;
	k = 0;
	while (k < size)
	{
		while (issep(str[i], sep))
			i++;
		j = i + 1;
		while (!issep(str[j], sep) && str[j] != 0)
			j++;
		list[k] = (char *)malloc((j - i + 1) * sizeof(char));
		ft_strcpylr(list[k], str, i, j);
		k++;
		i = j + 1;
	}
	list[size] = 0;
	return (list);
}
