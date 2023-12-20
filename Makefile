# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cgeoffra <cgeoffra@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/15 13:29:44 by roroca            #+#    #+#              #
#    Updated: 2023/12/19 18:37:35 by cgeoffra         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3D
SANIFLAG = -g
FLAGS = -Wall -Werror -Wextra $(SANIFLAG)

MLX_INCLUDE =	mlx/libmlx_Linux.a -lXext -lX11

SRC_FOLDER = src/
SRC_FILES = *.c
OBJS = $(addprefix $(SRC_FOLDER), $(SRC_FILES:%.c=%.o))

MLX_DIR = ./mlx/
MLX = $(MLX_DIR)libmlx_Linux.a

GNL_PATH = gnl/
GNL_LIB = $(GNL_PATH)get_next_line.a

LIBFT_DIR = libft/
LIBFT_LIB = $(LIBFT_DIR)ft_printf.a

%.o: %.c
	gcc $(FLAGS) -c $< -o $@

$(NAME): $(OBJS)
	make -C $(GNL_PATH)
	make -C $(MLX_DIR)
	make -C $(LIBFT_DIR)
	gcc $(FLAGS) $(OBJS) $(GNL_LIB) $(MLX_INCLUDE) -o $(NAME)
	clear

all: $(NAME)

clean:
	rm -rf $(OBJS)
	$(MAKE) clean -C $(MLX_DIR)
	make clean -C $(GNL_PATH)
	make clean -C $(LIBFT_DIR)

fclean:
	rm -rf $(NAME) $(OBJS)
	$(MAKE) clean -C $(MLX_DIR)
	make fclean -C $(GNL_PATH)
	make fclean -C $(LIBFT_DIR)

re: fclean all

.PHONY: all clean fclean re
