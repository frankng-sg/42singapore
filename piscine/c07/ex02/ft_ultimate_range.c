/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vietnguy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 16:48:17 by vietnguy          #+#    #+#             */
/*   Updated: 2023/06/29 18:02:13 by vietnguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

int	ft_ultimate_range(int **range, int min, int max)
{
	int	size;
	int	*buff;

	if (min >= max)
	{
		*range = (void *)0;
		return (0);
	}	
	size = max - min;
	*range = (int *)malloc(size * sizeof(int));
	if (*range == 0)
		return (-1);
	buff = *range;
	while (min < max)
		*buff++ = min++;
	return (size);
}
