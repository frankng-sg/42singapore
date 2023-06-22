/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vietnguy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/01 11:22:29 by vietnguy          #+#    #+#             */
/*   Updated: 2023/07/02 10:41:21 by vietnguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "helpers.h"
#define BOARD_SIZE 7

int	row_max_val(t_boardstat *s, int row)
{
	int	col;
	int	max;

	col = 1;
	max = 0;
	while (col <= s->size && s->mat[row][col] != 0)
	{
		if (max < s->mat[row][col])
			max = s->mat[row][col];
		col++;
	}
	return (max);
}

int	col_max_val(t_boardstat *s, int col)
{
	int	row;
	int	max;

	row = 1;
	max = 0;
	while (row <= s->size && s->mat[row][col] != 0)
	{
		if (max < s->mat[row][col])
			max = s->mat[row][col];
		row++;
	}
	return (max);
}

int	ft_valid_case(int i, int j, int h, t_boardstat *s)
{
	const int	left_views = ft_count_left_views(i, s);
	const int	right_views = ft_count_right_views(i, s);
	const int	up_views = ft_count_up_views(j, s);
	const int	down_views = ft_count_down_views(j, s);

	if (s->col_used[j][h] || s->row_used[i][h])
		return (0);
	if (i == 1 && s->upview[j] > s->size - h + 1)
		return (0);
	if (j == 1 && s->leftview[i] > s->size - h + 1)
		return (0);
	if (left_views > s->leftview[i])
		return (0);
	if (up_views > s->upview[j])
		return (0);
	if (left_views == s->leftview[i] && row_max_val(s, i) < s->size)
		return (0);
	if (up_views == s->upview[j] && col_max_val(s, j) < s->size)
		return (0);
	if (j == s->size && left_views != s->leftview[i])
		return (0);
	if (j == s->size && right_views != s->rightview[i])
		return (0);
	if (i == s->size && up_views != s->upview[j])
		return (0);
	if (i == s->size && down_views != s->downview[j])
		return (0);
	return (1);
}

int	is_complete(int i, t_boardstat *s)
{
	if (s->found)
		return (1);
	if (i >= s->size + 1)
	{
		s->found = 1;
		ft_print_matrix(s);
		return (1);
	}
	return (0);
}

void	try(int i, int j, t_boardstat *s);

void	next(int i, int j, t_boardstat *s)
{
	if (j >= s->size)
		try(i + 1, 1, s);
	else
		try(i, j + 1, s);
}

void	try(int i, int j, t_boardstat *s)
{
	int	h;

	if (is_complete(i, s))
		return ;
	if (s->mat[i][j] != 0)
		return (next(i, j, s));
	h = 1;
	while (h <= s->size)
	{
		s->mat[i][j] = h;
		if (ft_valid_case(i, j, h, s))
		{
			s->col_used[j][h] = 1;
			s->row_used[i][h] = 1;
			next(i, j, s);
			s->col_used[j][h] = 0;
			s->row_used[i][h] = 0;
		}
		h++;
	}
	s->mat[i][j] = 0;
}

void	ft_initialize(t_boardstat *s)
{
	int	i;
	int	j;

	s->found = 0;
	i = 0;
	while (i <= s->size)
	{
		j = 0;
		while (j <= s->size)
		{
			s->mat[i][j] = 0;
			s->col_used[i][j] = 0;
			s->row_used[i][j] = 0;
			j++;
		}
		i++;
	}
}

void	assign_cell(t_boardstat *s, int i, int j, int val)
{
	s->mat[i][j] = val;
	s->col_used[j][val] = 1;
	s->row_used[i][val] = 1;
}

void	assign_col(t_boardstat *s, int col, int istopview)
{
	int	row;

	if (istopview)
	{
		row = 1;
		while (row <= s->size)
		{
			assign_cell(s, row, col, row);
			row++;
		}
	}
	else
	{
		row = s->size;
		while (row >= 1)
		{
			assign_cell(s, row, col, s->size - row + 1);
			row--;
		}
	}
}

void	assign_row(t_boardstat *s, int row, int isleftview)
{
	int	col;

	if (isleftview)
	{
		col = 1;
		while (col <= s->size)
		{
			assign_cell(s, row, col, col);
			col++;
		}
	}
	else
	{
		col = s->size;
		while (col >= 1)
		{
			assign_cell(s, row, col, s->size - col + 1);
			col--;
		}
	}
}

void	ft_prefill(t_boardstat *s)
{
	int	i;

	i = 1;
	while (i < s->size)
	{
		if (s->upview[i] == 1)
			assign_cell(s, 1, i, s->size);
		if (s->downview[i] == 1)
			assign_cell(s, s->size, i, s->size);
		if (s->leftview[i] == 1)
			assign_cell(s, i, 1, s->size);
		if (s->rightview[i] == 1)
			assign_cell(s, i, s->size, s->size);
		if (s->upview[i] == s->size)
			assign_col(s, i, 1);
		if (s->downview[i] == s->size)
			assign_col(s, i, 0);
		if (s->leftview[i] == s->size)
			assign_row(s, i, 1);
		if (s->rightview[i] == s->size)
			assign_row(s, i, 0);
		i++;
	}
}

int	main(int argc, char *argv[])
{
	t_boardstat	s_stat;

	s_stat.size = BOARD_SIZE;
	if (argc != 2 || ft_strlen(argv[1]) != 8 * s_stat.size - 1)
	{
		ft_putstr("Error\n");
		return (1);
	}
	ft_readview(argv[1], &s_stat);
	ft_initialize(&s_stat);
	ft_prefill(&s_stat);
	try(1, 1, &s_stat);
	if (!s_stat.found)
		ft_putstr("Error\n");
	return (0);
}
