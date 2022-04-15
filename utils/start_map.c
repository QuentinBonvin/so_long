/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbonvin <qbonvin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 15:03:40 by qbonvin           #+#    #+#             */
/*   Updated: 2022/04/14 14:30:16 by qbonvin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_player_position(t_maps *maps)
{
	set_static_items(maps, "./img/mario.xpm", 'P');
	player_position(maps);
}

void start_map(t_maps *maps)
{
    set_static_items(maps, "./img/waaal.xpm", '1');
    set_static_items(maps, "./img/ground.xpm", '0');
    set_static_items(maps, "./img/mushroom.xpm", 'C');
    set_static_items(maps, "./img/mario.xpm", 'P');
	init_player_position(maps);
	count_coin(maps);
}

void    set_static_items(t_maps *maps, char *tile, int c)
{
	int	i;
	int	x;
	int	y;

	x = -1;
	y = -1;
	i = -1;
	while (maps->y > ++y)
	{
		while ((maps->maps)[++i] && maps->x > ++x)
		{
			if ((maps->maps)[i] == c)
				init_tile(tile, x * 32, y * 32, maps);
		}
		x = -1;
	}
}

void	init_tile(char *path, int x, int y, t_maps *maps)
{
	int		w;
	int		h;
	void	*img;

	img = mlx_xpm_file_to_image(maps->mlx, path, &w, &h);
	mlx_put_image_to_window(maps->mlx, maps->mlx_windows, img, x, y);
}