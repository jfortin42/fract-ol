# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jfortin <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/11/24 10:29:00 by jfortin           #+#    #+#              #
#    Updated: 2016/03/15 18:07:20 by jfortin          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FLAG = -Wall -Wextra -Werror

NAME = fractol

MLX = -L minilibx_macos -lmlx -framework OpenGL -framework AppKit

SRC = burningship.c \
		julia.c \
		key_biding.c \
		main.c \
		mandelbis.c \
		mandelbrot.c \
		utilities.c \
		zoom.c

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
		@make -C libft
		@make -C minilibx_macos
		@gcc $(FLAG) -o $(NAME) $(OBJ) $(MLX) -L libft -lft
		@echo "$(NAME) created"

%.o: %.c
		@gcc $(FLAG) -c $< -o $@
clean:
		@make clean -C libft
		@Make clean -C minilibx_macos
		@rm -f $(OBJ)
		@echo "$(NAME) OBJ deleted"

fclean: clean
		@make fclean -C libft
		@rm -f $(NAME)
		@echo "$(NAME) deleted"

re : fclean all

.PHONY: all, clean, fclean, re
