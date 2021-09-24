/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eerika <eerika@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/23 13:44:53 by eerika            #+#    #+#             */
/*   Updated: 2021/09/23 13:44:54 by eerika           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex_bonus.h"
#include "../include/get_next_line.h"

void	exec_cmd(char *path, char **cmd, char **env)
{
	pid_t	pid;
	int		fd[2];

	pipe(fd);
	pid = fork();
	if (pid == 0)
	{
		close(fd[0]);
		dup2(fd[1], STDOUT_FILENO);
		close(fd[1]);
		execve(path, cmd, env);
	}
	else
	{
		close(fd[1]);
		dup2(fd[0], STDIN_FILENO);
		close(fd[0]);
		waitpid(pid, NULL, 0);
	}
}

void	write_outfile(char *path, char **cmd, char **env, int outfile_fd)
{
	pid_t	pid;

	pid = fork();
	if (pid == 0)
	{
		dup2(outfile_fd, STDOUT_FILENO);
		execve(path, cmd, env);
	}
	else
		waitpid(pid, NULL, 0);
}

static int	get_line(char **line)
{
	char	*buffer;
	int		i;
	int		r;
	char	c;

	i = 0;
	r = 0;
	buffer = (char *)malloc(10000);
	if (!buffer)
		return (-1);
	r = read(0, &c, 1);
	while (r && c != '\n' && c != '\0')
	{
		if (c != '\n' && c != '\0')
			buffer[i] = c;
		i++;
		r = read(0, &c, 1);
	}
	buffer[i] = '\n';
	buffer[++i] = '\0';
	*line = buffer;
	free(buffer);
	return (r);
}

void	here_doc(char **argv)
{
	pid_t	pid;
	int		fd[2];
	char	*line;

	pipe(fd);
	pid = fork();
	if (pid == 0)
	{
		close(fd[0]);
		while (get_line(&line))
		{
			if (ft_strncmp(line, argv[2], ft_strlen(argv[2])) == 0)
				exit(EXIT_SUCCESS);
			write(fd[1], line, ft_strlen(line));
		}
	}
	else
	{
		close(fd[1]);
		dup2(fd[0], STDIN_FILENO);
		wait(NULL);
	}
}
