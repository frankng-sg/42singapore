/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vietnguy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 14:52:02 by vietnguy          #+#    #+#             */
/*   Updated: 2023/12/31 21:34:25 by vietnguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <stdint.h>

// Configuration
# define WIDTH 200
# define HEIGHT 200
# define RE_START -3.0
# define RE_END 3.0 
# define IM_START -3.0
# define IM_END 3.0
# define MAX_ITER 100
# define JULIA_CX -0.7
# define JULIA_CY 0.27015
# define SHIFT_STEP 10

# if __linux
#  define ESC 65307
#  define SCROLL_UP 5
#  define SCROLL_DOWN 4
#  define ARR_UP 65364
#  define ARR_DOWN 65362
#  define ARR_RIGHT 65363
#  define ARR_LEFT 65361
#  define SPACE 32
# else
#  define ESC 53
#  define SCROLL_UP 5
#  define SCROLL_DOWN 4
# endif

// Error Management
# define ERR_INVALID_ARGS "invalid arguments"
# define ERR_INIT_MLX "fail to initialize mlx"
# define ERR_INIT_WIN "fail to initialize window"
# define ERR_INIT_IMG "fail to initialize image"

void		ft_error(char *msg);

// Handle Complex Number
typedef struct s_complex
{
	double	re;
	double	im;
}	t_complex;
t_complex	c_new(double re, double im);
t_complex	c_mult(t_complex a, t_complex b);
t_complex	c_add(t_complex a, t_complex b);
double		c_abssq(t_complex a);	

// Fractol Data Structure
typedef struct s_image
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_len;
	int		endian;
}	t_image;

typedef struct s_fractol
{
	int			type;
	int			color[MAX_ITER + 1];
	void		*mlx;
	void		*win;
	t_image		img;
	double		zoom;
	double		re_scale;
	double		im_scale;
	double		re_start;
	double		im_start;
	double		shift_re;
	double		shift_im;
	t_complex	julia;
	uintptr_t	img_map[WIDTH][HEIGHT];
}	t_fractol;

// Initialization
void		init_fractol(t_fractol *g, int type);
void		init_image(t_fractol *g);
void		init_image_map(t_fractol *g);

// Free Memory
void		free_fractol(t_fractol *g);

// Handle Events: Keyboard & Mouse
void		register_events(t_fractol *g);

// Render Image
int			get_iter_mandelbrot(t_fractol *g, t_complex c);
int			get_iter_julia(t_fractol *g, t_complex c);
void		render_init(t_fractol *g);
void		render_update(t_fractol *g);
void		render(t_fractol *g, t_image *img, int (*get_iter)());
void		render_fractol(t_fractol *g);

#endif
