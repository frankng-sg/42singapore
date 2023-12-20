/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vietnguy <vietnguy@42mail.sutd.edu.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 09:17:32 by vietnguy          #+#    #+#             */
/*   Updated: 2023/12/20 20:22:07 by vietnguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/push_swap.h"
#include "../lib/libft.h"
#include <stdlib.h>

t_stack	*search(t_stack *head, int key)
{
	while (head)
	{
		if (head->val == key)
			return (head);
		head = head->next;
	}
	return (NULL);
}

void	ft_free_stack(t_stack *head)
{
	t_stack	*next;

	if (head == NULL)
		return ;
	while (head->next)
	{
		next = head->next;
		free(head);
		head = next;
	}
	free(head);
}

void	ft_print_stack(t_stack *head)
{
	ft_printf("Stack:");
	while (head)
	{
		ft_printf(" %d", head->val);
		head = head->next;
	}
	ft_printf(" NULL\n");
}

t_stack	*ft_push_last(t_stack *head, int val)
{
	t_stack	*node;
	t_stack	*p;

	node = ft_new(val);
	if (head == NULL)
		return (node);
	p = head;
	while (p->next)
		p = p->next;
	p->next = node;
	return (head);
}

t_stack	*ft_rotate(t_stack *head)
{
	int val;

	if (head == NULL)
		return (head);
	val = head->val;
	head = ft_pop(head);
	head = ft_push_last(head, val);
	return (head);
}
