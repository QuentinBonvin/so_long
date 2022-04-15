/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbonvin <qbonvin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 16:19:37 by qbonvin           #+#    #+#             */
/*   Updated: 2022/04/15 17:06:59 by qbonvin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	start_read_map(int fd, char **map)
{
	int		height;
	int		width;
	char	*line;

	if (fd < 0)
		error("Impossible to opening file");
	else
	{
		height = 0;
		line = get_next_line(fd);
		width = ft_strchr_location(line, '\n');
		while (line != NULL)
		{
			height++;
			*map = ft_strjoin_gnl(*map, line);
			check_last_line(map, line, width);
			line = get_next_line(fd);
		}
		//printf("%c\n", *map[width - 1]);
		check_char_on_map(map);
		check_if_valid_map(map);
		start_windows(width, height, map);
	}
	free_ptr(map);
}

int	start_windows(int width, int height, char **map)
{
	t_maps *maps;
	maps = malloc(sizeof(t_maps));
	maps->player = malloc(sizeof(t_player));
	maps->maps = *map;
	maps->x = width;
	maps->y = height;
	maps->mlx = mlx_init();
	maps->mlx_windows = mlx_new_window(maps->mlx, maps->x * 32, maps->y * 32, "./so_long");
	start_map(maps);
	//printf("nombre de coin = %d\n", maps->coin);
	mlx_loop_hook(maps->mlx, init_event, maps);
	printf("position_x = %d", maps->player->position_x);
	mlx_loop(maps->mlx);
	free(maps);
	maps = NULL;
	free(maps->player);
	maps->player = NULL;
	return(0);
}

int	init_event(t_maps *maps)
{
	mlx_hook(maps->mlx_windows, 2, 1L << 0, key_event, maps);
	//mlx_hook(maps->mlx_windows, 2, 0L << 0, ft_close, maps);
	return (0);
}

int	key_event(int key, t_maps *maps)
{
	set_static_items(maps, "./img/ground.xpm", '0');
	init_tile("./img/ground.xpm", maps->player->position_x, maps->player->position_y, maps);
	if (key == KEY_ESC)
		ft_close(maps);
	if (key == KEY_RIGHT)
		move_right(maps);
	if (key == KEY_LEFT)
		move_left(maps);
	if (key == KEY_UP)
		move_up(maps);
	if (key == KEY_DOWN)
		move_down(maps);
	return (0);
}

int	ft_close(t_maps *maps)
{
	(void)maps;
	exit (0);
}