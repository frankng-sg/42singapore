/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vietnguy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 14:52:02 by vietnguy          #+#    #+#             */
/*   Updated: 2023/12/29 16:10:23 by vietnguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

// Error Management
# define ERR_INVALID_ARGS "invalid arguments"

// Configuration
# define WIDTH 600
# define HEIGHT 400
# define RE_START -2
# define RE_END 1
# define IM_START -1
# define IM_END 1
# define MAX_ITER 150

// Fractol Data Structure
typedef struct s_image
{
	void	*img;
	char	*buf;
	int		bits_per_pixel;
	int		line_len;
	int		endian;
}	t_image;

typedef struct s_fractol
{
	void	*mlx;
	void	*win;
	t_image	img;
}	t_fractol;

// Initialization
void	init_fractol(t_fractor *g);

// Free Memory

// Handle Complex Number
typedef struct s_complex
{
	double	re;
	double	im;
}	t_complex;

t_complex	multiply(t_complex a, t_complex b);
t_complex	add(t_complex a, t_complex b);
double		abs_sq(t_complex a);	

#endif
