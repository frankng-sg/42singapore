/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vietnguy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 11:40:59 by vietnguy          #+#    #+#             */
/*   Updated: 2023/12/10 17:12:23 by vietnguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/gnl.h"
#include "../lib/libft.h"
#include "../lib/pipex.h"

int	run_cmd(t_global *g, int infd, int outfd, char *cmd, char **args)
{
	int	pid;

	pid = fork();
	if (pid == 0)
	{
		dup2(infd, 0);
		dup2(outfd, 1);
		close(g->pipefd[0]);
		close(g->pipefd[1]);
		execve(cmd, args, g->envp);
		exit(0);
	}
	return (pid);
}

int	main(int argc, char **argv, char **envp)
{
	int	pid1;
	int	pid2;
	int	fin;
	int	fout;
	char	*cmd1 = "/usr/bin/cat";
	char	*arg1[2] = {"/usr/bin/cat", NULL};
	char	*cmd2 = "/usr/bin/wc";
	char	*arg2[2] = {"/usr/bin/wc", NULL};
	t_global	g;

	if (argc <= 0 || argv == NULL)
		return (0);
	pipe(g.pipefd);
	fin = open("input.txt", O_RDONLY);
	if (fin < 0)
	{
		perror("fin");
		exit(1);
	}
	fout = open("output.txt", O_CREAT | O_WRONLY | O_TRUNC, 0644);
	if (fout < 0)
	{
		perror("fout");
		exit(1);
	}
	g.envp = envp;
	pid1 = run_cmd(&g, fin, g.pipefd[1], cmd1, arg1);
	pid2 = run_cmd(&g, g.pipefd[0], fout, cmd2, arg2);
	close(g.pipefd[0]);
	close(g.pipefd[1]);
	waitpid(pid2, NULL, 0);
	waitpid(pid1, NULL, 0);
	close(fin);
	close(fout);

}
