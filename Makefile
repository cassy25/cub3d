# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cgeoffra <cgeoffra@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/15 13:29:44 by roroca            #+#    #+#              #
#    Updated: 2024/01/08 13:58:12 by cgeoffra         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3D
SANIFLAG = -g
FLAGS = -Wall -Werror -Wextra $(SANIFLAG)

MLX_INCLUDE =	mlx/libmlx_Linux.a -lXext -lX11

SRC_FOLDER = src/
SRC_FILES = controls.c error.c file_color.c file_map.c file_params.c main.c parsing.c raycasting.c utils.c utils2.c set_floor_ceiling.c raycasting2.c controls2.c
OBJS = $(addprefix $(SRC_FOLDER), $(SRC_FILES:%.c=%.o))

MLX_DIR = ./mlx/
MLX = $(MLX_DIR)libmlx_Linux.a

GNL_PATH = gnl/
GNL_LIB = $(GNL_PATH)get_next_line.a

%.o: %.c
	gcc $(FLAGS) -c $< -o $@

$(NAME): $(OBJS)
	make -C $(GNL_PATH)
	make -C $(MLX_DIR)
	gcc $(FLAGS) $(OBJS) $(GNL_LIB) $(MLX_INCLUDE) -o $(NAME) -lm
	clear

all: $(NAME)

clean:
	rm -rf $(OBJS)
	$(MAKE) clean -C $(MLX_DIR)
	make clean -C $(GNL_PATH)

fclean:
	rm -rf $(NAME) $(OBJS)
	$(MAKE) clean -C $(MLX_DIR)
	make fclean -C $(GNL_PATH)

re: fclean all

.PHONY: all clean fclean re
