/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_program_name.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vietnguy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 11:46:31 by vietnguy          #+#    #+#             */
/*   Updated: 2023/06/29 11:46:33 by vietnguy         ###   ########.fr       */
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
	if (argc < 0)
		return (1);
	ft_putstr(argv[0]);
	ft_putstr("\n");
	return (0);
}
