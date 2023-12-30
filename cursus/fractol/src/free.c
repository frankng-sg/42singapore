/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vietnguy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 10:49:21 by vietnguy          #+#    #+#             */
/*   Updated: 2023/12/30 18:45:54 by vietnguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "../pkg/mlx/mlx.h"
#include <stdlib.h>

void	free_fractol(t_fractol *g)
{
	if (g == NULL || g->mlx == NULL)
		return ;
	if (g->win)
		mlx_destroy_window(g->mlx, g->win);
	if (g->img.img)
		mlx_destroy_image(g->mlx, g->img.img);
	mlx_destroy_display(g->mlx);
	free(g->mlx);
}
