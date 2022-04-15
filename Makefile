# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: qbonvin <qbonvin@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/04 15:05:41 by qbonvin           #+#    #+#              #
#    Updated: 2022/04/14 15:15:57 by qbonvin          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long.a
RUN = so_long
CC = gcc -g
CFLAGS = -Wall -Werror -Wextra -Imlx
LIBFT = ./libft
MLX = ./mlx
MLXLINK = -Lmlx -lmlx -lz -framework OpenGL -framework AppKit
SRC = utils/
FILES = so_long.c utils.c check_map.c map.c load_image.c start_map.c \
player_position.c event.c

SOURCES = $(addprefix ${SRC}, ${FILES})
OBJ = ${SOURCES:.c=.o}
LIB = -L ./libft -lft -L ./mlx -lmlx

all : ${NAME}

${NAME} : ${OBJ}
	make -C ${LIBFT}
	make -C ${MLX}
	${CC} ${CFLAGS} ${MLXLINK} -o ${RUN} ${OBJ} ${LIB}

clean :
	rm -rf ${OBJ}
	rm -rf ${RUN}
	make -C ${MLX} clean
	make -C ${LIBFT} clean

fclean : clean
	rm -rf ${NAME}
	make -C ${LIBFT} fclean

re : fclean all