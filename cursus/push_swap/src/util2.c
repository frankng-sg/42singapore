/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vietnguy <vietnguy@42mail.sutd.edu.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 17:49:00 by vietnguy          #+#    #+#             */
/*   Updated: 2023/12/21 17:06:23 by vietnguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/libft.h"
#include "../lib/push_swap.h"
#include <limits.h>

#define MAX_BIN 12

int	read_bit(int val, int bit)
{
	return ((val >> bit) & 1);
}

int	find_max_bit(t_stack *a)
{
	int	max_v;
	int	i;

	max_v = 0;
	while (a)
	{
		if (max_v < a->val)
			max_v = a->val;
		a = a->next;
	}
	i = MAX_BIN;
	while (i >= 0)
	{
		if (read_bit(max_v, i))
			return (i);
		i--;
	}
	return (0);
}

int	minabc(int a, int b, int c)
{
	int	min;

	min = a;
	if (min > b)
		min = b;
	if (min > c)
		min = c;
	return (min);
}
