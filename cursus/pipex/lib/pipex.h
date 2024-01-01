/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vietnguy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 15:10:34 by vietnguy          #+#    #+#             */
/*   Updated: 2024/01/01 13:19:11 by vietnguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef PIPEX_H
# define PIPEX_H

# include <stdio.h>
# include <sys/wait.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>

# define ERR_INVALID_PARAMS "pipex: invalid parameters"
# define ERR_INVALID_FILE "pipex: no such file or directory"
# define ERR_INVALID_CMD "pipex: command not found"
# define ERR_SOMETHING_WENT_WRONG "pipex: something went wrong"
# define ERR_PIPE "pipex: pipe error"
# define ERR_FORK "pipex: fork error"

typedef struct s_params
{
	int		fin;
	int		fout;
	char	**argv;
	char	**envp;
	int		pipefd[2];
}	t_params;

char	*find_env_path(char **envp);
char	**find_cmd_paths(char **envp);
void	free2(char **v);
char	*locate_cmd(char **paths, char *cmd);

#endif
