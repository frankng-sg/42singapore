/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_min.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vietnguy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 21:55:50 by vietnguy          #+#    #+#             */
/*   Updated: 2023/09/24 14:36:06 by vietnguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned int	ft_min_uint(unsigned int a, unsigned int b)
{
	if (a < b)
		return (a);
	return (b);
}

size_t	ft_min_sizet(size_t a, size_t b)
{
	if (a < b)
		return (a);
	return (b);
}
