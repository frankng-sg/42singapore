/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vietnguy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 13:07:24 by vietnguy          #+#    #+#             */
/*   Updated: 2023/06/25 09:35:36 by vietnguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h> 

void	swap(unsigned char *i, unsigned char *j)
{
	unsigned char	tmp;

	tmp = *i;
	*i = *j;
	*j = tmp;
}

void	print_digits(int n, unsigned char *digit)
{
	int	i;
	int	j;
	int	l;

	i = 0;
	while (n != 0)
	{
		digit[i] = n % 10 + 48;
		n /= 10;
		i++;
	}
	l = i;
	i--;
	j = 0;
	while (j < i)
	{
		swap(&digit[i], &digit[j]);
		i--;
		j++;
	}
	write(1, digit, l);
}

void	ft_putnbr(int nb)
{
	unsigned char	digit[128];

	if (nb == -2147483648)
	{
		write(1, "-2147483648", 11);
		return ;
	}
	if (nb == 0)
	{
		write(1, "0", 1);
		return ;
	}
	if (nb < 0)
	{
		write(1, "-", 1);
		nb = -nb;
	}
	print_digits(nb, digit);
}
