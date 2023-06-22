/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_views.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vietnguy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/01 17:29:26 by vietnguy          #+#    #+#             */
/*   Updated: 2023/07/01 19:26:22 by vietnguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "helpers.h"

void	ft_do_readview(char **argv, int *view, int size)
{
	int	i;

	i = 1;
	while (i <= size)
	{
		view[i] = **argv - '0';
		*argv += 2;
		i++;
	}
}

void	ft_readview(char *argv, t_boardstat *s)
{
	ft_do_readview(&argv, s->upview, s->size);
	ft_do_readview(&argv, s->downview, s->size);
	ft_do_readview(&argv, s->leftview, s->size);
	ft_do_readview(&argv, s->rightview, s->size);
}
