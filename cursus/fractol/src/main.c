/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vietnguy <vietnguy@42mail.sutd.edu.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/24 13:51:52 by vietnguy          #+#    #+#             */
/*   Updated: 2023/12/31 10:50:23 by vietnguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pkg/libft/libft.h"
#include "../pkg/gnl/gnl.h"
#include "../pkg/mlx/mlx.h"
#include "fractol.h"
#include <stdlib.h>

void	ft_error(char *msg)
{
	ft_puterr(msg);
	exit(EXIT_FAILURE);
}

void	ft_menu()
{
	ft_printf("USAGE:\n");
	ft_printf("./fractol [type] [options]\n");
	ft_printf("type=1: mandelbrot\n");
	ft_printf("        e.g. ./fractol 1\n");
	ft_printf("type=2: julia\n");
	ft_printf("        options: x y where x, y are floating point numbers\n");
	ft_printf("        e.g. ./fractol 2 1.3 -0.1\n");
	ft_printf("\n");
}

static int	ft_isnumber(char *s)
{
	if (s == NULL)
		return (0);
	if (*s == '-' || *s == '+')
		s++;
	while (*s && *s != '.')
	{
		if (*s < '0' || *s > '9')
			return (0);
		s++;
	}
	if (*s == '.')
		s++;
	while (*s)
	{
		if (*s < '0' || *s > '9')
			return (0);
		s++;
	}
	return (1);
}

int	validate(int argc, char **argv)
{
	
	if (argc <= 1 || argc > 4 || argc == 3 || argv == NULL)
		return (0);
	if (ft_strcmp(argv[1], "1") != 0 && ft_strcmp(argv[1], "2") != 0)
		return (0);
	if (ft_strcmp(argv[1], "1") == 0 && argc != 2)
		return (0);
	if (argc == 4 && (ft_isnumber(argv[2]) == 0 || ft_isnumber(argv[3]) == 0))
		return (0);
	return (1);
}

int	main(int argc, char **argv)
{
	t_fractol	g;
	int		type;

	if (validate(argc, argv) == 0)
		(ft_menu(), ft_error(ERR_INVALID_ARGS));
	type = ft_atoi(argv[1]);
	init_fractol(&g, type);
	if (argc > 2)
	{
		g.julia.re = ft_atod(argv[2]);
		g.julia.im = ft_atod(argv[3]);
	}
	render_init(&g);
	render_fractol(&g);
	register_events(&g);
	mlx_loop(g.mlx);
	free_fractol(&g);
	return (0);
}

