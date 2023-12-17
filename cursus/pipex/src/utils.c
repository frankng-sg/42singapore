/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vietnguy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 11:40:59 by vietnguy          #+#    #+#             */
/*   Updated: 2023/12/17 07:58:04 by vietnguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/gnl.h"
#include "../lib/libft.h"
#include "../lib/pipex.h"

char	*find_env_path(char **envp)
{
	while (envp && *envp)
	{
		if (strncmp(*envp, "PATH=", 5) == 0)
		{
			return (ft_strdup(&(*envp)[5]));
		}
		envp++;
	}
	return (NULL);
}

void	free2(char **v)
{
	char	**p;

	if (!v)
		return ;
	p = v;
	while (*v)
	{
		free(*v);
		v++;
	}
	free(p);
}

char	**find_cmd_paths(char **envp)
{
	char	**paths;
	char	*path;

	path = find_env_path(envp);
	paths = ft_split(path, ':');
	if (path)
		free(path);
	return (paths);
}

char	*locate_cmd(char **paths, char *cmd)
{
	char	*_cmd;
	char	*cmd_path;

	_cmd = ft_strjoin("/", cmd);
	cmd_path = NULL;
	while (paths && *paths)
	{
		cmd_path = ft_strjoin(*paths, _cmd);
		if (access(cmd_path, X_OK) >= 0)
			break ;
		free(cmd_path);
		cmd_path = NULL;
		paths++;
	}
	free(_cmd);
	return (cmd_path);
}
