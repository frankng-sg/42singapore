/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_mandelbrot.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vietnguy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 15:18:35 by vietnguy          #+#    #+#             */
/*   Updated: 2023/12/30 10:04:00 by vietnguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "../pkg/mlx/mlx.h"
#include <stdio.h>

static int	get_iter(t_complex c)
{
	t_complex	t;
	int		iter;

	t = c;
	iter = -1;
	while (++iter < MAX_ITER && c_abssq(t) <= 4)
		t = c_add(c_mult(t, t), c);
	return (iter);
}

static t_mandelbrot	init_mandelbrot()
{
	t_mandelbrot	mdb;

	mdb.re_scale = (double)(RE_END - RE_START) / (double)WIDTH;
	mdb.im_scale = (double)(IM_END - IM_START) / (double)HEIGHT;
	mdb.color_scale = (1 << 24) / MAX_ITER;
	return (mdb);
}

void	render_mandelbrot(t_fractol *g)
{
	int		x;
	int		y;
	int		color;
	int		iter;
	t_complex	c;
	t_mandelbrot	mdb;

	y = -1;
	mdb = init_mandelbrot();
	while (++y < HEIGHT)
	{
		c.im = (double)IM_START + (double)y * mdb.im_scale;
		x = -1;
		while (++x < WIDTH)
		{
			c.re = (double)RE_START + (double)x * mdb.re_scale;
			iter = get_iter(c);
			color = iter * mdb.color_scale; 
			ft_put_pixel(&g->img, x, y, color);	
}
	}
	mlx_put_image_to_window(g->mlx, g->win, g->img.img, 0, 0);
}
