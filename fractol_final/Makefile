# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tstahlhu <tstahlhu@student.42berlin.d      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/13 13:05:13 by tstahlhu          #+#    #+#              #
#    Updated: 2023/10/18 12:17:36 by tstahlhu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= fractol
CC	= cc
CFLAGS	= -Wall -Werror -Wextra
I_PATH	= ./../minilibx-linux/ #/usr/local/include
L_PATH	= ./../minilibx-linux/  #/usr/local/lib/
LIB	= -lmlx -lXext -lX11 -lm

CFILES	= main.c init.c input_check.c render_image.c error_exit_handlings.c utils.c \
			event_handling.c ft_printf.c ft_print_arguments.c color_palettes.c
OBJ	=  main.o init.o input_check.o render_image.o error_exit_handlings.o utils.o \
		event_handling.o ft_printf.o ft_print_arguments.o color_palettes.o 

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
