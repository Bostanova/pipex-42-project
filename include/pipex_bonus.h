/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eerika <eerika@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/22 10:57:28 by eerika            #+#    #+#             */
/*   Updated: 2021/09/22 12:52:01 by eerika           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_BONUS_H
# define PIPEX_BONUS_H

# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <errno.h>

int		ft_strcmp(const char *s1, const char *s2);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	**ft_split(char const *s, char c);
int		ft_putstr(char *str);
void	free_array(char **arr);
size_t	ft_strlen(const char *str);
char	*ft_join(char const *s1, char const *s2);
void	*ft_calloc(size_t count, size_t size);
void	ft_error(int err, char *str);
char	*ft_copy(char *str, int start);
void	ft_bzero(void *s, size_t n);
void	exec_cmd(char *path, char **cmd, char **env);
void	here_doc(char **argv);
void	write_outfile(char *path, char **cmd, char **env, int outfile_fd);

#endif