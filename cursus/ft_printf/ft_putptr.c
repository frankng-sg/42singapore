/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vietnguy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 11:37:52 by vietnguy          #+#    #+#             */
/*   Updated: 2023/10/01 13:06:07 by vietnguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putptr(uintptr_t ptr)
{
	write(1, "0x", 2);
	return (ft_puthex((size_t)ptr, 0) + 2);
}

//#include <stdio.h>
//
//int	main(void)
//{
//	char	*t = "test";
//
//	ft_putstr("\nActual  :");
//	ft_putptr((uintptr_t)t);
//	printf("\nExpected:%p\n", t);
//}
