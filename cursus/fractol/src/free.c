/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vietnguy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 10:49:21 by vietnguy          #+#    #+#             */
/*   Updated: 2023/12/29 22:04:32 by vietnguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "fractol.h"

void	free_fractol(t_fractol *g)
{
	if (g == NULL)
		return ;
	free(g->mlx);
	free(g->win);
	free(g);
}

void	free_image(t_image *img)
{
	free(img->img);
}
