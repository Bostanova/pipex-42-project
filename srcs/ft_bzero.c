/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eerika <eerika@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/21 18:43:49 by eerika            #+#    #+#             */
/*   Updated: 2021/09/21 18:43:50 by eerika           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex_bonus.h"

void	ft_bzero(void *s, size_t n)
{
	size_t	i;
	char	*tmp;

	tmp = (char *)s;
	if (n != 0)
	{
		i = 0;
		while (n > 0)
		{
			tmp[i] = '\0';
			i++;
			n--;
		}
		s = (void *)tmp;
	}
}
