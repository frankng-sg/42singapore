/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vietnguy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 11:40:59 by vietnguy          #+#    #+#             */
/*   Updated: 2023/12/07 22:00:25 by vietnguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/gnl.h"
#include "../lib/libft.h"
#include "../lib/pipex.h"

int	main(int argc, char *argv[], char *envp[])
{
	int		fin;
	int		fout;
	char	*path;

	if (argc != 5)
		return (ft_puterr(PARAMS_MISMATCHED));
	fin = open(argv[1], O_RDONLY);
	if (fin < 0)
		return (ft_puterr(INVALID_FILE));
	fout = open(argv[4], O_WRONLY | O_CREAT);
	if (fout < 0)
		return (ft_puterr(INVALID_FILE));
	while (envp != NULL && *envp != NULL)
	{
		if (strncmp(*envp, "PATH=", (size_t)5) == 0)
		{
			path = *envp;
			break ;
		}
	}
	printf("%d %d %s", fin, fout, path);
	return (0);
}
