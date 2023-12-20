/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vietnguy <vietnguy@42mail.sutd.edu.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 09:17:32 by vietnguy          #+#    #+#             */
/*   Updated: 2023/12/20 20:29:22 by vietnguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/push_swap.h"
#include "../lib/libft.h"
#include <stdlib.h>

t_stack	*ft_rrotate(t_stack *head)
{
	int val;

	if (head == NULL)
		return (head);
	val = ft_last(head);
	head = ft_pop_last(head);
	head = ft_push(head, val);
	return (head);
}

t_stack	*ft_pop_last(t_stack *head)
{
	t_stack	*curr;
	t_stack	*next;

	if (head == NULL)
		return (head);
	if (head->next == NULL)
	{
		free(head);
		return (NULL);
	}
	curr = head;
	next = head->next;
	while (next->next)
	{
		curr = next;
		next = next->next;
	}
	free(next);
	curr->next = NULL;
	return (head);
}

int	ft_last(t_stack *head)
{
	if (head == NULL)
		return (0);
	while (head->next)
		head = head->next;
	return (head->val);
}

int	ft_length(t_stack *head)
{
	int	count;

	count = 0;
	while (head)
	{
		count++;
		head = head->next;
	}
	return (count);
}
