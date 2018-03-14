cmake_minimum_required(VERSION 3.9)
project(printf)

set(CMAKE_CXX_STANDARD 11)

add_executable(printf
        ft_apply_fields.c
        ft_copy_fields.c
        ft_find_fields.c
        ft_find_arg_type.c
        ft_search_fields.c
        ft_veri_fields.c
        main.c
        printf.h
        ft_apply_precision.c ft_set_struct_to_zero.c ft_count_printed_char.c ft_functions_libft.c ft_find_percents.c ft_print_percents.c)
