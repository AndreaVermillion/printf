# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ancardi <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/03/08 21:24:13 by ancardi           #+#    #+#              #
#    Updated: 2018/03/30 20:33:05 by ancardi          ###   ########.fr        #
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
	   apply_zero_conditions_1.c \
	   apply_zero_conditions_2.c \
	   assist_functions_1.c \
	   assist_functions_2.c \
	   find_arg_group1_len_0.c \
	   find_arg_group1_len_1_2.c \
	   find_arg_group2_len_0_1.c \
	   find_arg_group2_len_2.c \
	   find_arg_group3.c \
	   find_fields_1.c \
	   find_fields_2.c \
	   find_fields_3.c \
	   libft_functions_1.c \
	   libft_functions_2.c \
	   libft_functions_3.c \
	   libft_functions_4.c \
	   parse_fields.c \
	   print_elements_1.c \
	   print_elements_2.c \
	   ft_printf.c \
	   unicode_convert.c \
	   reset_structures.c \
	   verify_fields_part_1.c \
	   verify_fields_part_2.c \
	   verify_fields_part_3.c \
	   get_arg_type_len_len_0_1_2.c \
	   apply_lc_c.c \
	   apply_ls_s_part_1.c \
	   apply_ls_s_part_2.c \
	   apply_wtp_1_2_4.c \

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
