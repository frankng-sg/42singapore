/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vietnguy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/01 17:25:44 by vietnguy          #+#    #+#             */
/*   Updated: 2023/07/02 09:49:27 by vietnguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HELPERS_H
# define HELPERS_H

typedef struct s_boardstat
{
	int	col_used[10][10];
	int	row_used[10][10];
	int	mat[10][10];
	int	upview[10];
	int	downview[10];
	int	leftview[10];
	int	rightview[10];
	int	size;
	int	found;
}	t_boardstat;
int		ft_strlen(char *str);
void	ft_putchar(char c);
void	ft_putstr(char *str);
void	ft_print_matrix(t_boardstat *s);
int		ft_count_left_views(int row, t_boardstat *s);
int		ft_count_right_views(int row, t_boardstat *s);
int		ft_count_up_views(int col, t_boardstat *s);
int		ft_count_down_views(int col, t_boardstat *s);
void	ft_do_readview(char **argv, int *view, int size);
void	ft_readview(char *argv, t_boardstat *s);
#endif
