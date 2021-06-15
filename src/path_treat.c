/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_path_treat.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eerika <eerika@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/10 16:46:19 by eerika            #+#    #+#             */
/*   Updated: 2021/06/10 16:46:28 by eerika           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

static char	*handling_path(char *str)
{
	char	*res;
	int		i;
	int		j;

	res = (char *)malloc(ft_strlen(str) - 3);
	if (!res)
		return (NULL);
	i = 5;
	j = 0;
	while (str[i])
	{
		res[j] = str[i];
		i++;
		j++;
	}
	return (res);
}

char	**get_path(char **env)
{
	char	**path;
	char	*tmp_path;
	int		i;

	i = 0;
	while (env[i])
	{
		if (!ft_strncmp("PATH", env[i], 4))
		{
			tmp_path = handling_path(env[i]);
			path = ft_split(tmp_path, ':');
			free(tmp_path);
		}
		i++;
	}
	i = 0;
	while (path[i])
	{
		path[i] = ft_strjoin(path[i], "/");
		i++;
	}
	return (path);
}

char	*test_path(char **path, char *cmd)
{
	int	i;
	int	fd;

	i = 0;
	while (path[i])
	{
		path[i] = ft_strjoin(path[i], cmd);
		fd = open(path[i], O_RDONLY);
		if (fd != -1)
		{
			close(fd);
			return (path[i]);
		}
		i++;
	}
	ft_putstr(cmd);
	ft_putstr(": command not found");
	return (NULL);
}
