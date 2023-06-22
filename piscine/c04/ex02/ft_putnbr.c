/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vietnguy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 18:46:43 by vietnguy          #+#    #+#             */
/*   Updated: 2023/06/28 19:57:10 by vietnguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <limits.h>

void	ft_putstr(char *str)
{
	while (*str != 0)
		write(1, str++, 1);
}

char	*ft_revstr(char *str, int left, int right)
{
	char	tmp;

	while (left < right)
	{
		tmp = str[left];
		str[left] = str[right];
		str[right] = tmp;
		left++;
		right--;
	}
	return (str);
}

char	*ft_utostr(int n, char *str)
{
	int	i;

	i = 0;
	while (n != 0)
	{
		str[i] = n % 10 + '0';
		n /= 10;
		i++;
	}
	str[i] = 0;
	ft_revstr(str, 0, i - 1);
	return (str);
}

void	ft_putnbr(int nb)
{
	char	str[17];
	char	c;

	if (nb == 0)
	{
		write(1, "0", 1);
		return ;
	}
	if (nb < 0)
	{
		c = '-';
		write(1, &c, 1);
	}
	if (nb == INT_MIN)
	{
		ft_putstr(ft_utostr(-(nb / 10), str));
		c = -(nb % 10) + '0';
		write(1, &c, 1);
		return ;
	}
	if (nb < 0)
		ft_putstr(ft_utostr(-nb, str));
	else
		ft_putstr(ft_utostr(nb, str));
}
