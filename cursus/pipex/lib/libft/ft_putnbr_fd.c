/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vietnguy <vietnguy@student.42singapore.sg  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 11:00:12 by vietnguy          #+#    #+#             */
/*   Updated: 2023/09/28 15:27:14 by vietnguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static void	putnbr_fd(long num, int fd)
{
	if (num < 10)
	{
		ft_putchar_fd(num + '0', fd);
		return ;
	}
	putnbr_fd(num / 10, fd);
	ft_putchar_fd((num % 10) + '0', fd);
}

void	ft_putnbr_fd(int n, int fd)
{
	long	num;

	num = (long)n;
	if (num < 0)
	{
		ft_putchar_fd('-', fd);
		num = -num;
	}
	putnbr_fd(num, fd);
}
