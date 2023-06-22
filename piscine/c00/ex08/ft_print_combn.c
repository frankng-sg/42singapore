/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vietnguy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 17:07:51 by vietnguy          #+#    #+#             */
/*   Updated: 2023/06/22 19:04:02 by vietnguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	gen_num(char *num, char initial_value, int i, int n)
{
	if (i >= n)
		return ;
	num[i] = initial_value;
	while (num[i] <= '9')
	{
		if (i == n - 1)
		{
			write(1, num, n);
			if (num[0] < '9' - n + 1)
				write(1, ", ", 2);
		}
		else
		{
			gen_num(num, num[i] + 1, i + 1, n);
		}
		num[i]++;
	}
}

void	ft_print_combn(int n)
{
	char	num[10];

	gen_num(num, '0', 0, n);
}
