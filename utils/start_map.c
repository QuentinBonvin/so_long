/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbonvin <qbonvin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 15:03:40 by qbonvin           #+#    #+#             */
/*   Updated: 2022/04/21 09:48:11 by qbonvin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_player_position(t_maps *maps)
{
	load_sprit(maps, "./img/player.xpm", 'P');
	player_position(maps);
}

void	start_map(t_maps *maps)
{
	load_sprit(maps, "./img/wall.xpm", '1');
	load_sprit(maps, "./img/ground.xpm", '0');
	load_sprit(maps, "./img/coin.xpm", 'C');
	load_sprit(maps, "./img/exit.xpm", 'E');
	init_player_position(maps);
	count_coin(maps);
}

void	load_sprit(t_maps *maps, char *sprit, int c)
{
	int	i;
	int	x;
	int	y;

	x = -1;
	y = -1;
	i = -1;
	while (maps->y > ++y)
	{
		while (maps->maps[++i] && maps->x > ++x)
		{
			if (maps->maps[i] == c)
				init_sprit(sprit, x * 32, y * 32, maps);
		}
		x = -1;
	}
}

void	init_sprit(char *sprit, int x, int y, t_maps *maps)
{
	int		w;
	int		h;
	void	*img;

	img = mlx_xpm_file_to_image(maps->mlx, sprit, &w, &h);
	mlx_put_image_to_window(maps->mlx, maps->mlx_windows, img, x, y);
}
