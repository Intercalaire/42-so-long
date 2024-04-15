# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vgodart <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/01 13:20:19 by vgodart           #+#    #+#              #
#    Updated: 2023/11/01 16:28:59 by vgodart          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = clang
CFLAGS = -Wall -Wextra -Werror -g
MACROLIBX = MacroLibX/libmlx.so -lSDL2
MACROLIBX_PATH = MacroLibX
Libft_PATH = Libft
Libft_FILE = Libft/Libft.a
SRC = so_long.c \
	so_long_utils.c \
	map_verif.c \
	init_map.c \
	data_clear.c \
	put_textures.c \
	player_movement.c \
	parsing.c \
	parsing_utils.c \
	init_map_utils.c \
	

OBJ = $(SRC:.c=.o)

NAME = so_long

all: $(NAME)

	
$(NAME): $(OBJ) 
	make -C $(Libft_PATH)
	make -C $(MACROLIBX_PATH)
	$(CC) $(OBJ) $(MACROLIBX) $(Libft_FILE) -o $(NAME)


.c.o:
	$(CC) $(CFLAGS) -c $< -o $@


clean: 
	make clean -C $(Libft_PATH)
	make clean -C $(MACROLIBX_PATH)
	rm -f $(OBJ)

fclean: clean
	make fclean -C $(Libft_PATH)
	make fclean -C $(MACROLIBX_PATH)
	rm -f $(NAME)

re: fclean all


.PHONY: all clean fclean re

	
