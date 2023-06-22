/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_views.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vietnguy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/01 18:20:02 by vietnguy          #+#    #+#             */
/*   Updated: 2023/07/01 19:31:40 by vietnguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "helpers.h"

int	ft_count_left_views(int row, t_boardstat *s)
{
	int	count;
	int	col;
	int	max;

	count = 0;
	max = 0;
	col = 1;
	while (col <= s->size)
	{
		if (s->mat[row][col] == 0)
			break ;
		if (max < s->mat[row][col])
		{
			count++;
			max = s->mat[row][col];
		}
		col++;
	}
	return (count);
}

int	ft_count_right_views(int row, t_boardstat *s)
{
	int	count;
	int	col;
	int	max;

	count = 0;
	max = 0;
	col = s->size;
	while (col >= 1)
	{
		if (s->mat[row][col] == 0)
			break ;
		if (max < s->mat[row][col])
		{
			count++;
			max = s->mat[row][col];
		}
		col--;
	}
	return (count);
}

int	ft_count_up_views(int col, t_boardstat *s)
{
	int	count;
	int	row;
	int	max;

	count = 0;
	max = 0;
	row = 1;
	while (row <= s->size)
	{
		if (s->mat[row][col] == 0)
			break ;
		if (max < s->mat[row][col])
		{
			count++;
			max = s->mat[row][col];
		}
		row++;
	}
	return (count);
}

int	ft_count_down_views(int col, t_boardstat *s)
{
	int	count;
	int	row;
	int	max;

	count = 0;
	max = 0;
	row = s->size;
	while (row >= 1)
	{
		if (s->mat[row][col] == 0)
			break ;
		if (max < s->mat[row][col])
		{
			count++;
			max = s->mat[row][col];
		}
		row--;
	}
	return (count);
}
