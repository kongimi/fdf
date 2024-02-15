# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: npiyapan <npiyapan@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/21 12:42:15 by npiyapan          #+#    #+#              #
#    Updated: 2024/02/13 12:37:06 by npiyapan         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

SRC_DIR = src/
OBJ_DIR = bin/
CC = cc
CFLAGS = -Wall -Werror -Wextra

INC = inc/
LIB = lib/
LIBTF_DIR =  $(LIB)libft/
LIBFT = $(LIBTF_DIR)libft.a
MINILIBX_DIR = $(LIB)minilibx-linux/
MINILIBX = $(MINILIBX_DIR)libmlx_Linux.a
#MINILIBXCC = -Imlx -L $(MINILIBX_DIR) -lmlx #this line for MACOS
MINILIBXCC = -I$(MINILIBX_DIR) $(MINILIBX) -lXext -lX11 -lm -lz
HEADER = -I$(INC) -I$(LIBTF_DIR) -I$(MINILIBX_DIR)
OPENGL = -framework OpenGL -framework AppKit

SRC_FILES = main draw init_hook read_map ft_atoi_hex init_system draw_map print_errors

SRC = $(addprefix $(SRC_DIR), $(addsuffix .c, $(SRC_FILES)))
OBJ = $(addprefix $(OBJ_DIR), $(addsuffix .o, $(SRC_FILES)))

bin/%.o: $(SRC_DIR)%.c
	@mkdir -p bin
	$(CC) $(CFLAGS) -I/usr/include -Imlx_linux -O3 -c $< -o $@
#	$(CC) $(CFLAGS) -Imlx -c $< -o $@ # this line for MACOS
	


all:	$(NAME)

$(NAME): $(OBJ)
	$(MAKE) -C $(LIBTF_DIR)
	$(MAKE) -C $(MINILIBX_DIR)
#	$(CC) $(CFLAGS) $(OBJ) $(LIBFT) $(MINILIBXCC) $(OPENGL) -o $(NAME) # this line for MACOS
	$(CC) $(CFLAGS) $(OBJ) $(LIBFT) $(MINILIBXCC) -o $(NAME)
clean:
	rm -rf bin
	rm -f fdf
	rm -f $(LIBTF_DIR)libft.a
	rm -f $(MINILIBX_DIR)libmlx.a
	$(MAKE) -C $(LIBTF_DIR) clean
	$(MAKE) -C $(MINILIBX_DIR) clean

fclean: clean
	$(MAKE) -C $(LIBTF_DIR) clean
	$(MAKE) -C $(MINILIBX_DIR) clean

l:
	leaks --atExit -- ./$(NAME)

re: fclean all

.PHONY: all bonus clean fclean re
