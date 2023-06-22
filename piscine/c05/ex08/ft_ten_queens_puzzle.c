/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ten_queens_puzzle.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vietnguy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 10:56:36 by vietnguy          #+#    #+#             */
/*   Updated: 2023/06/29 10:56:38 by vietnguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print(int *pos, int size)
{
	char	c;

	while (size > 0)
	{
		c = (char)(*pos + '0');
		write(1, &c, 1);
		pos++;
		size--;
	}
	write(1, "\n", 1);
}

int	ft_abs(int n)
{
	if (n < 0)
		return (-n);
	return (n);
}

int	is_attacked(int *pos, int n)
{
	int	i;

	i = 0;
	while (i < n)
	{
		if (pos[i] == pos[n])
			return (1);
		if (ft_abs(i - n) == ft_abs(pos[i] - pos[n]))
			return (1);
		i++;
	}
	return (0);
}

int	try(int *pos, int n, int size)
{
	int	i;
	int	count;

	count = 0;
	if (n >= size)
	{
		ft_print(pos, size);
		return (1);
	}
	i = 0;
	while (i < size)
	{
		pos[n] = i;
		if (!is_attacked(pos, n))
			count += try(pos, n + 1, size);
		i++;
	}
	return (count);
}

int	ft_ten_queens_puzzle(void)
{
	int	pos[10];

	return (try(pos, 0, 10));
}
