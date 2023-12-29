/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vietnguy <vietnguy@42mail.sutd.edu.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/24 13:51:52 by vietnguy          #+#    #+#             */
/*   Updated: 2023/12/29 22:03:26 by vietnguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pkg/libft/libft.h"
#include "../pkg/gnl/gnl.h"
#include "../pkg/mlx/mlx.h"
#include "fractol.h"

int	main(int argc, char **argv)
{
	t_fractol	g;

	if (argc <= 1 || argv == NULL)
		return (ft_puterr(ERR_INVALID_ARGS));
	init_fractol(&g);
	render_mandelbrot(&g);
	mlx_loop(g.mlx);
	return (0);
}

