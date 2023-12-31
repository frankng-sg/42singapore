/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atod.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vietnguy <vietnguy@student.42singapore.sg  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/31 00:21:58 by vietnguy          #+#    #+#             */
/*   Updated: 2023/12/31 10:27:53 by vietnguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

double	ft_atod(char *str)
{
	double	number;
	double	n;
	int		signal;
	int		i;

	signal = 1;
	number = 0;
	n = 1;
	i = 0;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i++] == '-')
			signal = -1;
	}
	while ((str[i] >= '0' && str[i] <= '9') && str[i] != 0)
		number = number * 10 + (str[i++] - '0');
	if (str[i] == '.')
		i++;
	while ((str[i] >= '0' && str[i] <= '9') && str[i] != 0)
	{
		number = number + (str[i++] - '0') * 0.1 * n;
		n /= 10;
	}
	return (number * signal);
}
