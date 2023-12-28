/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vietnguy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 12:34:07 by vietnguy          #+#    #+#             */
/*   Updated: 2023/12/09 22:27:55 by vietnguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
