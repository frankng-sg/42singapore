/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vietnguy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 15:18:35 by vietnguy          #+#    #+#             */
/*   Updated: 2023/12/31 21:17:42 by vietnguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "../pkg/mlx/mlx.h"

void	render_init(t_fractol *g)
{
	g->re_scale = g->zoom * (double)(RE_END - RE_START) / (double)WIDTH;
	g->im_scale = g->zoom * (double)(IM_END - IM_START) / (double)HEIGHT;
	g->re_start = g->zoom * RE_START + g->shift_re;
	g->im_start = g->zoom * IM_START + g->shift_im;
}

void	render_update(t_fractol *g)
{
	render_init(g);
	if (g->type == 1)
		render(g, &g->img, &get_iter_mandelbrot);
	else if (g->type == 2)
		render(g, &g->img, &get_iter_julia);
}

void	render_fractol(t_fractol *g)
{
	if (g->type == 1)
		render(g, &g->img, &get_iter_mandelbrot);
	else if (g->type == 2)
		render(g, &g->img, &get_iter_julia);
}

void	render(t_fractol *g, t_image *img, int (*get_iter)())
{
	int			x;
	int			y;
	int			color;
	int			iter;
	t_complex	c;

	y = -1;
	c.im = g->im_start;
	while (++y < HEIGHT)
	{
		x = -1;
		c.re = g->re_start;
		while (++x < WIDTH)
		{
			iter = get_iter(g, c);
			color = g->color[iter];
			*(unsigned int *)(g->img_map[x][y]) = color;
			c.re += g->re_scale;
		}
		c.im += g->im_scale;
	}
	mlx_put_image_to_window(g->mlx, g->win, img->img, 0, 0);
}
