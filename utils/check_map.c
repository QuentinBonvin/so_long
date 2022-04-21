/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbonvin <qbonvin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 15:05:33 by qbonvin           #+#    #+#             */
/*   Updated: 2022/04/20 16:57:55 by qbonvin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/*******
 * check if the name of map is a <.ber>
 *******/
int	check_name_of_map(char *str)
{
	int	i;

	i = ft_strlen(str);
	if (i < 5)
		return (0);
	if (str[--i] == 'r')
	{
		if (str[--i] == 'e')
		{
			if (str[--i] == 'b')
			{
				if (str[--i] == '.')
					return (1);
			}
		}
	}
	return (0);
}

/*******
 * check if the last line doesn't finish with a '\n'
 *******/
void	check_last_line(char **map, char *line, int width)
{
	int	last_char;

	last_char = (int)ft_strlen(line) - 1;
	check_border_left_and_right(map, line, width);
	if (line[last_char] != '\n')
		last_char += 1;
	if (width != last_char)
	{
		error("error\nmap not rectangular\n");
		free_ptr(map);
		exit(0);
	}
}

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

/*******
 * check if on the map there is a '0' '1' 'C' 'E' 'P'
 *******/
int	check_char_on_map(char **map)
{
	int	i;

	i = 0;
	while ((*map)[i])
	{
		if ((*map)[i] != 'E' && (*map)[i] != 'P' &&
			(*map)[i] != 'C' && (*map)[i] != '1' &&
			(*map)[i] != '0' && (*map)[i] != '\n')
			error("error\ninvalid char on the map\n");
		i++;
	}
	return (1);
}

int	check_if_valid_map(char **map)
{
	if (!ft_strchr(*map, 'P'))
		error("error\nThe map dosen't have a Player\n");
	else if (!ft_strchr(*map, 'C'))
		error("error\nThe map dosen't have collectible\n");
	else if (!ft_strchr(*map, '1'))
		error("error\nThe map dosen't have Wall\n");
	else if (!ft_strchr(*map, 'E'))
		error("error\nThe map dosen't have exit\n");
	else if (!ft_strchr(*map, '0'))
		error("error\nThe map dosen't have ground\n");
	else
		return (1);
	return (0);
}
