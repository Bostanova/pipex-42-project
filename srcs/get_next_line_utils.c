/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eerika <eerika@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/29 10:19:29 by eerika            #+#    #+#             */
/*   Updated: 2021/09/23 12:53:24 by eerika           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/get_next_line.h"

size_t	ft_len(const char *s)
{
	int				i;

	i = 0;
	if (!s)
		return (0);
	while (s[i] != '\0')
		i++;
	return (i);
}

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*res;
	unsigned char	*str;

	i = 0;
	if (dst == NULL && src == NULL)
		return (NULL);
	res = (unsigned char *)dst;
	str = (unsigned char *)src;
	while (i < n)
	{
		((char *)dst)[i] = ((char *)src)[i];
		i++;
	}
	return (dst);
}

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t			i;
	unsigned char	*res;
	unsigned char	*str;

	i = 0;
	res = (unsigned char *)dst;
	str = (unsigned char *)src;
	if (src < dst)
	{
		while (len--)
			res[len] = str[len];
	}
	else
	{
		ft_memcpy(dst, src, len);
	}
	return (dst);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char			*result;
	size_t			s1_length;
	size_t			s2_length;

	if (!s1 && !s2)
	{
		return (0);
	}
	s1_length = ft_len((char *)s1);
	s2_length = ft_len((char *)s2);
	result = malloc(s1_length + s2_length + 1);
	if (!result)
	{
		return (0);
	}
	ft_memmove(result, s1, s1_length);
	ft_memmove(result + s1_length, s2, s2_length);
	result[s1_length + s2_length] = '\0';
	free((char *)s1);
	return (result);
}
