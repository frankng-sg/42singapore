/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vietnguy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 15:10:34 by vietnguy          #+#    #+#             */
/*   Updated: 2023/12/16 11:39:19 by vietnguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef PIPEX_H
# define PIPEX_H

# include <stdio.h>
# include <sys/wait.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>

# define INVALID_PARAMS "invalid parameters"
# define ERR_OPENING_FILE "error opening file"

typedef struct	s_global
{
	char	**envp;
	char	**cmd_args[2];
	char	*cmd[2];
	char	**paths;
	int		pipefd[2];
	int		fin;
	int		fout;
} t_global;

#endif
