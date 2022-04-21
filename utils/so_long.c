/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbonvin <qbonvin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 13:59:06 by qbonvin           #+#    #+#             */
/*   Updated: 2022/04/21 08:15:22 by qbonvin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char *argv[])
{
	if (argc != 2)
		error("error\nmust have 2 arguments\n");
	else
		start_so_long(argv[1]);
	return (0);
}

void	start_so_long(char *map)
{
	int			fd;
	char		*save;

	save = ft_strdup("");
	fd = open(map, O_RDONLY);
	if (!check_name_of_map(map))
		error("error \nnot a map <.ber>\n");
	start_read_map(fd, &save);
	free_ptr(&save);
	close(fd);
}
