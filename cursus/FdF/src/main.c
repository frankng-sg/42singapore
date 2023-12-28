/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vietnguy <vietnguy@42mail.sutd.edu.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/24 13:51:52 by vietnguy          #+#    #+#             */
/*   Updated: 2023/12/28 13:14:31 by vietnguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pkg/libft/libft.h"
#include "../pkg/gnl/gnl.h"
#include "../pkg/mlx_linux/mlx.h"

int	main()
{
	void	*mlx;
	void	*mlx_win;

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 600, 400, "Hello World!");
	mlx_loop(mlx);
}
