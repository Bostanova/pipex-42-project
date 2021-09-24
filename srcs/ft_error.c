/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eerika <eerika@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/21 18:44:23 by eerika            #+#    #+#             */
/*   Updated: 2021/09/22 12:51:37 by eerika           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex_bonus.h"
#include "../include/pipex.h"

void	ft_error(int err, char *str)
{
	if (err == 1)
		ft_putstr("Error: Cannot allocate memory\n");
	else if (err == 2)
		ft_putstr("Error: Arguments are less than six\n");
	else if (err == 3)
	{
		ft_putstr(str);
		ft_putstr(": command not found\n");
	}
	exit(err);
}
