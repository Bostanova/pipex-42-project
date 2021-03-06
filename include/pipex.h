/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eerika <eerika@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/21 18:46:21 by eerika            #+#    #+#             */
/*   Updated: 2021/09/23 14:51:56 by eerika           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <errno.h>

char	**ft_split(char const *s, char c);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
size_t	ft_strlen(const char *str);
char	*ft_join(char const *s1, char const *s2);
void	exec_process(char **cmd1, char **cmd2, int *fd_in_out);
int		ft_putstr(char *str);
char	*ft_copy(char *str, int start);
void	ft_error(int err, char *str);
void	free_array(char **arr);

#endif