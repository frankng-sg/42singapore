/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_iter.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vietnguy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 15:18:35 by vietnguy          #+#    #+#             */
/*   Updated: 2023/12/31 10:33:28 by vietnguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "../pkg/mlx/mlx.h"

int	get_iter_mandelbrot(t_fractol *g, t_complex c)
{
	t_complex	t;
	int		iter;

	(void)g;
	t = c;
	iter = -1;
	while (++iter < MAX_ITER && c_abssq(t) <= 4)
		t = c_add(c_mult(t, t), c);
	return (iter);
}

int	get_iter_julia(t_fractol *g, t_complex c)
{
	t_complex	prev;
	int		iter;

	iter = -1;
	while (++iter < MAX_ITER && c_abssq(c) <= 4)
	{
		prev = c;
		c = c_add(c_mult(prev, prev), g->julia); 
	}
	return (iter);
}
