/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eerika <eerika@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/21 18:45:14 by eerika            #+#    #+#             */
/*   Updated: 2021/09/23 15:39:27 by eerika           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex_bonus.h"

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
	char	*res;
	int		i;
	int		j;

	i = 0;
	while (path[i])
	{
		path[i] = ft_join(path[i], cmd);
		if (!(access(path[i], X_OK)))
		{
			res = (char *)malloc(ft_strlen(path[i] + 1));
			j = 0;
			while (path[i][j])
			{
				res[j] = path[i][j];
				j++;
			}
			res[j] = '\0';
			return (res);
		}	
		i++;
	}
	ft_error(3, cmd);
	return (NULL);
}

static int	prepare(int argc, char **argv, int *infile_fd, int *outfile_fd)
{
	char	j;

	if (argc < 6)
		ft_error(2, NULL);
	j = 1;
	if (!(ft_strcmp("here_doc", argv[1]) && argv[2]))
	{
		here_doc(argv);
		*outfile_fd = open(argv[argc - 1], O_WRONLY | O_CREAT | O_APPEND, 0777);
		j += 2;
	}
	else
	{
		*infile_fd = open(argv[1], O_RDONLY);
		dup2(*infile_fd, STDIN_FILENO);
		close(*infile_fd);
		*outfile_fd = open(argv[argc - 1], O_WRONLY | O_CREAT | O_TRUNC, 0777);
		j++;
	}
	return (j);
}

int	main(int argc, char **argv, char **env)
{
	char	**path;
	int		j;
	int		in_out[2];
	char	**cmd;
	char	*tmp;

	j = prepare(argc, argv, &in_out[0], &in_out[1]);
	while (j < argc - 1)
	{
		path = get_path(env);
		cmd = ft_split(argv[j], ' ');
		tmp = cmd[0];
		cmd[0] = test_path(path, cmd[0]);
		if (j == argc - 2)
			write_outfile(cmd[0], cmd, env, in_out[1]);
		else
			exec_cmd(cmd[0], cmd, env);
		j++;
		free_array(cmd);
		free_array(path);
		free(tmp);
	}
	sleep(500);
	return (EXIT_SUCCESS);
}
