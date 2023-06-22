/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush01.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: latang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/25 12:28:56 by latang            #+#    #+#             */
/*   Updated: 2023/06/25 20:06:32 by vietnguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c);

void	ft_printcell(int width, int height, int c, int r)
{
	if (c == 1 && r == 1)
		ft_putchar('/');
	else if (c == width && r == 1)
		ft_putchar('\\');
	else if (c == 1 && r == height)
		ft_putchar('\\');
	else if (c == width && r == height)
		ft_putchar('/');
	else if (c == 1 || c == width)
		ft_putchar('*');
	else if (r == 1 || r == height)
		ft_putchar('*');
	else
		ft_putchar(' ');
}

void	rush(int width, int height)
{
	int		r;
	int		c;

	r = 1;
	if (width < 1 || height < 1)
		return ;
	while (r <= height)
	{
		c = 1;
		while (c <= width)
		{
			ft_printcell(width, height, c, r);
			c++;
		}
		ft_putchar('\n');
		r++;
	}
}
