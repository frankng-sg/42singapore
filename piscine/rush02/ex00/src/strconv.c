/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strconv.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vietnguy <vietnguy@student.42singapore.sg  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/08 09:30:48 by vietnguy          #+#    #+#             */
/*   Updated: 2023/07/13 15:16:48 by vietnguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

char	*ft_trim(char *str)
{
	while (*str == ' ')
		str++;
	return (str);
}

long long	ft_atoi(char *str)
{
	long long	sign;
	long long	n;

	str = ft_trim(str);
	sign = 1;
	if (*str == '-')
	{
		sign = -1;
		str++;
	}
	else if (*str == '+')
		str++;
	n = 0;
	while (*str != 0 && *str >= '0' && *str <= '9')
	{
		n = n * 10 + *str - '0';
		if (n < 0)
			return (-1);
		str++;
	}
	return (sign * n);
}

int	ft_valid_number(char *str)
{
	str = ft_trim(str);
	if (*str < '0' || *str > '9')
		return (0);
	while (*str >= '0' && *str <= '9')
		str++;
	if (*str != 0 && *str != ' ')
		return (0);
	while (*str == ' ')
		str++;
	if (*str != 0)
		return (0);
	return (1);
}
