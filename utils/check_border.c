/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_border.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbonvin <qbonvin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 09:29:52 by qbonvin           #+#    #+#             */
/*   Updated: 2022/04/25 09:31:02 by qbonvin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/*******
 * check if the border left and right are a '1'
 *******/
void	check_border_left_and_right(char **map, char *line, int width)
{
	int	i;

	i = 0;
	while (i < width)
	{
		if (line[0] != '1' || line[width - 1] != '1')
		{
			error("error\nmap not close\n");
			free_ptr(map);
			exit(0);
		}
		i++;
	}
}

void	check_border_top_and_bot(char **map, int width)
{
	int		i;
	int		j;

	i = -1;
	j = ft_strlen(*map) - 1;
	while (++i < width)
	{
		if ((*map)[i] != '1' || (*map)[j--] != '1')
		{
			error("Error\nmap not close\n");
		}
	}
}
