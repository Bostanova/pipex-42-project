/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eerika <eerika@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/10 16:46:42 by eerika            #+#    #+#             */
/*   Updated: 2021/06/10 16:46:51 by eerika           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

int	main(int argc, char *argv[], char *env[])
{
	t_cmd	cmd;
	char	**path1;
	char	**path2;
	int		fd_in_out[2];

	if (argc == 5)
	{
		cmd.cmd1 = ft_split(argv[2], ' ');
		cmd.cmd2 = ft_split(argv[3], ' ');
		path1 = get_path(env);
		path2 = get_path(env);
		cmd.cmd1[0] = test_path(path1, cmd.cmd1[0]);
		cmd.cmd2[0] = test_path(path2, cmd.cmd2[0]);
		fd_in_out[0] = open(argv[1], O_RDONLY);
		if (fd_in_out[0] == -1)
		{
			perror(argv[1]);
			exit(EXIT_FAILURE);
		}
		fd_in_out[1] = open(argv[4], O_WRONLY | O_TRUNC | O_CREAT, 0644);
		exec_process(cmd, fd_in_out);
	}
	else
		ft_putstr("Error: more or less than five arguments");
	return (0);
}
