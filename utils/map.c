/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbonvin <qbonvin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 16:19:37 by qbonvin           #+#    #+#             */
/*   Updated: 2022/04/07 16:32:45 by qbonvin          ###   ########.fr       */
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
		//check_char_on_map(map);
		//check_if_valid_map(map);
		start_windows(width, height, map);
		//printf("height = %d\n", height);
		//printf("width = %d", width);
	}
}

int	start_windows(int width, int height, char **map)
{
	t_maps *maps;
	maps = malloc(sizeof(t_maps));
	maps->maps = *map;
	maps->x = width;
	maps->y = height;
	maps->mlx = mlx_init();
	maps->mlx_windows = mlx_new_window(maps->mlx, maps->x * 32, maps->y * 32, "./so_long");
	start_map(maps);
	mlx_loop(maps->mlx);
	return(0);
}
