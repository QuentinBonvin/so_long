/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbonvin <qbonvin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 14:27:58 by qbonvin           #+#    #+#             */
/*   Updated: 2022/04/25 09:25:37 by qbonvin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../libft/libft.h"
# include "../mlx/mlx.h"

# define KEY_ESC 53
# define KEY_RIGHT 124
# define KEY_LEFT 123
# define KEY_UP 126
# define KEY_DOWN 125
# define KEY_W 13
# define KEY_A 0
# define KEY_S 1
# define KEY_D 2

typedef struct s_player
{
	int	position_x;
	int	position_y;
	int	position_actual;
}	t_player;

typedef struct s_maps
{
	t_player	*player;
	void		*mlx;
	void		*mlx_windows;
	int			x;
	int			y;
	char		*maps;
	int			coin;
	int			step;
}	t_maps;

/**********
 * parsing
 *********/
void	start_so_long(char *map);
void	start_read_map(int fd, char **map);
int		ft_strchr_location(char *line, char c);
int		check_name_of_map(char *str);
void	check_last_line(char **map, char *line, int width);
void	check_border_left_and_right(char **map, char *line, int width);
int		check_char_on_map(char **map);
int		check_if_valid_map(char **map);
int		init_event(t_maps *maps);
int		start_event(t_maps *maps);
int		key_event(int key, t_maps *maps);
void	player_position(t_maps *maps);
void	move_right(t_maps *maps);
void	move_left(t_maps *maps);
void	move_up(t_maps *maps);
void	move_down(t_maps *maps);
void	init_player_position(t_maps *maps);
void	free_ptr(char **ptr);
void	error(char *str);
int		start_windows(int width, int height, char **map);
void	start_map(t_maps *maps);
void	load_sprit(t_maps *maps, char *sprit, int c);
void	init_sprit(char *sprit, int x, int y, t_maps *maps);
void	count_coin(t_maps *maps);
int		ft_close(t_maps *maps);
void	count_move(t_maps *maps);
void	take_coin(int position, t_maps *maps);
void	check_border_top_and_bot(char **map, int width);

#endif