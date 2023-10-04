/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vietnguy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 12:30:36 by vietnguy          #+#    #+#             */
/*   Updated: 2023/10/04 00:57:08 by vietnguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdint.h>

int	ft_putchar(char c);
int	ft_putstr(char *str);
int	ft_puthex(size_t num, int isupper);
int	ft_putptr(uintptr_t ptr);
int	ft_putnbr(long num);
int	ft_printf(const char *fmt, ...);

#endif
