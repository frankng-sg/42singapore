/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vietnguy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 11:40:59 by vietnguy          #+#    #+#             */
/*   Updated: 2023/12/20 21:48:20 by vietnguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/libft.h"
#include "../lib/push_swap.h"
#include <stdio.h>
#include <limits.h>

t_stack	*init_stack(int size, char **s)
{
	t_stack	*result;
	int		val;

	result = NULL;
	while (--size >= 0)
	{
		if (!ft_atoi2(s[size], &val) || search(result, val))
		{
			ft_free_stack(result);
			return (NULL);
		}
		result = ft_push(result, val);
	}
	return (result);
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

int	main(int argc, char **argv)
{
	t_stack	*a;

	if (argc <= 1 || !argv)
		return (0);
	a = init_stack(argc - 1, argv + 1);
	if (a == NULL)
		ft_printf(ERR_MSG);
	a = ft_sort(a);
	if (!verify_sorted(a))
		ft_printf("ERROR: NOT SORTED\n");
	ft_free_stack(a);
	return (0);
}
