/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vietnguy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 14:52:02 by vietnguy          #+#    #+#             */
/*   Updated: 2023/12/28 15:36:47 by vietnguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

// Error Management
# define ERR_INVALID_ARGS "invalid arguments"

// FDF Data Structure
typedef struct s_point
{
	float	x;
	float	y;
	float	z;
	int		color;
}	t_point;

typedef struct s_map
{
	t_point	**coord;
	int		max_x;
	int		max_y;
	int		max_z;
	int		min_z;
}	t_map;

typedef struct s_line
{
	t_point	start;
	t_point	end;
	float	transform_z;
}	t_line;

typedef struct s_image
{
	void	*image;
	char	*buffer;
	t_line	*line;
	int		pixel_bits;
	int		line_bytes;
	int		endian;
}	t_image;

typedef struct s_fdf
{
	t_map	*map;
	t_image	*img;
	void	*mlx;
	void	*win;
	int		win_width;
	int		win_height;
}	t_fdf;

#endif
