/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vietnguy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 11:37:52 by vietnguy          #+#    #+#             */
/*   Updated: 2023/10/08 08:14:41 by vietnguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putptr(uintptr_t ptr)
{
	if (ptr == 0)
	{
		ft_putstr("(nil)");
		return (5);
	}
	write(1, "0x", 2);
	return (ft_puthex((size_t)ptr, 0) + 2);
}
//
//#include <stdio.h>
//
//int	main(void)
//{
//	char	*t = "test";
//	char	*null = NULL;
//
//	ft_putstr("\nActual  :");
//	ft_putptr((uintptr_t)t);
//	printf("\nExpected:%p\n", t);
//
//	ft_putstr("\nActual  :");
//	ft_putptr((uintptr_t)null);
//	printf("\nExpected:%p\n", null);
//
//}
