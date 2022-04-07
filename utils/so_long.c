/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbonvin <qbonvin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 13:59:06 by qbonvin           #+#    #+#             */
/*   Updated: 2022/04/07 11:54:26 by qbonvin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char *argv[])
{
	if (argc != 2)
		error("must have 2 arguments\n");
	else
		start_so_long(argv[1]);
	return (0);
}

void	start_so_long(char *map)
{
	int			fd;
	static char	*save;

	if (save == 0)
		save = ft_strdup("");
	fd = open(map, O_RDONLY);
	if (!check_name_of_map(map))
		error("not a map <.ber>");
	start_read_map(fd, &save);
}
