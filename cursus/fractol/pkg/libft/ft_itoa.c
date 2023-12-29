/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vietnguy <vietnguy@student.42singapore.sg  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 08:26:21 by vietnguy          #+#    #+#             */
/*   Updated: 2023/09/28 09:34:12 by vietnguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <limits.h>
#include <stdio.h>

static int	count_digits(long num)
{
	int	ndigits;

	ndigits = 1;
	if (num < 0)
	{
		ndigits = 2;
		num = -num;
	}
	while (num >= 10)
	{
		num /= 10;
		ndigits++;
	}
	return (ndigits);
}

static void	do_itoa(char *out, long num, int *i)
{
	if (num >= 10)
	{
		do_itoa(out, num / 10, i);
		out[*i] = (num % 10) + '0';
		*i += 1;
		return ;
	}
	out[*i] = num + '0';
	*i += 1;
}

char	*ft_itoa(int n)
{
	int		ndigits;
	int		i;
	long	num;
	char	*out;

	num = (long)n;
	ndigits = count_digits(num);
	out = (char *)malloc((ndigits + 1) * sizeof(char));
	if (out == NULL)
		return (NULL);
	i = 0;
	if (num < 0)
	{
		num = -num;
		out[0] = '-';
		i = 1;
	}
	do_itoa(out, num, &i);
	out[i] = 0;
	return (out);
}
