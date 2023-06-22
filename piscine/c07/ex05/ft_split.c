/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vietnguy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/02 10:59:38 by vietnguy          #+#    #+#             */
/*   Updated: 2023/07/02 13:26:07 by vietnguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

void	ft_init(char *charset, int *issep, int len)
{
	int	i;

	i = 0;
	while (i < len)
	{
		issep[i] = 0;
		i++;
	}
	while (*charset != 0)
	{
		issep[(int)*charset] = 1;
		charset++;
	}
}

void	ft_strcpy(char *dest, char *src, int start, int end)
{
	while (start < end)
	{
		*dest = src[start];
		dest++;
		start++;
	}
	*dest = 0;
}

void	ft_do_split(char **arr, char *str, int *issep)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (str[j] != 0)
	{
		while (!issep[(int)str[j]] && str[j] != 0)
			j++;
		*arr = (char *)malloc((j - i + 1) * sizeof(char));
		ft_strcpy(*arr, str, i, j);
		while (issep[(int)str[j]] && str[j] != 0)
			j++;
		i = j;
		arr++;
	}
	*arr = 0;
}

int	ft_count_words(char *str, int *issep)
{
	int	nwords;
	int	newword;

	nwords = 0;
	newword = 1;
	while (*str != 0)
	{
		if (newword && !issep[(int)*str])
		{
			nwords++;
			newword = 0;
		}
		else if (issep[(int)*str])
			newword = 1;
		str++;
	}
	return (nwords);
}

char	**ft_split(char *str, char *charset)
{
	int		issep[256];
	int		nwords;
	char	**arr;

	if (str == 0)
		return ((void *)0);
	ft_init(charset, issep, 256);
	while (*str != 0 && issep[(int)*str])
		str++;
	nwords = ft_count_words(str, issep);
	arr = (char **)malloc((nwords + 1) * sizeof(char *));
	if (arr == 0)
		return ((void *)0);
	ft_do_split(arr, str, issep);
	return (arr);
}
/*
int	main(void)
{
	char **t;
	char **x;

	t = ft_split("hello", "");
	x = t;
	while (*t != 0)
	{
		printf("%s\n", *t);
		free(*t);
		t++;
	}
	printf("%p\n", *t);
	free(x);
	return (0);
}
*/
