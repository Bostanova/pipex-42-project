/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eerika <eerika@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/10 16:40:43 by eerika            #+#    #+#             */
/*   Updated: 2021/06/10 16:40:45 by eerika           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h> // don't forget to delete this library

typedef struct s_cmd
{
	char	**cmd1;
	char	**cmd2;
}				t_cmd;

char	**ft_split(char const *s, char c);
char	**get_path(char **env);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
size_t	ft_strlen(const char *str);
char	*ft_strjoin(char const *s1, char const *s2);
char	*test_path(char **path, char *cmd);
void	exec_process(t_cmd cmd, int *fd_in_out);
int		ft_putstr(char *str);

#endif