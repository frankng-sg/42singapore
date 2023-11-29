/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vietnguy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 11:40:59 by vietnguy          #+#    #+#             */
/*   Updated: 2023/11/29 16:13:24 by vietnguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/gnl.h"
#include "../lib/libft.h"
#include "../lib/pipex.h"

int	main(int argc, char *argv[], char *envp[])
{
	int	fin;
	int	fout;

	if (argc != 5)
		return (ft_puterr(PARAMS_MISMATCHED));
	if ((fin = open(argv[1], O_RDONLY)) < 0)
		return (ft_puterr(INVALID_FILE));
	if ((fout = open(argv[4], O_WRONLY | O_CREAT)) < 0)
		return (ft_puterr(INVALID_FILE)); 
	if (envp == NULL)
	{}
	return (0);
}
