/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vietnguy <vietnguy@student.42singapore.sg  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 17:34:10 by vietnguy          #+#    #+#             */
/*   Updated: 2023/12/20 09:08:43 by vietnguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"
#include <limits.h>

static int	ft_isspace(char c)
{
	return (c == ' ' || c == '\n' || c == '\t' \
		|| c == '\v' || c == '\r' || c == '\f');
}

int	ft_atoi(const char *str)
{
	int	sign;
	int	res;

	while (ft_isspace(*str))
		str++;
	sign = 1;
	if (*str == '-')
	{
		sign = -1;
		str++;
	}
	else if (*str == '+')
		str++;
	res = 0;
	while (ft_isdigit(*str))
		res = res * 10 + *str++ - '0';
	return (res * sign);
}

int	ft_atoi2(const char *str, int *num)
{
	long	sign;
	long	res;

	sign = 1;
	if (*str == '-')
	{
		sign = -1;
		str++;
	}
	else if (*str == '+')
		str++;
	if (!ft_isdigit(*str))
		return (0);
	res = 0;
	while (ft_isdigit(*str))
		res = res * 10 + (long)(*str++ - '0');
	if (*str)
		return (0);
	res = res * sign;
	if (res < INT_MIN || res > INT_MAX)
		return (0);
	*num = res;
	return (1);
}
