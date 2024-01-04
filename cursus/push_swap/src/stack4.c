/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack4.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vietnguy <vietnguy@42mail.sutd.edu.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 14:03:20 by vietnguy          #+#    #+#             */
/*   Updated: 2023/12/21 15:09:46 by vietnguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/libft.h"
#include "../lib/push_swap.h"

void	ft_push2(t_stack **src, t_stack **dst)
{
	int	val;

	if (src == NULL || *src == NULL)
		return ;
	val = (*src)->val;
	*src = ft_pop(*src);
	*dst = ft_push(*dst, val);
}
