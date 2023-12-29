/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_mandelbrot.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vietnguy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 15:18:35 by vietnguy          #+#    #+#             */
/*   Updated: 2023/12/29 16:30:22 by vietnguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static int	get_iter(t_complex c)
{
	t_complex	t;
	int		iters;

	t = c;
	iters = 0;
	while (iters < MAX_ITER && c_abssq(t) >= 2)
	{
		iters++;
		t = c_add(c_mult(t, t), c);
	}
	return (iters);
}

void	render_mandelbrot(t_fractol *g)
{
	int		x;
	int		y;
	t_complex	c;

	x = -1;
	while (++x < WIDTH)
	{
		y = -1;
		while (++y < HEIGHT)
		{
			c = c_new(RE_START + x * (RE_END - RE_START) / WIDTH,
				IM_START + y * (IM_END - IM_START) / HEIGHT);
			iter = get_iter(c);
			color = (int)255 - (int)255 * iter / MAX_ITER;
			ft_put_pixel(g->img, x, y, color);	
		}
	}
}
