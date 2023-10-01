/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vietnguy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 11:45:25 by vietnguy          #+#    #+#             */
/*   Updated: 2023/10/01 14:38:44 by vietnguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	puthex(size_t num, char hex)
{
	if (num >= 16)
		return (puthex(num / 16, hex) + puthex(num % 16, hex));
	if (num < 10)
		return (ft_putchar(num + '0'));
	return (ft_putchar(num - 10 + hex));
}

int	ft_puthex(size_t num, int isupper)
{
	if (isupper)
		return (puthex(num, 'A'));
	return (puthex(num, 'a'));
}
//#include <stdio.h>
//int	main(void)
//{
//	ft_putstr("Actual:");
//	ft_putHEX(1439111);
//	ft_putchar('\n');
//	printf("Expected:%X\n", 1439111);
//}
