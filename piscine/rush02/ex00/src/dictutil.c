/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dictutil.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vietnguy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/09 20:01:42 by vietnguy          #+#    #+#             */
/*   Updated: 2023/07/09 20:10:18 by vietnguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"
#include "stdlib.h"

char	*ft_get_val(t_record *dict, long long key)
{
	int	i;

	i = 0;
	while (dict[i].val != 0)
	{
		if (dict[i].key == key)
			return (dict[i].val);
		i++;
	}
	return (NULL);
}

int	ft_count_valid_dict_records(char **strs)
{
	int	count;

	count = 0;
	while (*strs != 0)
	{
		if (!ft_valid_dict_format(*strs))
			return (-1);
		count++;
		strs++;
	}
	return (count);
}
