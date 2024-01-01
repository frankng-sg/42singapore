/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vietnguy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 11:40:59 by vietnguy          #+#    #+#             */
/*   Updated: 2024/01/01 13:15:09 by vietnguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/gnl.h"
#include "../lib/libft.h"
#include "../lib/pipex.h"

char	**ft_split_cmd_args(char *s)
{
	int		size;
	char	*p;
	char	**cmd_args;

	if (s == NULL || *s == 0)
		return (NULL);
	p = s;
	while (*p && *p != ' ')
		p++;
	if (*p == 0)
		size = 2;
	else
		size = 3;
	cmd_args = (char **)malloc(size * sizeof(char *));
	cmd_args[size - 1] = 0;
	cmd_args[0] = ft_strndup(s, p - s);
	if (*p && p[1])
		cmd_args[1] = ft_strdup_ignore(p + 1, '"');
	return (cmd_args);
}

int	run_cmd(char *cmd, int infd, int outfd, char **envp)
{
	char	**cmd_args;
	char	*cmd_name;
	char	*cmd_path;
	char	**paths;
	int		status;

	dup2(infd, 0);
	dup2(outfd, 1);
	paths = find_cmd_paths(envp);
	cmd_args = ft_split_cmd_args(cmd);
	cmd_name = cmd_args[0];
	cmd_path = locate_cmd(paths, cmd_name);
	free(paths);
	status = 0;
	if (cmd_path)
		status = execve(cmd_path, cmd_args, NULL);
	else
		ft_puterr(ERR_INVALID_CMD);
	if (cmd_path)
		free(cmd_path);
	free2(cmd_args);
	return (status);
}

int	pipex(t_params g)
{
	pid_t	pid;
	int		status;

	status = 0;
	pid = fork();
	if (pid < 0)
		ft_puterr(ERR_FORK);
	else if (pid == 0)
		run_cmd(g.argv[2], g.fin, g.pipefd[1], g.envp);
	else
	{
		close(g.pipefd[1]);
		status = run_cmd(g.argv[3], g.pipefd[0], g.fout, g.envp);
	}
	close(g.fin);
	close(g.fout);
	return (status);
}

int	main(int argc, char **argv, char **envp)
{
	t_params	g;

	if (argc != 5)
		return (ft_puterr(ERR_INVALID_PARAMS));
	if (pipe(g.pipefd) < 0)
		return (ft_puterr(ERR_PIPE));
	g.fin = open(argv[1], O_RDONLY);
	if (g.fin < 0)
		return (ft_puterr(ERR_INVALID_FILE));
	g.fout = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (g.fout < 0)
		return (ft_puterr(ERR_INVALID_FILE));
	g.argv = argv;
	g.envp = envp;
	if (pipex(g) < 0)
	{
		unlink(argv[4]);
		return (ft_puterr(ERR_SOMETHING_WENT_WRONG));
	}
	return (0);
}
