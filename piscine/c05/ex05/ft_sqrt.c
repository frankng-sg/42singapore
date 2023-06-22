/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vietnguy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 09:39:18 by vietnguy          #+#    #+#             */
/*   Updated: 2023/06/29 09:39:20 by vietnguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_sqrt(int nb)
{
	int	left;
	int	right;
	int	mid;

	if (nb <= 0)
		return (0);
	left = 1;
	right = nb >> 1;
	while (left < right - 1)
	{
		mid = (left + right) >> 1;
		if (mid > nb / mid)
			right = mid - 1;
		else
			left = mid;
	}
	if (left * left == nb)
		return (left);
	if (right * right == nb)
		return (right);
	return (0);
}
