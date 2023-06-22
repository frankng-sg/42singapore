/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush00.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: latang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/25 12:28:50 by latang            #+#    #+#             */
/*   Updated: 2023/06/25 19:56:41 by vietnguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c);

void	rush(int width, int height)
{
	int	c;
	int	r;

	if (width < 1 || height < 1)
		return ;
	r = 1;
	while (r <= height)
	{
		c = 1;
		while (c <= width)
		{
			if ((c == 1 || c == width) && (r == 1 || r == height))
				ft_putchar('o');
			else if (c == 1 || c == width)
				ft_putchar('|');
			else if (r == 1 || r == height)
				ft_putchar('-');
			else
				ft_putchar(' ');
			c++;
		}
		ft_putchar('\n');
		r++;
	}
}
