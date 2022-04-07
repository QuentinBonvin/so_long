/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbonvin <qbonvin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 14:27:58 by qbonvin           #+#    #+#             */
/*   Updated: 2022/04/07 16:59:20 by qbonvin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../libft/libft.h"
# include "../mlx/mlx.h"

typedef struct s_img 
{
    void    *wall;
    void    *player;
    void    *collectible;
    void    *exit;
}	t_img;

typedef struct s_maps 
{
    void	*mlx;
    void	*mlx_windows;
    int		x;
    int		y;
    char    *maps;
    t_img   img;
}	t_maps;

/**********
 * parsing
 *********/
void	    start_so_long(char *map);
void	    start_read_map(int fd, char **map);
int		    ft_strchr_location(char *line, char c);
int		    check_name_of_map(char *str);
void        check_last_line(char **map, char *line, int width);
void        check_border_left_and_right(char **map, char *line, int width);
int         check_char_on_map(char **map);
int	        check_if_valid_map(char **map);


void	free_ptr(char **ptr);
void	error(char *str);
int     start_windows(int width, int height, char **map);
void start_map(t_maps *maps);
void    set_static_items(t_maps *maps, char *tile, int c);
void    init_tile(char *path, int x, int y, t_maps *maps);








#endif
