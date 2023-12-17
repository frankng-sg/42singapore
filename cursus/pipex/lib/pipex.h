/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vietnguy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 15:10:34 by vietnguy          #+#    #+#             */
/*   Updated: 2023/12/17 07:50:32 by vietnguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef PIPEX_H
# define PIPEX_H

# include <stdio.h>
# include <sys/wait.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>

# define ERR_INVALID_PARAMS "invalid parameters"
# define ERR_INVALID_FILE "no such file or directory"
# define ERR_INVALID_CMD "command not found"
# define ERR_PIPE "pipe error"
# define ERR_FORK "fork error"

char	*find_env_path(char **envp);
char	**find_cmd_paths(char **envp);
void	free2(char **v);
char	*locate_cmd(char **paths, char *cmd);

#endif
