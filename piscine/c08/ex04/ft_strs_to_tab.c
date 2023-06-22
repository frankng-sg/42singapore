/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs_to_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vietnguy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/02 14:18:00 by vietnguy          #+#    #+#             */
/*   Updated: 2023/07/05 19:23:49 by vietnguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_stock_str.h"

int	ft_strlen(char *str)
{
	int	len;

	len = 0;
	while (*str++ != 0)
		len++;
	return (len);
}

void	ft_strcpy(char *dest, char *src)
{
	while (*src != 0)
		*dest++ = *src++;
	*dest = 0;
}

struct s_stock_str	*ft_strs_to_tab(int ac, char **av)
{
	t_stock_str	*s;
	int			i;

	s = (t_stock_str *)malloc((ac + 1) * sizeof(t_stock_str));
	i = 0;
	while (i < ac)
	{
		s[i].size = ft_strlen(av[i]);
		s[i].str = av[i];
		s[i].copy = (char *)malloc((s[i].size + 1) * sizeof(char));
		ft_strcpy(s[i].copy, av[i]);
		i++;
	}
	s[i].str = 0;
	s[i].copy = 0;
	return (s);
}
