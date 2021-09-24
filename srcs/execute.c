/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eerika <eerika@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/22 10:55:37 by eerika            #+#    #+#             */
/*   Updated: 2021/09/22 10:55:40 by eerika           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

static void	helper(char **cmd1, char **cmd2, int *fd_in_out, int *fd)
{	
	pid_t	pid;

	pid = fork();
	if (pid == -1)
		exit(EXIT_FAILURE);
	if (pid == 0)
	{
		close(fd[0]);
		dup2(fd[1], 1);
		dup2(fd_in_out[0], 0);
		close(fd[1]);
		execve(cmd1[0], cmd1, NULL);
		exit(EXIT_FAILURE);
	}
	else
	{
		close(fd[1]);
		dup2(fd[0], 0);
		dup2(fd_in_out[1], 1);
		close(fd[0]);
		close(fd_in_out[1]);
		execve(cmd2[0], cmd2, NULL);
		exit(EXIT_FAILURE);
	}
}

void	exec_process(char **cmd1, char **cmd2, int *fd_in_out)
{
	int		fd[2];

	if (pipe(fd) != 0)
		exit(EXIT_FAILURE);
	helper(cmd1, cmd2, fd_in_out, fd);
}
