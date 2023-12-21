/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vietnguy <vietnguy@42mail.sutd.edu.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 14:38:12 by vietnguy          #+#    #+#             */
/*   Updated: 2023/12/21 16:14:00 by vietnguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/libft.h"
#include "../lib/push_swap.h"
#include <limits.h>

int	find_min(int *nums, int size, int *visited)
{
	int	i;
	int	loc;
	int	min_v;

	min_v = INT_MAX;
	loc = 0;
	i = 0;
	while (i < size)
	{
		if (!visited[i] && min_v > nums[i])
		{
			min_v = nums[i];
			loc = i;
		}
		i++;
	}
	return (loc);
}

int	has_duplicate(int *nums, int size)
{
	int	i;
	int	j;

	i = 0;
	while (i < size)
	{
		j = i + 1;
		while (j < size)
		{
			if (nums[i] == nums[j])
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	verify_sorted(t_stack *head)
{
	if (head == NULL || head->next == NULL)
		return (1);
	while (head->next)
	{
		if (head->val > head->next->val)
			return (0);
		head = head->next;
	}
	return (1);
}
