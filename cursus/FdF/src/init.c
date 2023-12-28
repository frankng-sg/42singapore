/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vietnguy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 15:29:51 by vietnguy          #+#    #+#             */
/*   Updated: 2023/12/28 15:42:09 by vietnguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdlib.h>

t_fdf	*init_fdf(char *filename)
{
	t_fdf	*fdf;

	fdf = malloc(sizeof(t_fdf));
	if (!fdf)
		return (close_fdf(fdf), NULL);
	fdf->map = read_map(filename);
	if (!fdf->map)
		return (close_fdf(fdf), NULL);
	fdf->mlx = mlx_init();
	fdf->win_width = WINDOW_WIDTH;
	fdf->win_height = WINDOW_HEIGHT;
	fdf->win = mlx_new_window(fdf->mlx, fdf->win_width, 
			fdf->win_height, WINDOW_NAME);
	fdf->img = init_image(fdf->mlx);
	if (!fdf->image)
		return (close_fdf(fdf), NULL);
	return (fdf);
}
