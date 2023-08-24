# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: joaopereira <joaopereira@student.42.fr>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/14 10:24:03 by jalves-p          #+#    #+#              #
#    Updated: 2023/08/24 17:12:43 by joaopereira      ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


SRCS = checkers.c controls.c ft_utils.c map.c\
		so_long.c imags.c\
		
OBJS = $(SRCS:.c=.o)

FLAGS = -Wall -Wextra -Werror -Iinc/
MLXFLAGS = -lXext -lX11 -lm -lz
LIBFT = Libft/libft.a
PRINTF = Printf/libftprintf.a
MLX = minilibx-linux/libmlx_Linux.a

NAME = so_long

all: $(NAME) 

.PHONY: all, fclean, re

$(NAME): $(OBJS)
		make -C minilibx-linux/
		make -C Libft/
		make -C Printf/
		cc $(FLAGS) $(OBJS) $(LIBFT) $(MLX) $(PRINTF) $(MLXFLAGS) -o $(NAME) 

clean:
	rm -f $(OBJS)
	make clean -C minilibx-linux/
	make clean -C Libft/
	make clean -C Printf/
	
fclean: clean
	rm -f $(NAME) $(LIBFT) $(PRINTF) $(MLX)

re: fclean all