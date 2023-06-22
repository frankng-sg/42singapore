/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vietnguy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 20:40:54 by vietnguy          #+#    #+#             */
/*   Updated: 2023/07/12 23:01:24 by vietnguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_sort(int *tab, int length, int (*f)(int, int))
{
	int	arr_dir;
	int	curr_dir;

	arr_dir = 0;
	while (length-- > 1)
	{
		curr_dir = f(tab[length - 1], tab[length]);
		if (curr_dir == 0)
			continue ;
		if (arr_dir == 0)
			arr_dir = curr_dir;
		if ((arr_dir < 0 && curr_dir > 0) || \
			(arr_dir > 0 && curr_dir < 0))
			return (0);
	}
	return (1);
}
/*
#include <stdio.h>
int	cmp(int a, int b)
{
	return (a - b);
}
int	main(void)
{
	const int	num[] = {-148091, -127421, -23593, 248345};

	printf("%d\n", ft_is_sort((int *)num, 4, &cmp));
	return (0);
}
*/
