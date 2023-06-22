/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vietnguy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 16:22:39 by vietnguy          #+#    #+#             */
/*   Updated: 2023/06/29 16:37:08 by vietnguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int	*arr;
	int	*arr_addr;
	int	i;

	if (min >= max)
		return ((void *)0);
	arr = (int *)malloc((max - min) * sizeof(int));
	arr_addr = arr;
	i = min;
	while (i < max)
		*arr++ = i++;
	return (arr_addr);
}
