/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_memory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vietnguy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/25 09:57:45 by vietnguy          #+#    #+#             */
/*   Updated: 2023/06/25 09:57:46 by vietnguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	print_address(unsigned long loc)
{
	const unsigned char	hex[16] = "0123456789abcdef";
	char				buffer[16];
	int					i;

	i = 15;
	while (i >= 0)
	{
		buffer[i] = hex[loc & 0xf];
		loc >>= 4;
		i--;
	}
	write(1, buffer, 16);
}

void	print_mem_hex(unsigned char *loc, unsigned int size)
{
	const unsigned char	hex[16] = "0123456789abcdef";
	unsigned char		num;
	unsigned int		i;
	unsigned int		len;

	i = 0;
	len = 0;
	while (i < size)
	{
		num = *(unsigned char *)(loc + i);
		write(1, &hex[(num >> 4) & 0x0f], 1);
		write(1, &hex[num & 0x0f], 1);
		if (i % 2 == 1)
		{
			write(1, " ", 1);
			len++;
		}
		i++;
		len += 2;
	}
	while (len < 40)
	{
		write(1, " ", 1);
		len++;
	}
}

void	print_mem_chars(unsigned char *loc, unsigned int size)
{
	unsigned int	i;

	i = 0;
	while (i < size)
	{
		if (loc[i] >= ' ' && loc[i] <= '~')
		{
			write(1, &loc[i], 1);
		}
		else
		{
			write(1, ".", 1);
		}
		i++;
	}
}

void	ft_print_memory(void *addr, unsigned int size)
{
	unsigned int	cnt_size;
	unsigned int	len;
	unsigned char	*loc;

	loc = (unsigned char *)addr;
	cnt_size = 0;
	while (cnt_size < size)
	{
		len = size - cnt_size;
		if (len > 16)
			len = 16;
		print_address((unsigned long)loc);
		write(1, ": ", 2);
		print_mem_hex(loc, len);
		print_mem_chars(loc, len);
		write(1, "\n", 1);
		loc += 16;
		cnt_size += 16;
	}
}
