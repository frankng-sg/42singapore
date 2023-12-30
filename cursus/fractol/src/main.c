/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vietnguy <vietnguy@42mail.sutd.edu.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/24 13:51:52 by vietnguy          #+#    #+#             */
/*   Updated: 2023/12/30 19:52:47 by vietnguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pkg/libft/libft.h"
#include "../pkg/gnl/gnl.h"
#include "../pkg/mlx/mlx.h"
#include "fractol.h"

void	ft_error(char *msg)
{
	ft_puterr(msg);
	exit(EXIT_FAILURE);
}

int	main(int argc, char **argv)
{
	t_fractol	g;

	if (argc <= 1 || argv == NULL)
		ft_error(ERR_INVALID_ARGS);
	init_fractol(&g, 1);
	init_mandelbrot(&g);
	render_mandelbrot(&g, &g.img);
	register_events(&g);
	mlx_loop(g.mlx);
	free_fractol(&g);
	return (0);
}

