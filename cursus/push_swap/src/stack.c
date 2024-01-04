/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vietnguy <vietnguy@42mail.sutd.edu.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 09:17:32 by vietnguy          #+#    #+#             */
/*   Updated: 2023/12/20 19:34:50 by vietnguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/libft.h"
#include "../lib/push_swap.h"
#include <stdlib.h>

t_stack	*ft_pop(t_stack *head)
{
	t_stack	*new_head;

	if (head == NULL)
		return (NULL);
	new_head = head->next;
	free(head);
	return (new_head);
}

t_stack	*ft_new(int val)
{
	t_stack	*node;

	node = (t_stack *)malloc(sizeof(t_stack));
	node->val = val;
	node->next = NULL;
	return (node);
}

t_stack	*ft_push(t_stack *head, int val)
{
	t_stack	*new_head;

	new_head = ft_new(val);
	new_head->next = head;
	return (new_head);
}

t_stack	*ft_swap(t_stack *head)
{
	int	tmp;

	if (head == NULL || head->next == NULL)
		return (head);
	tmp = head->val;
	head->val = head->next->val;
	head->next->val = tmp;
	return (head);
}

int	ft_rm_bottom(t_stack *head)
{
	int		val;
	t_stack	*next;
	t_stack	*curr;

	if (head == NULL)
		return (0);
	if (head->next == NULL)
	{
		val = head->val;
		free(head);
		return (val);
	}
	curr = head;
	next = head->next;
	while (next->next)
	{
		curr = next;
		next = next->next;
	}
	val = next->val;
	free(next);
	curr->next = NULL;
	return (val);
}
