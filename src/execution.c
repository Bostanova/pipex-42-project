/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eerika <eerika@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/10 16:41:13 by eerika            #+#    #+#             */
/*   Updated: 2021/06/10 16:41:26 by eerika           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

static void	helper(t_cmd cmd, int *fd_in_out, int *fd, pid_t pid)
{
	if (pid == 0)
	{
		close(fd[0]);
		dup2(fd[1], 1);
		dup2(fd_in_out[0], 0);
		close(fd[1]);
		execve(cmd.cmd1[0], cmd.cmd1, NULL);
		exit(EXIT_FAILURE);
	}
	else
	{
		close(fd[1]);
		dup2(fd[0], 0);
		dup2(fd_in_out[1], 1);
		close(fd[0]);
		execve(cmd.cmd2[0], cmd.cmd2, NULL);
		exit(EXIT_FAILURE);
	}
}

void	exec_process(t_cmd cmd, int *fd_in_out)
{
	int		fd[2];
	pid_t	pid;

	if (pipe(fd) != 0)
		exit(EXIT_FAILURE);
	pid = fork();
	if (pid == -1)
		exit(EXIT_FAILURE);
	helper(cmd, fd_in_out, fd, pid);
}
