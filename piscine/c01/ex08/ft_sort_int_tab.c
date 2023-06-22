/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_int_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vietnguy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/25 09:49:12 by vietnguy          #+#    #+#             */
/*   Updated: 2023/06/25 09:55:44 by vietnguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	swap(int *a, int *b)
{
	int	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

void	ft_sort_int_tab(int *tab, int size)
{
	int	found;
	int	i;

	found = 1;
	while (found)
	{
		i = 1;
		found = 0;
		while (i < size)
		{
			if (tab[i - 1] > tab[i])
			{
				swap(&tab[i - 1], &tab[i]);
				found = 1;
			}
			i++;
		}
	}
}
