/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vietnguy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 15:29:51 by vietnguy          #+#    #+#             */
/*   Updated: 2023/12/30 10:03:09 by vietnguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "../pkg/mlx/mlx.h"
#include <stdlib.h>

void	init_fractol(t_fractol *g)
{
	g->mlx = mlx_init();
	g->win = mlx_new_window(g->mlx, WIDTH, HEIGHT, "Mandelbrot");
	init_image(g->mlx, &g->img);
	g->re_scale = (double)(RE_END - RE_START) / (double)WIDTH;
	g->im_scale = (double)(IM_END - IM_START) / (double)HEIGHT;
	g->color_scale = (1 << 24) / MAX_ITER;
}

void	init_image(void *mlx, t_image *img)
{
	img->img = mlx_new_image(mlx, WIDTH, HEIGHT);
	img->addr = mlx_get_data_addr(img->img, &img->bits_per_pixel,
			&img->line_len, &img->endian);
}
