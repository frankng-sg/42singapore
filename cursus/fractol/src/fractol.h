/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vietnguy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 14:52:02 by vietnguy          #+#    #+#             */
/*   Updated: 2023/12/30 22:13:10 by vietnguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

// Configuration
# define WIDTH 400
# define HEIGHT 400
# define RE_START -3.0
# define RE_END 3.0 
# define IM_START -3.0
# define IM_END 3.0
# define MAX_ITER 25 

# if __linux
#  define ESC 65307
#  define SCROLL_UP 5
#  define SCROLL_DOWN 4
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
void	ft_error(char *msg);

// Fractol Data Structure
typedef struct s_image
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_len;
	int		endian;
}	t_image;

typedef char*	t_img_map[WIDTH][HEIGHT];

typedef struct s_fractol
{
	int	type;
	void	*mlx;
	void	*win;
	t_image	img;
	double	zoom;
	int	color_scale;
	t_img_map	img_map;
	double	re_scale;
	double	im_scale;
	double	re_start;
	double	im_start;
}	t_fractol;

// Initialization
void	init_fractol(t_fractol *g, int type);
void	init_image(t_fractol *g, t_image *img);
void	init_image_map(t_fractol *g, t_img_map *img_map);

// Free Memory
void	free_fractol(t_fractol *g);

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

// Handle Events: Keyboard & Mouse
void	register_events(t_fractol *g);

// Render Image
int	get_iter_mandelbrot(t_complex c);
void	render_init(t_fractol *g);
void	render_zoom(int mousecode, t_fractol *g);
void	render(t_fractol *g, t_image *img, int (*get_iter)());

#endif
