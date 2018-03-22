cmake_minimum_required(VERSION 3.9)
project(printf)

set(CMAKE_CXX_STANDARD 11)

add_executable(printf
        apply_fields.c
        assist_functions.c
        find_fields.c
        parse_fields.c
        verify_fields.c
        printf.c
        printf.h
        reset_structures.c libft_fonctions.c print_elements.c apply_width_group1.c apply_width_group2.c apply_width_group3.c apply_zero_conditions.c find_arg_group1.c find_arg_group2.c find_arg_group3.c apply_precision_group1.c apply_precision_group2.c apply_precision_group3.c unicode_convert.c)
