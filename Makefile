# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tstahlhu <tstahlhu@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/13 13:05:13 by tstahlhu          #+#    #+#              #
#    Updated: 2024/03/19 12:19:21 by tstahlhu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= fractol
CC	= cc
CFLAGS	= -Wall -Werror -Wextra
I_PATH	= ./minilibx-linux/ #/usr/local/include
L_PATH	= ./minilibx-linux/  #/usr/local/lib/
LIB	= -lmlx -lXext -lX11 -lm

CFILES	= fractol.c init.c input_check.c render_image.c error_exit_handlings.c \
			utils.c event_handling.c ft_printf.c ft_print_arguments.c \
			color_palettes_1.c color_palettes_2.c
OBJ	=  fractol.o init.o input_check.o render_image.o error_exit_handlings.o \
		utils.o	event_handling.o ft_printf.o ft_print_arguments.o \
		color_palettes_1.o color_palettes_2.o

all:		$(NAME)

$(NAME):	$(OBJ)
		$(CC) -o $(NAME) -I $(I_PATH) $(OBJ) -L $(L_PATH) $(LIB)

%.o: %.c
		$(CC) $(CFLAGS) -c -g $<

clean:
ifneq ("$(wildcard $(OBJ))", "")
		rm -f $(OBJ)
endif

fclean:		clean
ifneq ("$(wildcard $(NAME))", "")
		rm -f $(NAME)
endif

re:		fclean all

.PHONY: all clean fclean re
