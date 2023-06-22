/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vietnguy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/25 09:57:40 by vietnguy          #+#    #+#             */
/*   Updated: 2023/06/25 21:33:45 by vietnguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	write_hexadecimal(unsigned char c)
{
	const unsigned char	hex[] = "0123456789abcdef";
	unsigned char		str[3];

	str[0] = '\\';
	str[1] = hex[(c >> 4) & 0xf];
	str[2] = hex[c & 0xf];
	write(1, str, 3);
}

void	ft_putstr_non_printable(char *str)
{
	int	i;

	i = 0;
	while (str[i] != 0)
	{
		if (str[i] >= ' ' && str[i] <= '~')
		{
			write(1, &str[i], 1);
		}
		else
		{
			write_hexadecimal((unsigned char)str[i]);
		}
		i++;
	}
}
