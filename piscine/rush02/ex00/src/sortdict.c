/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sortdict.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vietnguy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/08 16:17:42 by vietnguy          #+#    #+#             */
/*   Updated: 2023/07/08 18:41:44 by vietnguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

int	ft_dictkeycmp(t_record k1, t_record k2)
{
	if (k1.key < k2.key)
		return (1);
	if (k1.key > k2.key)
		return (-1);
	return (0);
}

int	ft_dictlen(t_record *dict)
{
	int	len;

	len = 0;
	while (dict[len].val != 0)
		len++;
	return (len);
}

void	ft_swapkv(t_record *r1, t_record *r2)
{
	int		keytmp;
	char	*valtmp;

	keytmp = r1->key;
	r1->key = r2->key;
	r2->key = keytmp;
	valtmp = r1->val;
	r1->val = r2->val;
	r2->val = valtmp;
}

void	ft_sortdict(t_record *dict)
{
	int		found;
	int		i;
	int		size;

	size = ft_dictlen(dict);
	size--;
	while (1)
	{
		found = 0;
		i = 0;
		while (i < size)
		{
			if (ft_dictkeycmp(dict[i], dict[i + 1]) > 0)
			{
				ft_swapkv(&dict[i], &dict[i + 1]);
				found = 1;
			}
			i++;
		}
		if (!found)
			break ;
	}	
}
