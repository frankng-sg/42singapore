/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strutil.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vietnguy <vietnguy@student.42singapore.sg  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/08 09:16:29 by vietnguy          #+#    #+#             */
/*   Updated: 2023/07/08 14:13:07 by vietnguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

void	ft_strcpy(char *dest, char *src)
{
	while (*src != 0)
		*dest++ = *src++;
	*dest = 0;
}

void	ft_strcpylr(char *dest, char *src, int l, int r)
{
	while (l < r)
	{
		*dest = src[l];
		l++;
		dest++;
	}
	*dest = 0;
}

int	ft_strlen(char *str)
{
	int	len;

	len = 0;
	while (*str++ != 0)
		len++;
	return (len);
}

int	ft_strslen(char **strs)
{
	int	len;

	len = 0;
	while (*strs++ != 0)
		len++;
	return (len);
}

int	ft_printable(char c)
{
	return (c >= ' ' && c <= '~');
}
