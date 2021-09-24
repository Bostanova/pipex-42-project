/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eerika <eerika@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/21 18:41:39 by eerika            #+#    #+#             */
/*   Updated: 2021/09/23 15:34:50 by eerika           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

static char	**get_path(char **env)
{
	int		i;
	char	**path;

	i = 0;
	path = NULL;
	while (env[i])
	{
		if (!(ft_strncmp(env[i], "PATH=", 5)))
			path = ft_split(env[i], ':');
		i++;
	}
	path[0] = ft_copy(path[0], 5);
	i = 0;
	while (path[i])
	{
		path[i] = ft_join(path[i], "/");
		i++;
	}
	return (path);
}

static char	*test_path(char **path, char *cmd)
{
	int	i;

	i = 0;
	while (path[i])
	{
		path[i] = ft_join(path[i], cmd);
		if (!(access(path[i], X_OK)))
			return (path[i]);
		i++;
	}
	ft_putstr(cmd);
	ft_putstr(": command not found\n");
	return (NULL);
}

static void	open_file(int *fd_in, char *infile, int *fd_out, char *outfile)
{
	*fd_in = open(infile, O_RDONLY);
	*fd_out = open(outfile, O_WRONLY | O_TRUNC | O_CREAT, 0777);
	if (*fd_in == -1)
	{
		perror(infile);
		exit(EXIT_FAILURE);
	}
}

int	main(int argc, char *argv[], char *env[])
{
	char	**cmd1;
	char	**cmd2;
	char	**path1;
	char	**path2;
	int		fd_in_out[2];

	if (argc == 5)
	{
		cmd1 = ft_split(argv[2], ' ');
		cmd2 = ft_split(argv[3], ' ');
		path1 = get_path(env);
		path2 = get_path(env);
		cmd1[0] = test_path(path1, cmd1[0]);
		cmd2[0] = test_path(path2, cmd2[0]);
		open_file(&fd_in_out[0], argv[1], &fd_in_out[1], argv[4]);
		exec_process(cmd1, cmd2, fd_in_out);
	}
	else
		ft_putstr("Error: more or less than five arguments\n");
	return (0);
}
