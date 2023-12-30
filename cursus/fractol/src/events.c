/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vietnguy <vietnguy@student.42singapore.sg  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/30 10:27:32 by vietnguy          #+#    #+#             */
/*   Updated: 2023/12/30 18:50:58 by vietnguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "../pkg/mlx/mlx.h"
#include <stdlib.h>

static int	key_hook(int keycode, t_fractol *g)
{
	if (keycode == ESC)
		esc_window(g);
	return (0);
}

static int	mouse_hook(int mousecode, int x, int y, t_fractol *g)
{
	(void)x;
	(void)y;
	if (g->type == 1)
		zoom_mandelbrot(mousecode, g);
	return (0);
}

void	register_events(t_fractol *g)
{
	mlx_mouse_hook(g->win, &mouse_hook, g);
	mlx_hook(g->win, 17, 0, &esc_window, g);
	mlx_key_hook(g->win, &key_hook, g);
}
