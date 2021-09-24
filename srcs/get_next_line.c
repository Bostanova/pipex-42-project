/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eerika <eerika@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/24 03:12:39 by eerika            #+#    #+#             */
/*   Updated: 2021/09/23 13:34:50 by eerika           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/get_next_line.h"

int	check_new_line(char *str)
{
	int			i;

	i = 0;
	if (!str)
	{
		return (0);
	}
	while (str[i] != '\0')
	{
		if (str[i] == '\n')
		{
			return (1);
		}
		i++;
	}
	return (0);
}

char	*change_alloc(char *stat_buf)
{
	int			i;
	int			j;
	char		*result;

	i = 0;
	j = 0;
	if (!stat_buf)
		return (0);
	while (stat_buf[i] != '\n' && stat_buf[i] != '\0')
		i++;
	if (stat_buf[i] == '\0')
	{
		free(stat_buf);
		return (0);
	}
	result = malloc((ft_len(stat_buf) - i) + 1);
	if (!result)
		return (0);
	i++;
	while (stat_buf[i])
		result[j++] = stat_buf[i++];
	result[j] = '\0';
	free(stat_buf);
	return (result);
}

char	*copy_from_static(char *str)
{
	int			i;
	char		*result;

	i = 0;
	if (!str)
		return (0);
	while (str[i] != '\0' && str[i] != '\n')
	{
		i++;
	}
	result = malloc(sizeof(char) * (i + 1));
	if (result == NULL)
	{
		return (0);
	}
	i = 0;
	while (str[i] != '\0' && str[i] != '\n')
	{
		result[i] = str[i];
		i++;
	}
	result[i] = '\0';
	return (result);
}

int	get_next_line(int fd, char **line)
{
	static char	*stat_buf;
	char		*buffer;
	int			len_to_eof;

	if (fd < 0 || BUFFER_SIZE <= 0 || !line)
		return (-1);
	buffer = malloc(BUFFER_SIZE + 1);
	len_to_eof = 1;
	while (!check_new_line(stat_buf) && len_to_eof != 0)
	{
		len_to_eof = read(fd, buffer, BUFFER_SIZE);
		if (len_to_eof == -1)
		{
			free(buffer);
			return (-1);
		}
		buffer[len_to_eof] = '\0';
		stat_buf = ft_strjoin(stat_buf, buffer);
	}
	free(buffer);
	*line = copy_from_static(stat_buf);
	stat_buf = change_alloc(stat_buf);
	if (len_to_eof == 0)
		return (0);
	return (1);
}
