/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush04.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vietnguy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/25 20:37:47 by vietnguy          #+#    #+#             */
/*   Updated: 2023/06/25 20:40:11 by vietnguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_putchar(char c);

void	printcell(int col, int row, int width, int height)
{
	if (col == 1 && row == 1)
		ft_putchar('A');
	else if (col == width && row == 1)
		ft_putchar('C');
	else if (col == width && row == height)
		ft_putchar('A');
	else if (col == 1 && row == height)
		ft_putchar('C');
	else if (row == 1 || row == height)
		ft_putchar('B');
	else if (col == 1 || col == width)
		ft_putchar('B');
	else
		ft_putchar(' ');
}

void	rush(int width, int height)
{
	int	row;
	int	col;

	if (width < 1 || height < 1)
		return ;
	row = 1;
	while (row <= height)
	{
		col = 1;
		while (col <= width)
		{
			printcell(col, row, width, height);
			col++;
		}
		row++;
		ft_putchar('\n');
	}
}
