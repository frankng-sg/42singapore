/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush02.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vietnguy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/25 12:28:07 by vietnguy          #+#    #+#             */
/*   Updated: 2023/06/25 20:19:17 by vietnguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

char	get_val(int col, int row, int width, int height)
{
	if (col == 1 && row == 1)
		return ('A');
	if (col == width && row == 1)
		return ('A');
	if (col == 1 && row == height)
		return ('C');
	if (col == width && row == height)
		return ('C');
	if (row == 1 || row == height)
		return ('B');
	if (col == 1 || col == width)
		return ('B');
	return (' ');
}

void	rush(int width, int height)
{
	int		col;
	int		row;
	char	c;

	if (width < 1 || height < 1)
		return ;
	row = 1;
	while (row <= height)
	{
		col = 1;
		while (col <= width)
		{
			c = get_val(col, row, width, height);
			ft_putchar(c);
			col++;
		}
		ft_putchar('\n');
		row++;
	}
}
