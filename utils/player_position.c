/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_position.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbonvin <qbonvin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 10:05:25 by qbonvin           #+#    #+#             */
/*   Updated: 2022/04/19 14:05:18 by qbonvin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	player_position(t_maps *maps)
{
	int	i;
	int	x;
	int	y;
	int	actual;

	i = 0;
	x = -1;
	y = -1;
	actual = -1;
	while (maps->y > ++y)
	{
		while ((maps->maps)[++actual] && maps->x > ++x)
		{
			if (maps->maps[actual] == 'P')
			{
				maps->player->position_x = x * TILE_SIZE;
				maps->player->position_y = y * TILE_SIZE;
				maps->player->position_actual = actual;
			}
		}
		x = -1;
	}
}
