# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ancardi <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/03/08 21:24:13 by ancardi           #+#    #+#              #
#    Updated: 2018/03/12 22:15:16 by ancardi          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRCS = ft_apply_fields.c \
	   ft_copy_fields.c \
	   ft_find_fields.c \
	   ft_find_arg_type.c \
	   ft_functions_libft.c \
	   ft_search_fields.c \
	   ft_veri_fields.c \
	   main.c \
	   ft_apply_precision.c \
	   ft_count_printed_char.c \
	   ft_set_struct_to_zero.c \
	   ft_print_percents.c \
	   ft_find_percents.c

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
