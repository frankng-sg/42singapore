/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vietnguy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 15:29:51 by vietnguy          #+#    #+#             */
/*   Updated: 2023/12/31 21:37:41 by vietnguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "../pkg/mlx/mlx.h"
#include <stdlib.h>

static	void	init(t_fractol *g)
{
	int	i;
	int	color_scale;

	g->mlx = NULL;
	g->win = NULL;
	g->img.img = NULL;
	g->img.addr = NULL;
	g->zoom = 1.0;
	g->re_start = RE_START;
	g->im_start = IM_START;
	g->shift_re = 0;
	g->shift_im = 0;
	color_scale = (1 << 24) / MAX_ITER;
	i = 1;
	g->color[0] = 0;
	while (i <= MAX_ITER)
	{
		g->color[i] = g->color[i - 1] + color_scale;
		i++;
	}
}

void	init_fractol(t_fractol *g, int type)
{
	init(g);
	g->mlx = mlx_init();
	g->type = type;
	g->julia = c_new(JULIA_CX, JULIA_CY);
	if (g->mlx == NULL)
		ft_error(ERR_INIT_MLX);
	if (type == 1)
		g->win = mlx_new_window(g->mlx, WIDTH, HEIGHT, "Mandelbrot");
	else if (type == 2)
		g->win = mlx_new_window(g->mlx, WIDTH, HEIGHT, "Julia");
	if (g->win == NULL)
		(free_fractol(g), ft_error(ERR_INIT_WIN));
	init_image(g);
	init_image_map(g);
}

void	init_image_map(t_fractol *g)
{
	int	x;
	int	y;

	y = -1;
	while (++y < HEIGHT)
	{
		x = -1;
		while (++x < WIDTH)
		{
			g->img_map[x][y] = (uintptr_t)(g->img.addr + (y * g->img.line_len
						+ x * (g->img.bits_per_pixel >> 3)));
		}
	}
}

void	init_image(t_fractol *g)
{
	g->img.img = mlx_new_image(g->mlx, WIDTH, HEIGHT);
	if (g->img.img == NULL)
		(free_fractol(g), ft_error(ERR_INIT_IMG));
	g->img.addr = mlx_get_data_addr(g->img.img, &g->img.bits_per_pixel,
			&g->img.line_len, &g->img.endian);
	if (g->img.addr == NULL)
		(free_fractol(g), ft_error(ERR_INIT_IMG));
}
