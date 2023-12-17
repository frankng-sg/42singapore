/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vietnguy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 11:40:59 by vietnguy          #+#    #+#             */
/*   Updated: 2023/12/17 07:57:36 by vietnguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/gnl.h"
#include "../lib/libft.h"
#include "../lib/pipex.h"

int	run_cmd(char *cmd, int infd, int outfd, char **envp)
{
	char	**cmd_args;
	char	*cmd_name;
	char	*cmd_path;
	char	**paths;

	dup2(infd, 0);
	dup2(outfd, 1);
	paths = find_cmd_paths(envp);
	cmd_args = ft_split(cmd, ' ');
	cmd_name = cmd_args[0];
	cmd_path = locate_cmd(paths, cmd_name);
	if (cmd_path)
	{
		execve(cmd_path, cmd_args, envp);
		free(cmd_path);
	}
	else
		ft_puterr(ERR_INVALID_CMD);
	free2(paths);
	free2(cmd_args);
	return (0);
}

void	pipex(int fin, int fout, int pipefd[2])
{
	pid_t	pid;

	pid = fork();
	if (pid < 0)
		return (ft_puterr(ERR_FORK), 1);
	if (pid == 0)
		run_cmd(argv[2], fin, pipefd[1], envp);
	else
	{
		close(pipefd[1]);
		run_cmd(argv[3], pipefd[0], fout, envp);
	}
	close(fin);
	close(fout);
}

int	main(int argc, char **argv, char **envp)
{
	int		pipefd[2];
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
	pipex(fin, fout, pipefd);
	return (0);
}
