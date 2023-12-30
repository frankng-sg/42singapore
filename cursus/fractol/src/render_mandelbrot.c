/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_mandelbrot.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vietnguy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 15:18:35 by vietnguy          #+#    #+#             */
/*   Updated: 2023/12/30 21:57:25 by vietnguy         ###   ########.fr       */
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

void	init_mandelbrot(t_fractol *g)
{
	g->re_start = g->zoom * RE_START;
	g->im_start = g->zoom * IM_START;
	g->re_scale = g->zoom * (double)(RE_END - RE_START) / (double)WIDTH;
	g->im_scale = g->zoom * (double)(IM_END - IM_START) / (double)HEIGHT;
	g->color_scale = (1 << 24) / MAX_ITER;
}

void	zoom_mandelbrot(int mousecode, t_fractol *g)
{
	if (mousecode == SCROLL_DOWN)
		g->zoom *= 0.9;
	else if (mousecode == SCROLL_UP)
		g->zoom *= 1.1;
	init_mandelbrot(g);
	render_mandelbrot(g, &g->img);
}

void	render_mandelbrot(t_fractol *g, t_image *img)
{
	int		x;
	int		y;
	int		color;
	int		iter;
	t_complex	c;

	y = -1;
	while (++y < HEIGHT)
	{
		c.im = g->im_start + (double)y * g->im_scale;
		x = -1;
		while (++x < WIDTH)
		{
			c.re = g->re_start + (double)x * g->re_scale;
			iter = get_iter(c);
			color = iter * g->color_scale; 
			*(unsigned int *)(g->img_map[x][y]) = color;
		}
	}
	mlx_put_image_to_window(g->mlx, g->win, img->img, 0, 0);
}