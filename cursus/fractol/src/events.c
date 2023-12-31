/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vietnguy <vietnguy@student.42singapore.sg  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/30 10:27:32 by vietnguy          #+#    #+#             */
/*   Updated: 2023/12/31 20:07:09 by vietnguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "../pkg/mlx/mlx.h"
#include <stdlib.h>

static int	esc_window(t_fractol *g)
{
	free_fractol(g);
	exit(0);
}

static int	key_hook(int keycode, t_fractol *g)
{
	if (keycode == ESC)
		esc_window(g);
	if (keycode == ARR_UP)
		g->shift_im += SHIFT_STEP * g->im_scale;
	else if (keycode == ARR_DOWN)
		g->shift_im -= SHIFT_STEP * g->im_scale;
	else if (keycode == ARR_LEFT)
		g->shift_re -= SHIFT_STEP * g->re_scale;
	else if (keycode == ARR_RIGHT)
		g->shift_re += SHIFT_STEP * g->re_scale;
	else if (keycode == SPACE)
	{
		g->shift_re = 0;
		g->shift_im = 0;
		g->zoom = 1;
	}
	render_update(g);
	return (0);
}

static int	mouse_hook(int mousecode, int x, int y, t_fractol *g)
{
	(void)x;
	(void)y;
	if (mousecode == SCROLL_DOWN)
		g->zoom *= 0.9;
	else if (mousecode == SCROLL_UP)
		g->zoom *= 1.1;
	render_update(g);
	return (0);
}

void	register_events(t_fractol *g)
{
	mlx_mouse_hook(g->win, &mouse_hook, g);
	mlx_hook(g->win, 17, 0, &esc_window, g);
	mlx_key_hook(g->win, &key_hook, g);
}
