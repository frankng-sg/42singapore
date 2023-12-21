/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vietnguy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 11:40:59 by vietnguy          #+#    #+#             */
/*   Updated: 2023/12/21 17:45:37 by vietnguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/libft.h"
#include "../lib/push_swap.h"
#include <stdio.h>
#include <limits.h>

void	reindex(int *nums, int lnums)
{
	int	i;
	int	loc;
	int	visited[MAX_SIZE];

	i = 0;
	while (i < lnums)
		visited[i++] = 0;
	i = 0;
	while (i < lnums)
	{
		loc = find_min(nums, lnums, visited);
		visited[loc] = 1;
		nums[loc] = i;
		i++;
	}
}

t_stack	*init_stack(int size, char **s)
{
	t_stack	*result;
	int		*nums;
	int		lnums;
	int		i;

	nums = (int *)malloc((size + 1) * sizeof(int));
	lnums = 0;
	while (--size >= 0)
	{
		if (!ft_atoi2(s[size], nums + lnums))
		{
			free(nums);
			return (NULL);
		}
		lnums++;
	}
	result = NULL;
	if (!has_duplicate(nums, lnums))
	{
		reindex(nums, lnums);
		i = 0;
		while (i < lnums)
			result = ft_push(result, nums[i++]);
	}
	return (free(nums), result);
}

int	main(int argc, char **argv)
{
	t_stack	*a;

	if (argc <= 1 || !argv)
		return (0);
	a = init_stack(argc - 1, argv + 1);
	if (a == NULL)
		return (ft_printf(ERR_MSG), 0);
	a = ft_sort(a, argc - 1);
	ft_free_stack(a);
	return (0);
}
