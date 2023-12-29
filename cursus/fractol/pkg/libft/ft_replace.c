/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_replace.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vietnguy <vietnguy@42mail.sutd.edu.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 22:56:57 by vietnguy          #+#    #+#             */
/*   Updated: 2023/12/22 22:58:14 by vietnguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_replace(char *s, char src, char dst)
{
	if (s == NULL)
		return ;
	while (*s)
	{
		if (*s == src)
			*s = dst;
		s++;
	}
}
