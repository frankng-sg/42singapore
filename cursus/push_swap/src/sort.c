/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vietnguy <vietnguy@42mail.sutd.edu.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 17:49:00 by vietnguy          #+#    #+#             */
/*   Updated: 2023/12/20 22:07:48 by vietnguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/libft.h"
#include "../lib/push_swap.h"
#include <limits.h>

static void	push(t_stack **a, t_stack **b)
{
	if (*a == NULL)
		return ;
	*b = ft_push(*b, (*a)->val);
	*a = ft_pop(*a); 
}

void	pusha(t_stack **b, t_stack **a)
{
	ft_printf("pa\n");
	push(b, a);
}

void	pushb(t_stack **a, t_stack **b)
{
	ft_printf("pb\n");
	push(a, b);
}

void	revrotb(t_stack **b)
{
	ft_printf("rrb\n");
	*b = ft_rrotate(*b);
}

void	rotb(t_stack **b)
{
	ft_printf("rb\n");
	*b = ft_rotate(*b);
}

t_stack	*ft_sort(t_stack *a)
{
	t_stack	*b;
	int	max_v;

	if (a == NULL)
		return (NULL);
	if (ft_length(a) <= 3)
		return (NULL);
	b = NULL;
	pushb(&a, &b);
	max_v = b->val;
	pushb(&a, &b);
	if (max_v < b->val)
		max_v = b->val;
	while (a)
	{
		while (b->val != max_v)
			revrotb(&b);
		if (a->val > max_v)
			max_v = a->val;
		if (a->val <= ft_last(b))
		{
			pushb(&a, &b);
			rotb(&b);
		}
		else
		{
			while (a->val < b->val)
				rotb(&b);
			pushb(&a, &b);
		}
	}
	while (b->val != max_v)
		revrotb(&b);
	while (b)
		pusha(&b, &a);
	return (a);
}

