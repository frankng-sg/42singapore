/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_start.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vietnguy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 20:55:03 by vietnguy          #+#    #+#             */
/*   Updated: 2023/07/12 22:37:28 by vietnguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_bsq.h"

int	ft_check_valid_board(char *str, t_instr *info)
{
	int	mapsize;
	
	mapsize = info->length + info->height * (info->height + 1);
	if (ft_strlen(str) != mapsize)
		return (0);
	str += info->length;
	while (*str)
	{
		if (*str != '\n' && *str != info->empty && \
			*str != info->obst && *str != info->full)
			return (0);
		str++;
	}
	return (1);
}

void	ft_start(char *str)
{
	t_instr		*info;
	t_record	*record;

	info = ft_first_line(str);
	record = ft_new_record();
	if (info && info->height > 0 && ft_check_valid_board(str, info))
	{
		info->width = info->height;
		ft_get_record(info, str, record);
		ft_fill_board(record, str, info);
		ft_putstrsc(str, info->length, info->height * (info->height + 1));
	}
	else
		ft_putstr("map error\n");
	free(record);
	free(info);
}
