/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbonvin <qbonvin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 10:40:46 by qbonvin           #+#    #+#             */
/*   Updated: 2022/04/14 13:36:42 by qbonvin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void    move_right(t_maps *maps)
{   

    int old_position;
    int next_position;
    int next_sprit;
    old_position = maps->player->position_actual;
    next_position = old_position + 1;
    next_sprit = maps->maps[maps->player->position_actual + 1];
    if (next_sprit != '1' && next_sprit != 'E')
    {
        maps->maps[old_position] = '0';
        maps->maps[next_position] = 'P';
        maps->player->position_x += 32;
        player_position(maps);
    }
    init_tile("./img/mario.xpm", maps->player->position_x, maps->player->position_y, maps);
}

void    move_left(t_maps *maps)
{   

    int old_position;
    int next_position;
    int next_sprit;
    old_position = maps->player->position_actual;
    next_position = old_position - 1;
    next_sprit = maps->maps[maps->player->position_actual - 1];
    if (next_sprit != '1' && next_sprit != 'E')
    {
        maps->maps[old_position] = '0';
        maps->maps[next_position] = 'P';
        maps->player->position_x += 32;
        player_position(maps);
    }
    init_tile("./img/mario.xpm", maps->player->position_x, maps->player->position_y, maps);
}

void    move_up(t_maps *maps)
{   

    int old_position;
    int next_position;
    int next_sprit;
    old_position = maps->player->position_actual;
    next_position = old_position - (maps->x + 1);
    next_sprit = maps->maps[maps->player->position_actual - (maps->x + 1)];
    if (next_sprit != '1' && next_sprit != 'E')
    {
        maps->maps[old_position] = '0';
        maps->maps[next_position] = 'P';
        maps->player->position_y -= 32;
        player_position(maps);
    }
    init_tile("./img/mario.xpm", maps->player->position_x, maps->player->position_y, maps);
}

void    move_down(t_maps *maps)
{   

    int old_position;
    int next_position;
    int next_sprit;
    old_position = maps->player->position_actual;
    next_position = old_position + (maps->x + 1);
    next_sprit = maps->maps[maps->player->position_actual + (maps->x + 1)];
    if (next_sprit != '1' && next_sprit != 'E')
    {
        maps->maps[old_position] = '0';
        maps->maps[next_position] = 'P';
        maps->player->position_y += 32;
        player_position(maps);
    }
    init_tile("./img/mario.xpm", maps->player->position_x, maps->player->position_y, maps);
}

void    count_coin(t_maps *maps)
{
	int	i;

	i = -1;
	maps->coin = 0;
	while (maps->maps[++i])
		if (maps->maps[i] == 'C')
			maps->coin += 1;
}