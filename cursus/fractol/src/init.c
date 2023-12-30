/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vietnguy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 15:29:51 by vietnguy          #+#    #+#             */
/*   Updated: 2023/12/30 20:06:54 by vietnguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "../pkg/mlx/mlx.h"
#include <stdlib.h>

void	init_fractol(t_fractol *g, int type)
{
	g->mlx = NULL;
	g->win = NULL;
	g->img.img = NULL;
	g->img.addr = NULL;
	g->mlx = mlx_init();
	g->type = type;
	g->zoom = 1.0;
	g->re_start = RE_START;
	g->im_start = IM_START;
	if (g->mlx == NULL)
		ft_error(ERR_INIT_MLX);
	if (type == 1)
		g->win = mlx_new_window(g->mlx, WIDTH, HEIGHT, "Mandelbrot");
	if (g->win == NULL)
		(free_fractol(g), ft_error(ERR_INIT_WIN));
	init_image(g, &g->img);
}

void	init_image(t_fractol *g, t_image *img)
{
	img->img = mlx_new_image(g->mlx, WIDTH, HEIGHT);
	if (img->img == NULL)
		(free_fractol(g), ft_error(ERR_INIT_IMG));
	img->addr = mlx_get_data_addr(img->img, &img->bits_per_pixel,
			&img->line_len, &img->endian);
	if (img->addr == NULL)
		(free_fractol(g), ft_error(ERR_INIT_IMG));
}
