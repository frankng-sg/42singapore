/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vietnguy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 20:17:22 by vietnguy          #+#    #+#             */
/*   Updated: 2023/06/28 20:52:23 by vietnguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

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

void	ft_putstr(char *str)
{
	while (*str != 0)
		write(1, str++, 1);
}

char	*ft_ltostr(long num, char *base, int lbase, char *str)
{
	int	i;

	if (num == 0)
	{
		str[0] = base[0];
		str[1] = 0;
		return (str);
	}
	i = 0;
	while (num != 0)
	{
		str[i] = base[num % lbase];
		num /= lbase;
		i++;
	}
	str[i] = 0;
	ft_revstr(str, 0, i - 1);
	return (str);
}

void	ft_putnbr_base(int nbr, char *base)
{
	long	num;
	int		i;
	int		j;
	char	str[1024];

	i = 0;
	while (base[i] != 0)
	{
		j = i + 1;
		while (base[j] != 0)
			if (base[i] == base[j++])
				return ;
		if (base[i] == '-' || base[i] == '+')
			return ;
		i++;
	}
	if (i <= 1)
		return ;
	num = (long)nbr;
	if (nbr < 0)
	{
		num = -num;
		write(1, "-", 1);
	}
	ft_putstr(ft_ltostr(num, base, i, str));
}
