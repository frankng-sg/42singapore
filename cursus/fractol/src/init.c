/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vietnguy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 15:29:51 by vietnguy          #+#    #+#             */
/*   Updated: 2023/12/29 22:06:50 by vietnguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "../pkg/mlx/mlx.h"
#include <stdlib.h>

void	init_fractol(t_fractol *g)
{
	g->mlx = mlx_init();
	g->win = mlx_new_window(g->mlx, WIDTH, HEIGHT, "Mandelbrot");
}

void	init_image(t_fractol *g, t_image *img)
{
	img->img = mlx_new_image(g->mlx, WIDTH, HEIGHT);
	img->addr = mlx_get_data_addr(img->img, &img->bits_per_pixel, 
			&img->line_len, &img->endian);
}
