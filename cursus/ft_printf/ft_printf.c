/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vietnguy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 12:34:07 by vietnguy          #+#    #+#             */
/*   Updated: 2023/10/08 08:17:36 by vietnguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	print_arg(va_list vl, const char fmt)
{
	int	nchars;

	nchars = 0;
	if (fmt == 'c')
		nchars += ft_putchar(va_arg(vl, int));
	else if (fmt == 's')
		nchars += ft_putstr(va_arg(vl, char *));
	else if (fmt == 'p')
		nchars += ft_putptr(va_arg(vl, uintptr_t));
	else if (fmt == 'd' || fmt == 'i')
		nchars += ft_putnbr((long)va_arg(vl, int));
	else if (fmt == 'u')
		nchars += ft_putnbr((long)va_arg(vl, unsigned int));
	else if (fmt == 'x')
		nchars += ft_puthex((size_t)va_arg(vl, unsigned int), 0);
	else if (fmt == 'X')
		nchars += ft_puthex((size_t)va_arg(vl, unsigned int), 1);
	else if (fmt == '%')
		nchars += ft_putchar('%');
	return (nchars);
}

int	ft_printf(const char *fmt, ...)
{
	int		i;
	va_list	vl;
	int		nchars;

	i = 0;
	nchars = 0;
	va_start(vl, fmt);
	while (fmt[i])
	{
		if (fmt[i] == '%')
		{
			nchars += print_arg(vl, fmt[i + 1]);
			i++;
		}
		else
			nchars += ft_putchar(fmt[i]);
		i++;
	}
	va_end(vl);
	return (nchars);
}
//#include <stdio.h>
//
//int	main(void)
//{
//	char	*str = "Hello";
//	char	*null = NULL;
//
//	ft_printf("\nTEST %%c\n");
//	printf("Actual:%d\n", ft_printf("%c\n", 65));
//	printf("Expected:%d\n", printf("%c\n", 65));
//
//	ft_printf("\nTEST %%s\n");
//	printf("Actual:%d\n", ft_printf("%s\n", str));
//	printf("Expected:%d\n", printf("%s\n", str));
//
//	ft_printf("\nTEST %%p\n");
//	printf("Actual:%d\n", ft_printf("%p\n", str));
//	printf("Expected:%d\n", printf("%p\n", str));
//
//	ft_printf("\nTEST %%p\n");
//	printf("Actual:%d\n", ft_printf("%p\n", null));
//	printf("Expected:%d\n", printf("%p\n", null));
//
//
//	ft_printf("\nTEST %%d\n");
//	printf("Actual:%d\n", ft_printf("%d\n", -9876));
//	printf("Expected:%d\n", printf("%d\n", -9876));
//
//	ft_printf("\nTEST %%i\n");
//	printf("Actual:%d\n", ft_printf("%i\n", -9876));
//	printf("Expected:%d\n", printf("%i\n", -9876));
//
//	ft_printf("\nTEST %%u\n");
//	printf("Actual:%d\n", ft_printf("%u\n", -9876));
//	printf("Expected:%d\n", printf("%u\n", -9876));
//
//	ft_printf("\nTEST %%x\n");
//	printf("Actual:%d\n", ft_printf("%x\n", -9876));
//	printf("Expected:%d\n", printf("%x\n", -9876));
//
//	ft_printf("\nTEST %%X\n");
//	printf("Actual:%d\n", ft_printf("%X\n", -9876));
//	printf("Expected:%d\n", printf("%X\n", -9876));
//
//	ft_printf("\nTEST %%%%\n");
//	printf("Actual:%d\n", ft_printf("%%\n"));
//	printf("Expected:%d\n", printf("%%\n"));
//
//
//}
//
