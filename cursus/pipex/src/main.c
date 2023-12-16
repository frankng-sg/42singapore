/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vietnguy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 11:40:59 by vietnguy          #+#    #+#             */
/*   Updated: 2023/12/16 20:05:38 by vietnguy         ###   ########.fr       */
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
		paths++;
	}
	free(_cmd);
	return (cmd_path);
}

int	run_cmd(char *cmd, int infd, int outfd, char **envp, int pipefd[2])
{
	char	**cmd_args;
	char	*cmd_name;
	char	*cmd_path;
	char	**paths;

	dup2(infd, 0);
	dup2(outfd, 1);
	close(pipefd[1]);
	paths = find_cmd_paths(envp);
	cmd_args = ft_split(cmd, ' ');
	cmd_name = cmd_args[0];
	cmd_path = locate_cmd(paths, cmd_name);
	execve(cmd_path, cmd_args, envp);
	if (cmd_path)
		free(cmd_path);
	free2(paths);
	free2(cmd_args);	
	return (0);
}

int	main(int argc, char **argv, char **envp)
{
	int		pipefd[2];
	pid_t	pid;
	int		fin;
	int		fout;

	if (argc != 5)
		return (ft_puterr(ERR_INVALID_PARAMS), 1);
	if (pipe(pipefd) < 0)
		return (ft_puterr(ERR_PIPE), 1);
	fin = open(argv[1], O_RDONLY);
	if (fin < 0)
		return (ft_puterr(ERR_INVALID_FILE));
	fout = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fout < 0)
		return (ft_puterr(ERR_INVALID_FILE));
	pid = fork();
	if (pid < 0)
		return (ft_puterr(ERR_FORK), 1);
	if (pid == 0)
		run_cmd(argv[2], fin, pipefd[1], envp, pipefd);
	else
		run_cmd(argv[3], pipefd[0], fout, envp, pipefd);
	close(fin);
	close(fout);
	return (0);
}
