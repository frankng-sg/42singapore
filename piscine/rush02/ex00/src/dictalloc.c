/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dictalloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vietnguy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/09 19:15:54 by vietnguy          #+#    #+#             */
/*   Updated: 2023/07/09 19:18:27 by vietnguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "rush02.h"

void	ft_free_dict(t_record *dict)
{
	int	i;

	i = 0;
	while (dict[i].val != 0)
	{
		free(dict[i].val);
		i++;
	}
	free(dict);
}
