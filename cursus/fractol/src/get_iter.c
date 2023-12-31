/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_iter.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vietnguy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 15:18:35 by vietnguy          #+#    #+#             */
/*   Updated: 2023/12/31 18:17:06 by vietnguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "../pkg/mlx/mlx.h"

int	get_iter_mandelbrot(t_fractol *g, t_complex c)
{
	t_complex	t;
	int		iter;
	double		cy2;
	double		q;

	(void)g;
	t = c;
	iter = -1;
	cy2 = c.im * c.im;
	q = (c.re - 0.25) * (c.re - 0.25) + cy2;
	if (q * (q + (c.re - 0.25)) < 0.25 * cy2)
		return (MAX_ITER);
	if ((c.re + 1) * (c.re + 1) + cy2 < 0.0625)
		return (MAX_ITER);
	while (++iter < MAX_ITER && c_abssq(t) <= 4)
		t = c_add(c_mult(t, t), c);
	return (iter);
}

int	get_iter_julia(t_fractol *g, t_complex c)
{
	int		iter;
	int		i;

	iter = -1;
	while (++iter < MAX_ITER && c_abssq(c) <= 4)
		c = c_add(c_mult(c, c), g->julia); 
		
	return (iter);
}
