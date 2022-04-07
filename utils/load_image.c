/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_image.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbonvin <qbonvin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 15:13:23 by qbonvin           #+#    #+#             */
/*   Updated: 2022/04/06 15:57:49 by qbonvin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void    load_img(t_maps *maps, int width, int height)
{
    maps->img.wall = mlx_xpm_file_to_image(maps->mlx, "../img/wall.xpm", &width, &height);
}