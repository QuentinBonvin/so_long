/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbonvin <qbonvin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 13:30:59 by qbonvin           #+#    #+#             */
/*   Updated: 2022/04/19 15:34:40 by qbonvin          ###   ########.fr       */
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

void	count_move(t_maps *maps)
{
	maps->step += 1;
	ft_printf("move %d\n", maps->step);
}

void	take_coin(int position, t_maps *maps)
{
	if (maps->maps[position] == 'C' && maps->coin > 0)
		maps->coin--;
}
