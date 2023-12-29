/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vietnguy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 15:29:51 by vietnguy          #+#    #+#             */
/*   Updated: 2023/12/29 14:58:51 by vietnguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdlib.h>

void	init_fractol(t_fractol *g)
{
	g->mlx = mlx_init();
	g->win = mlx_new_window(g->mlx, WIN_MAXX, WIN_MAXY, "Mandelbrot"
}

void	init_image(t_fractol *g, t_image *img)
{
	img->img = mlx_new_image(g->mlx, WIN_MAXX, WIN_MAXY);
	img->addr = mlx_get_data-addr(img->img, &img->bits_per_pixel, 
			&img->line_len, &img->endian);
}
