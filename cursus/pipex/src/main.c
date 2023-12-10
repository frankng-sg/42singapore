/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vietnguy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 11:40:59 by vietnguy          #+#    #+#             */
/*   Updated: 2023/12/16 11:37:49 by vietnguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/gnl.h"
#include "../lib/libft.h"
#include "../lib/pipex.h"

char	*find_path_str(char **envp)
{
	while (envp && *envp)
	{
		if (strncmp(*envp, "PATH=", 5) == 0)
			return (*envp);
		envp++;
	}
	return (NULL);
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

int	run_cmd(t_global *g, int infd, int outfd, char *cmd, char **args)
{
	int		pid;
	char	*cmd_path;

	pid = fork();
	if (pid == 0)
	{
		dup2(infd, 0);
		dup2(outfd, 1);
		close(g->pipefd[1]);
		cmd_path = locate_cmd(g->paths, cmd);
		execve(cmd_path, args, g->envp);
		exit(0);
	}
	return (pid);
}

int	ft_error(char *err)
{
	ft_puterr(err);
	return (1);
}

int	init_g(t_global *g, int argc, char **argv, char **envp)
{
	if (argc != 5)
		return (ft_error(INVALID_PARAMS));
	g->fin = open(argv[1], O_RDONLY);
	if (g->fin < 0)
		return (ft_error(ERR_OPENING_FILE));
	g->fout = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (g->fout < 0)
		return (ft_error(ERR_OPENING_FILE));
	if (pipe(g->pipefd) < 0)
		return (ft_error("pipe"));		
	g->envp = envp;
	g->paths = ft_split(find_path_str(envp), ':');
	g->cmd_args[0] = ft_split(argv[2], ' ');
	g->cmd_args[1] = ft_split(argv[3], ' ');
	g->cmd[0] = g->cmd_args[0][0];
	g->cmd[1] = g->cmd_args[1][0];
	return (0);
}

void	free_g(t_global *g)
{
	close(g->fin);
	close(g->fout);
}

int	main(int argc, char **argv, char **envp)
{
	int		pid1;
	int		pid2;
	t_global	g;

	if (init_g(&g, argc, argv, envp))
		return (1);
	g.envp = envp;
	pid1 = run_cmd(&g, g.fin, g.pipefd[1], g.cmd[0], g.cmd_args[0]);
	pid2 = run_cmd(&g, g.pipefd[0], g.fout, g.cmd[1], g.cmd_args[1]);
	close(g.pipefd[1]);
	waitpid(pid2, NULL, 0);
	waitpid(pid1, NULL, 0);
	free_g(&g);	
	return (0);
}
