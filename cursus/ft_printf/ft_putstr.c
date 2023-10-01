/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vietnguy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 11:35:43 by vietnguy          #+#    #+#             */
/*   Updated: 2023/10/01 11:59:49 by vietnguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putstr(char *str)
{
	int	nchars;

	if (str == NULL)
	{
		write(1, "(null)", 6);
		return (6);
	}
	nchars = 0;
	while (*str)
	{
		write(1, str++, 1);
		nchars++;
	}
	return (nchars);
}
