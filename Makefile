# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jalves-p <jalves-p@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/14 10:24:03 by jalves-p          #+#    #+#              #
#    Updated: 2023/08/14 15:29:21 by jalves-p         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc

NAME = so_long

SRCS = so_long.c

OBJS = $(SRCS:.c=.o)


FLAGS = -Wall -Wextra -Werror -Iinc/

MLXFLAGS = -lXext -lX11 -lm -lz

LIBFT = Libft/libft.a

PRINTF = Printf/libftprintf.a

MLX = mlx/libmlx-linux.a


all: $(NAME)

.PHONY: all, fclean, re

$(NAME): $(OBJS)
		make -C mlx/
		make -C Libft/
		make -C Printf/
		cc $(FLAGS) $(OBJS) $(LIBFT) $(PRINTF) $(MLX) $(MLXFLAGS) -o $(NAME) 
 
clean:
	rm -f $(OBJS) $(B_OBJS)
	make clean -C mlx/
		make -C Libft/
		make -C Printf/
	
fclean: clean
	rm -f $(NAME)

re: fclean all

# ifeq ($(shell uname), Linux)
# 	INCLUDES = -I/usr/include -Imlx
# else
# 	INCLUDES = -I/opt/X11/include -Imlx
# endif
 
# MLX_DIR = ./mlx
# MLX_LIB = $(MLX_DIR)/libmlx_$(UNAME).a
# ifeq ($(shell uname), Linux)
# 	MLX_FLAGS = -Lmlx -lmlx -L/usr/lib/X11 -lXext -lX11
# else
# 	MLX_FLAGS = -Lmlx -lmlx -L/usr/X11/lib -lXext -lX11 -framework OpenGL -framework AppKit
# endif
 
# # [...]
 
# all: $(MLX_LIB) $(NAME)
 
# .c.o:
# 	$(CC) $(CFLAGS) -c -o $@ $< $(INCLUDES)
 
# $(NAME): $(OBJS)
# 	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(MLX_FLAGS)
 
# $(MLX_LIB):
# 	@make -C $(MLX_DIR)