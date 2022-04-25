/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbonvin <qbonvin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 10:40:46 by qbonvin           #+#    #+#             */
/*   Updated: 2022/04/25 10:03:09 by qbonvin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_right(t_maps *maps)
{
	int	old_position;
	int	next_position;
	int	next_sprit;

	old_position = maps->player->position_actual;
	next_position = old_position + 1;
	next_sprit = maps->maps[maps->player->position_actual + 1];
	count_move(maps);
	if (next_sprit == 'E' && maps->coin == 0)
		ft_close(maps);
	if (next_sprit != '1' && next_sprit != 'E')
	{
		take_coin(next_position, maps);
		maps->maps[old_position] = '0';
		maps->maps[next_position] = 'P';
		maps->player->position_x += 32;
		player_position(maps);
	}
	init_sprit("./img/player.xpm", maps->player->position_x,
		maps->player->position_y, maps);
}

void	move_left(t_maps *maps)
{
	int	old_position;
	int	next_position;
	int	next_sprit;

	old_position = maps->player->position_actual;
	next_position = old_position - 1;
	next_sprit = maps->maps[maps->player->position_actual - 1];
	count_move(maps);
	if (next_sprit == 'E' && maps->coin == 0)
		ft_close(maps);
	if (next_sprit != '1' && next_sprit != 'E')
	{
		take_coin(next_position, maps);
		maps->maps[old_position] = '0';
		maps->maps[next_position] = 'P';
		maps->player->position_x += 32;
		player_position(maps);
	}
	init_sprit("./img/player.xpm", maps->player->position_x,
		maps->player->position_y, maps);
}

void	move_up(t_maps *maps)
{
	int	old_position;
	int	next_position;
	int	next_sprit;

	old_position = maps->player->position_actual;
	next_position = old_position - (maps->x + 1);
	next_sprit = maps->maps[maps->player->position_actual - (maps->x + 1)];
	count_move(maps);
	if (next_sprit == 'E' && maps->coin == 0)
		ft_close(maps);
	if (next_sprit != '1' && next_sprit != 'E')
	{
		take_coin(next_position, maps);
		maps->maps[old_position] = '0';
		maps->maps[next_position] = 'P';
		maps->player->position_y -= 32;
		player_position(maps);
	}
	init_sprit("./img/player.xpm", maps->player->position_x,
		maps->player->position_y, maps);
}

void	move_down(t_maps *maps)
{
	int	old_position;
	int	next_position;
	int	next_sprit;

	old_position = maps->player->position_actual;
	next_position = old_position + (maps->x + 1);
	next_sprit = maps->maps[maps->player->position_actual + (maps->x + 1)];
	count_move(maps);
	if (next_sprit == 'E' && maps->coin == 0)
		ft_close(maps);
	if (next_sprit != '1' && next_sprit != 'E')
	{
		take_coin(next_position, maps);
		maps->maps[old_position] = '0';
		maps->maps[next_position] = 'P';
		maps->player->position_y += 32;
		player_position(maps);
	}
	init_sprit("./img/player.xpm", maps->player->position_x,
		maps->player->position_y, maps);
}

void	count_coin(t_maps *maps)
{
	int	i;

	i = -1;
	maps->coin = 0;
	while (maps->maps[++i])
		if (maps->maps[i] == 'C')
			maps->coin += 1;
}
