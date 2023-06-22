/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vietnguy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 22:00:07 by vietnguy          #+#    #+#             */
/*   Updated: 2023/06/28 20:16:22 by vietnguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isspace(char c)
{
	if (c == '\t' || c == '\n' || c == '\v')
		return (1);
	if (c == '\f' || c == '\r' || c == ' ')
		return (1);
	return (0);
}

int	strtoi(char *str)
{
	int	num;

	num = 0;
	while (*str >= '0' && *str <= '9')
	{
		num = num * 10 + *str - '0';
		str += 1;
	}
	return (num);
}

int	ft_atoi(char *str)
{
	int	sign;

	while (ft_isspace(*str))
		str += 1;
	sign = 0;
	while (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign++;
		str += 1;
	}
	if (sign % 2 == 1)
		sign = -1;
	else
		sign = 1;
	return (sign * strtoi(str));
}
