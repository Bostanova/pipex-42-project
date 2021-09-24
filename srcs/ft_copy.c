/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_copy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eerika <eerika@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/21 18:44:13 by eerika            #+#    #+#             */
/*   Updated: 2021/09/21 18:44:16 by eerika           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex_bonus.h"
#include "../include/pipex.h"

char	*ft_copy(char *str, int start)
{
	char	*res;
	int		i;

	res = NULL;
	i = 0;
	if (str && ((int)ft_strlen(str) > start))
	{
		res = (char *)ft_calloc((ft_strlen(str) - start + 1), sizeof(char));
		if (!res)
			return (NULL);
		while (str[start])
		{
			res[i] = str[start];
			i++;
			start++;
		}
		res[i] = '\0';
		free(str);
	}
	return (res);
}
