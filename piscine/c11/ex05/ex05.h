/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex05.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vietnguy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 20:41:03 by vietnguy          #+#    #+#             */
/*   Updated: 2023/07/12 20:41:05 by vietnguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EX05_H
# define EX05_H

typedef struct s_global
{
	int		g_op_idx[50];
	int		(*g_f[5])(int, int);
	char	*g_err_msg[2];
}	t_global;
int		sum(int a, int b);
int		sub(int a, int b);
int		mul(int a, int b);
int		div(int a, int b);
int		mod(int a, int b);
void	ft_putstr(char *str);
void	rec(int nb);
void	ft_putnbr(int nb);
int		ft_atoi(char *str);
#endif
