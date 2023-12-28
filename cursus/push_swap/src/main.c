/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vietnguy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 11:40:59 by vietnguy          #+#    #+#             */
/*   Updated: 2023/12/28 23:02:16 by vietnguy         ###   ########.fr       */
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

void	ft_free2(char **nums)
{
	char	**p;

	if (nums == NULL)
		return ;
	p = nums;
	while (*p)
	{
		free(*p);
		p++;
	}
	free(nums);
}

int	ft_len(char **nums)
{
	int	cnt;

	if (nums == NULL)
		return (0);
	cnt = 0;
	while (*nums)
	{
		nums++;
		cnt++;
	}
	return (cnt);
}

int	main(int argc, char **argv)
{
	t_stack	*a;
	char		**nums;

	if (argc <= 1 || !argv)
		return (0);
	nums = NULL;
	if (argc == 2)
	{
		nums = ft_split(argv[1], ' ');
		argc = ft_len(nums);
		a = init_stack(argc, nums);
	}
	else
	{
		argc--;
		a = init_stack(argc, argv + 1);
	}
	if (a == NULL)
		return (ft_printf(ERR_MSG), 0);
	a = ft_sort(a, argc);
	ft_free_stack(a);
	ft_free2(nums);
	return (0);
}
