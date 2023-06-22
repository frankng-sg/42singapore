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
#define BOARD_SIZE 4

int	ft_valid_case(int i, int j, int h, t_boardstat *s)
{
	if (s->col_used[j][h] || s->row_used[i][h])
		return (0);
	if (i == 1 && s->upview[j] > s->size - h + 1)
		return (0);
	if (j == 1 && s->leftview[i] > s->size - h + 1)
		return (0);
	if (ft_count_left_views(i, s) > s->leftview[i])
		return (0);
	if (ft_count_up_views(j, s) > s->upview[j])
		return (0);
	if (j == s->size && ft_count_left_views(i, s) != s->leftview[i])
		return (0);
	if (j == s->size && ft_count_right_views(i, s) != s->rightview[i])
		return (0);
	if (i == s->size && ft_count_up_views(j, s) != s->upview[j])
		return (0);
	if (i == s->size && ft_count_down_views(j, s) != s->downview[j])
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

void	try(int i, int j, t_boardstat *s)
{
	int	h;

	if (is_complete(i, s))
		return ;
	h = 1;
	while (h <= s->size)
	{
		s->mat[i][j] = h;
		if (ft_valid_case(i, j, h, s))
		{
			s->col_used[j][h] = 1;
			s->row_used[i][h] = 1;
			if (j >= s->size)
				try(i + 1, 1, s);
			else
				try(i, j + 1, s);
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
	s_stat.found = 0;
	try(1, 1, &s_stat);
	if (!s_stat.found)
		ft_putstr("Error\n");
	return (0);
}
