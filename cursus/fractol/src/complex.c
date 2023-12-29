/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vietnguy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 16:11:24 by vietnguy          #+#    #+#             */
/*   Updated: 2023/12/29 23:39:30 by vietnguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_complex	c_new(double re, double im)
{
	t_complex	result;

	result.re = re;
	result.im = im;
	return (result);
}

t_complex	c_mult(t_complex a, t_complex b)
{
	t_complex	result;

	result.re = a.re * b.re - a.im * b.im;
	result.im = a.re * b.im + a.im * b.re;
	return (result);
}

t_complex	c_add(t_complex a, t_complex b)
{
	t_complex	result;

	result.re = a.re + b.re;
	result.im = a.im + b.im;
	return (result);
}

double	c_abssq(t_complex a)
{
	int	result;

	result = a.re * a.re + a.im * a.im;
	return (result);
}
