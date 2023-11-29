/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vietnguy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 11:40:59 by vietnguy          #+#    #+#             */
/*   Updated: 2023/11/29 15:43:07 by vietnguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/gnl.h"
#include "../lib/libft.h"
#include "../lib/pipex.h"

int	main(int argc, char *argv[], char *envp[])
{
	if (argc != 5)
		ft_puterr(PARAMS_MISMATCHED);
	else
	{
		ft_putstr("OK");
	}
	if (argv == NULL || envp == NULL)
	{
	}
	return (1);
}
