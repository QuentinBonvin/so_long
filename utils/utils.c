/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbonvin <qbonvin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 13:30:59 by qbonvin           #+#    #+#             */
/*   Updated: 2022/04/07 13:23:19 by qbonvin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	error(char *str)
{
	ft_putstr(str);
	exit(EXIT_SUCCESS);
}

int	ft_strchr_location(char *line, char c)
{
	int	i;

	i = 0;
	while (i < (int)ft_strlen(line))
	{
		if (line[i] == c)
			return (i);
		i++;
	}
	return (0);
}

void	free_ptr(char **ptr)
{
	if (*ptr != NULL)
	{
		free(*ptr);
		*ptr = NULL;
	}
}