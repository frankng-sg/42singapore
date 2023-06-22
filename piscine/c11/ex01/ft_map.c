/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vietnguy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 20:08:51 by vietnguy          #+#    #+#             */
/*   Updated: 2023/07/12 20:10:57 by vietnguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_map(int *tab, int length, int (*f)(int))
{
	int	*ret;
	int	i;

	ret = (int *)malloc(sizeof(int) * length);
	i = -1;
	while (++i < length)
		ret[i] = f(tab[i]);
	return (ret);
}
