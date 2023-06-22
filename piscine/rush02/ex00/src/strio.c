/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strio.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vietnguy <vietnguy@student.42singapore.sg  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/08 09:00:46 by vietnguy          #+#    #+#             */
/*   Updated: 2023/07/08 14:51:18 by vietnguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"
#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	while (*str != 0)
	{
		ft_putchar(*str);
		str++;
	}
}

void	ft_putstrs(char **strs)
{
	int	i;

	i = 0;
	while (*strs != 0)
	{
		ft_putstr(*strs);
		ft_putstr("\n");
		strs++;
		i++;
	}
}

void	ft_put_pos_nbr(int nbr)
{
	if (nbr > 9)
		ft_put_pos_nbr(nbr / 10);
	ft_putchar((nbr % 10) + '0');
}

void	ft_putnbr(int nbr)
{
	long	n;

	n = (long)nbr;
	if (n < 0)
	{
		ft_putchar('-');
		n = -n;
	}
	ft_put_pos_nbr(n);
}
