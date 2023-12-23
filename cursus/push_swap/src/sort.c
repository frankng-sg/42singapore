/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vietnguy <vietnguy@42mail.sutd.edu.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 17:49:00 by vietnguy          #+#    #+#             */
/*   Updated: 2023/12/23 20:50:49 by vietnguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/libft.h"
#include "../lib/push_swap.h"
#include <limits.h>

t_stack	*radix_sort(t_stack *a, int size)
{
	t_stack	*b;
	int		i;
	int		cnt;	
	int		max_bit;

	i = 0;
	b = NULL;
	max_bit = find_max_bit(a);
	while (i <= max_bit)
	{
		cnt = 0;
		while (cnt++ < size)
		{
			if (read_bit(a->val, i) == 1)
				(ft_printf("ra\n"), a = ft_rotate(a));
			else
				(ft_printf("pb\n"), ft_push2(&a, &b));
		}
		while (b)
			(ft_printf("pa\n"), ft_push2(&b, &a));
		i++;
	}
	return (a);
}

t_stack	*ft_sort3(t_stack *a)
{
	int		min_v;

	min_v = minabc(a->val, a->next->val, a->next->next->val);
	if (a->next->val == min_v)
		(ft_printf("rra\n"), a = ft_rrotate(a));
	else if (a->val == min_v)
		(ft_printf("ra\n"), a = ft_rotate(a));
	if (a->val > a->next->val)
		(ft_printf("sa\n"), a = ft_swap(a));
	(ft_printf("rra\n"), a = ft_rrotate(a));
	return (a);
}


t_stack	*ft_sort5(t_stack *a)
{
	t_stack	*b;
	int		med[MAX_SIZE];
	int		lmed;
	int		i;

	find_above_median(a, &lmed, med);
	i = 0;
	while (i < lmed)
	{
		if (a->val == med[i])
			(ft_printf("pb\n"), ft_push2(&a, &b), i++);
		else
			(ft_printf("ra\n"), a = ft_rotate(a));
	}
	if (b->val < b->next->val)
		(ft_printf("sb\n"), b = ft_swap(b));
	a = ft_sort3(a);
	(ft_printf("pa\npa\n"), ft_push2(&b, &a), ft_push2(&b, &a));
	(ft_printf("ra\nra\n"), a = ft_rotate(a), a = ft_rotate(a));
	return (a);
}

t_stack	*ft_sort(t_stack *a, int size)
{
	if (size <= 1)
		return (a);
	if (size == 2 && a->val < a->next->val)
		return (a);
	if (size == 2 && a->val > a->next->val)
		return (ft_printf("sa\n"), ft_swap(a));
	if (verify_sorted(a))
		return (a);
	if (size == 3)
		return (ft_sort3(a));
	if (size == 5)
		return (ft_sort5(a));
	return (radix_sort(a, size));
}
