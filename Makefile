# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ancardi <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/03/08 21:24:13 by ancardi           #+#    #+#              #
#    Updated: 2018/03/28 11:59:10 by ancardi          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRCS = apply_fields.c \
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
	   printf.c \
	   unicode_convert.c \
	   reset_structures.c \
	   verify_fields.c\

OBJS = $(SRCS:.c=.o)

FLAGS = -Wall -Wextra -Werror -c

all: $(SRCS) $(NAME)

$(NAME): $(OBJS)
	@ar rc $(NAME) $(OBJS)

%.o: %.c
	@gcc $(FLAGS) $<

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f libftprintf.a

re: fclean all
