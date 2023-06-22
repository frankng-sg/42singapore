/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_params.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vietnguy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 11:58:22 by vietnguy          #+#    #+#             */
/*   Updated: 2023/06/29 15:48:38 by vietnguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putstr(char *str)
{
	while (*str != 0)
		write(1, str++, 1);
}

int	main(int argc, char *argv[])
{
	while (--argc > 0)
	{
		ft_putstr((char *)argv[argc]);
		ft_putstr("\n");
	}
}
