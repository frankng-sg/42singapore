/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vietnguy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 12:07:24 by vietnguy          #+#    #+#             */
/*   Updated: 2023/12/09 22:30:24 by vietnguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	putnbr(long num)
{
	if (num < 10)
		return (ft_putchar(num + '0'));
	return (putnbr(num / 10) + putnbr(num % 10));
}

int	ft_putnbr(int n)
{
	int		nchars;
	long	num;

	num = (long)n;
	nchars = 0;
	if (num < 0)
	{
		nchars = write(1, "-", 1);
		num = -num;
	}
	return (nchars + putnbr(num));
}
