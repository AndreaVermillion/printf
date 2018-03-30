# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ancardi <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/03/08 21:24:13 by ancardi           #+#    #+#              #
#    Updated: 2018/03/28 20:46:34 by ancardi          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: all clean fclean re

NAME = libftprintf.a

CC = gcc

ORIGINAL_LIST = apply_fields.c \
	   apply_precision_group1.c \
	   apply_precision_group2.c \
	   apply_precision_group3.c \
	   apply_width_group1.c \
	   apply_width_group2.c \
	   apply_width_group3.c \
	   apply_zero_conditions.c \
	   assist_functions.c \
	   find_arg_group1.c \
	   find_arg_group2.c \
	   find_arg_group3.c \
	   find_fields.c \
	   libft_fonctions.c \
	   parse_fields.c \
	   print_elements.c \
	   ft_printf.c \
	   unicode_convert.c \
	   reset_structures.c \
	   verify_fields.c

OBJ_LIST = $(ORIGINAL_LIST:.c=.o)

CFLAGS = -Wall -Werror -Wextra -I.

CC = gcc

all: $(NAME)

$(NAME): $(OBJ_LIST)
	$(AR) rc $(NAME) $(OBJ_LIST)

%.o: %.c
	$(CC) -c $< -o $@ $(CFLAGS)

clean:
	$(RM) $(OBJ_LIST)

fclean: clean
	$(RM) $(NAME) 

re: fclean all
