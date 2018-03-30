#include "printf.h"

void    ft_select_args_group2_len_0(t_data *a, va_list arg)
{
    if (a->spe == 'o' || a->spe == 'u' || a->spe == 'x' || a->spe == 'X')
    {
        a->a_g2_o_u_x_X = va_arg(arg, unsigned int);
        if (a->spe == 'o')
            a->arg_str_conv = ft_itoa_base_unsigned(a->a_g2_o_u_x_X, 8);
        if (a->spe == 'u')
            a->arg_str_conv = ft_itoa_base_unsigned(a->a_g2_o_u_x_X, 10);
        if (a->spe == 'x' || a->spe == 'X')
            a->arg_str_conv = ft_itoa_base_unsigned(a->a_g2_o_u_x_X, 16);
    }
    else if (a->spe == 'O' || a->spe == 'U')
    {
        a->a_g2_O_U_l = va_arg(arg, unsigned long int);
        if (a->spe == 'O')
            a->arg_str_conv = ft_itoa_base_unsigned(a->a_g2_O_U_l, 8);
        if (a->spe == 'U')
            a->arg_str_conv = ft_itoa_base_unsigned(a->a_g2_O_U_l, 10);
    }
}

void    ft_select_args_group2_len_1_part1(t_data *a, va_list arg) // VERIFIED
{
    if (a->len[0] == 'l')
    {
        a->a_g2_O_U_l = va_arg(arg, unsigned long int);
        if (a->spe == 'o')
            a->arg_str_conv = ft_itoa_base_unsigned(a->a_g2_O_U_l, 8);
        else if (a->spe == 'u')
            a->arg_str_conv = ft_itoa_base_unsigned(a->a_g2_O_U_l, 10);
        else if (a->spe == 'x' || a->spe == 'X')
            a->arg_str_conv = ft_itoa_base_unsigned(a->a_g2_O_U_l, 16);
    }
    else if (a->len[0] == 'h')
    {
        a->a_g2_h = (unsigned short) va_arg(arg, int);
        if (a->spe == 'o')
            a->arg_str_conv = ft_itoa_base_signed(a->a_g2_h, 8);
        else if (a->spe == 'u')
            a->arg_str_conv = ft_itoa_base_signed(a->a_g2_h, 10);
        else if (a->spe == 'x' || a->spe == 'X')
            a->arg_str_conv = ft_itoa_base_signed(a->a_g2_h, 16);
    }
}

void    ft_select_args_group2_len_1_part2(t_data *a, va_list arg) // VERIFIED
{
    if (a->len[0] == 'j')
    {
        a->a_g2_j = va_arg(arg, uintmax_t);
        if (a->spe == 'o')
            a->arg_str_conv = ft_itoa_base_unsigned(a->a_g2_j, 8);
        else if (a->spe == 'u')
            a->arg_str_conv = ft_itoa_base_unsigned(a->a_g2_j, 10);
        else if (a->spe == 'x' || a->spe == 'X')
            a->arg_str_conv = ft_itoa_base_unsigned(a->a_g2_j, 16);
    }
    if (a->len[0] == 'z')
    {
        a->a_g2_z = va_arg(arg, size_t);
        if (a->spe == 'o')
            a->arg_str_conv = ft_itoa_base_unsigned(a->a_g2_z, 8);
        else if (a->spe == 'u')
            a->arg_str_conv = ft_itoa_base_unsigned(a->a_g2_z, 10);
        else if (a->spe == 'x' || a->spe == 'X')
            a->arg_str_conv = ft_itoa_base_unsigned(a->a_g2_z, 16);
    }
}

void    ft_select_args_group2_len_1(t_data *a, va_list arg)
{
    if (a->spe == 'O' || a->spe == 'U')
    {
        a->a_g2_O_U_l = va_arg(arg, unsigned long int);
        if (a->spe == 'O')
            a->arg_str_conv = ft_itoa_base_unsigned(a->a_g2_O_U_l, 8);
        if (a->spe == 'U')
            a->arg_str_conv = ft_itoa_base_unsigned(a->a_g2_O_U_l, 10);
    }
    else
    {
        ft_select_args_group2_len_1_part1(a, arg);
        ft_select_args_group2_len_1_part2(a, arg);
    }
}

void    ft_select_args_group2_len_2_part1(t_data *a, va_list arg)  // VERIFIED
{
    if (a->len[0] == 'h' && a->len[1] == 'h')
    {
        a->a_g2_hh = (unsigned char)va_arg(arg, int);
        if (a->spe == 'o')
            a->arg_str_conv = ft_itoa_base_unsigned(a->a_g2_hh, 8);
        else if (a->spe == 'u')
            a->arg_str_conv = ft_itoa_base_unsigned(a->a_g2_hh, 10);
        else if (a->spe == 'x' || a->spe == 'X')
            a->arg_str_conv = ft_itoa_base_unsigned(a->a_g2_hh, 16);
    }
}

void    ft_select_args_group2_len_2_part2(t_data *a, va_list arg)  // VERIFIED
{
    if (a->len[0] == 'l' && a->len[1] == 'l')
    {
        a->a_g2_ll = va_arg(arg, unsigned long long int);
        if (a->spe == 'o')
            a->arg_str_conv = ft_itoa_base_unsigned(a->a_g2_ll, 8);
        else if (a->spe == 'u')
            a->arg_str_conv = ft_itoa_base_unsigned(a->a_g2_ll, 10);
        else if (a->spe == 'x' || a->spe == 'X')
            a->arg_str_conv = ft_itoa_base_unsigned(a->a_g2_ll, 16);
    }
}

void    ft_select_args_group2_len_2(t_data *a, va_list arg)    // VERIFIED
{
    if (a->spe == 'O' || a->spe == 'U')
    {
        a->a_g2_O_U_l = va_arg(arg, unsigned long int);
        if (a->spe == 'O')
            a->arg_str_conv = ft_itoa_base_unsigned(a->a_g2_O_U_l, 8);
        if (a->spe == 'U')
            a->arg_str_conv = ft_itoa_base_unsigned(a->a_g2_O_U_l, 10);
    }
    else
    {
        ft_select_args_group2_len_2_part1(a, arg);
        ft_select_args_group2_len_2_part2(a, arg);
    }
}
