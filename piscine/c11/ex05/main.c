/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vietnguy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 20:36:16 by vietnguy          #+#    #+#             */
/*   Updated: 2023/07/12 20:36:47 by vietnguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ex05.h"

void	init(t_global *g)
{
	g->g_op_idx[(int) '/'] = 0;
	g->g_op_idx[(int) '%'] = 1;
	g->g_op_idx[(int) '+'] = 2;
	g->g_op_idx[(int) '-'] = 3;
	g->g_op_idx[(int) '*'] = 4;
	g->g_f[0] = div;
	g->g_f[1] = mod;
	g->g_f[2] = sum;
	g->g_f[3] = sub;
	g->g_f[4] = mul;
	g->g_err_msg[0] = "Stop : division by zero";
	g->g_err_msg[1] = "Stop : modulo by zero";
}

int	is_valid_operator(char op)
{
	return (op == '+' || op == '-' || op == '*' || op == '/' || op == '%');
}

int	main(int argc, char *argv[])
{
	int			a;
	int			b;
	char		op;
	t_global	g;

	init(&g);
	if (argc != 4)
		return (0);
	op = argv[2][0];
	if (argv[2][1] || !is_valid_operator(op))
	{
		ft_putstr("0\n");
		return (0);
	}
	a = ft_atoi(argv[1]);
	b = ft_atoi(argv[3]);
	if (b == 0 && (op == '/' || op == '%'))
		ft_putstr(g.g_err_msg[g.g_op_idx[(int)op]]);
	else
		ft_putnbr(g.g_f[g.g_op_idx[(int)op]](a, b));
	ft_putstr("\n");
	return (0);
}
