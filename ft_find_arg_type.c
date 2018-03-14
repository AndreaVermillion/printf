#include "printf.h"

/* ***** START ***** SELECT THE RIGHT ARGUMENT TYPE */

void    ft_find_arg_len(t_data *a)
{
    size_t i;
    char *temp;

    i = 0;
    if (a->grp == 1)
    {
        if ((a->spe == 'p') || (a->spe == 's' && a->arg_str_conv != NULL))
            a->arg_len = ft_strlen(a->arg_str_conv);

        if ((a->spe == 's') && (a->arg_str_conv == NULL))
        {
            temp = ft_strdup("(null)");
            a->arg_str_conv = temp;
            a->arg_len = ft_strlen(temp);
        }
        if ((a->spe == 'c' || a->spe == 'C') && ( a->arg_str_conv != NULL))
            a->arg_len = 1;

        if ((a->spe == 'c' || a->spe == 'C') && ( a->arg_str_conv == NULL))
            a->arg_len = 0;

        if (a->spe == 'S')
        {
            while (a->arg_uni_str_conv[i])
                i++;
            a->arg_len = i;
        }
    }
    else
        a->arg_len = ft_strlen(a->arg_str_conv);
}

void ft_select_args_len_2_group3(t_data *a, va_list arg) // VERIFIED
{
    if (a->spe == 'D')
    {
        a->a_g3_D_l = va_arg(arg, long int);
        a->arg_str_conv = ft_itoa_base_signed(a->a_g3_D_l, 10);
    }
    else
    {
        if (a->len[0] == 'h' && a->len[1] == 'h')
        {
            a->a_g3_hh = (signed char)va_arg(arg, int);
            a->arg_str_conv = ft_itoa_base_signed(a->a_g3_hh, 10);
        }
        if (a->len[0] == 'l' && a->len[1] == 'l')
        {
            a->a_g3_ll = va_arg(arg, long long int);
            a->arg_str_conv = ft_itoa_base_signed(a->a_g3_ll, 10);
        }
    }
}

void ft_select_args_len_2_group2_part1(t_data *a, va_list arg)  // VERIFIED
{
    if (a->len[0] == 'h' && a->len[1] == 'h')
    {
        a->a_g2_hh = (unsigned char)va_arg(arg, int);
        if (a->spe == 'o')
            a->arg_str_conv = ft_itoa_base_unsigned(a->a_g2_hh, 8);
        if (a->spe == 'u')
            a->arg_str_conv = ft_itoa_base_unsigned(a->a_g2_hh, 10);
        if (a->spe == 'x' || a->spe == 'X')
            a->arg_str_conv = ft_itoa_base_unsigned(a->a_g2_hh, 16);
    }
}

void ft_select_args_len_2_group2_part2(t_data *a, va_list arg)  // VERIFIED
{
    if (a->len[0] == 'l' && a->len[1] == 'l')
    {
        a->a_g2_ll = va_arg(arg, unsigned long long int);
        if (a->spe == 'o')
            a->arg_str_conv = ft_itoa_base_unsigned(a->a_g2_ll, 8);
        if (a->spe == 'u')
            a->arg_str_conv = ft_itoa_base_unsigned(a->a_g2_ll, 10);
        if (a->spe == 'x' || a->spe == 'X')
            a->arg_str_conv = ft_itoa_base_unsigned(a->a_g2_ll, 16);
    }
}

void ft_select_args_len_2_group2(t_data *a, va_list arg)    // VERIFIED
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
        ft_select_args_len_2_group2_part1(a, arg);
        ft_select_args_len_2_group2_part2(a, arg);
    }
}

void ft_select_args_len_1_group3_part1(t_data *a, va_list arg) // VERIFIED
{
    if (a->len[0] == 'l')
    {
        a->a_g3_D_l = va_arg(arg, long int);
        a->arg_str_conv = ft_itoa_base_signed(a->a_g3_D_l, 10);
    }
    if (a->len[0] == 'h')
    {
        a->a_g3_h = va_arg(arg, int);
        a->arg_str_conv = ft_itoa_base_signed(a->a_g3_h, 10);
    }
    if (a->len[0] == 'j')
    {
        a->a_g3_j = va_arg(arg, intmax_t);
        a->arg_str_conv = ft_itoa_base_signed(a->a_g3_j, 10);
    }
    if (a->len[0] == 'z')
    {
        a->a_g3_z = va_arg(arg, size_t);
        a->arg_str_conv = ft_itoa_base_unsigned(a->a_g3_z, 10);
    }
}

void ft_select_args_len_1_group3(t_data *a, va_list arg) // VERIFIED
{
    if (a->spe == 'D')
    {
        a->a_g3_D_l = va_arg(arg, long int);
        a->arg_str_conv = ft_itoa_base_signed(a->a_g3_D_l, 10);
    }
    else
        ft_select_args_len_1_group3_part1(a, arg);
}

void ft_select_args_len_1_group2_part1(t_data *a, va_list arg) // VERIFIED
{
    if (a->len[0] == 'l')
    {
        a->a_g2_O_U_l = va_arg(arg, unsigned long int);
        if (a->spe == 'o')
            a->arg_str_conv = ft_itoa_base_unsigned(a->a_g2_O_U_l, 8);
        if (a->spe == 'u')
            a->arg_str_conv = ft_itoa_base_unsigned(a->a_g2_O_U_l, 10);
        if (a->spe == 'x' || a->spe == 'X')
            a->arg_str_conv = ft_itoa_base_unsigned(a->a_g2_O_U_l, 16);
        }
    if (a->len[0] == 'h')
    {
        a->a_g2_h = (unsigned short) va_arg(arg, int);
        if (a->spe == 'o')
            a->arg_str_conv = ft_itoa_base_signed(a->a_g2_h, 8);
        if (a->spe == 'u')
            a->arg_str_conv = ft_itoa_base_signed(a->a_g2_h, 10);
        if (a->spe == 'x' || a->spe == 'X')
            a->arg_str_conv = ft_itoa_base_signed(a->a_g2_h, 16);
    }
}

void ft_select_args_len_1_group2_part2(t_data *a, va_list arg) // VERIFIED
{
    if (a->len[0] == 'j')
    {
        a->a_g2_j = va_arg(arg, uintmax_t);
        if (a->spe == 'o')
            a->arg_str_conv = ft_itoa_base_unsigned(a->a_g2_j, 8);
        if (a->spe == 'u')
            a->arg_str_conv = ft_itoa_base_unsigned(a->a_g2_j, 10);
        if (a->spe == 'x' || a->spe == 'X')
            a->arg_str_conv = ft_itoa_base_unsigned(a->a_g2_j, 16);
    }
    if (a->len[0] == 'z')
    {
        a->a_g2_z = va_arg(arg, size_t);
        if (a->spe == 'o')
            a->arg_str_conv = ft_itoa_base_unsigned(a->a_g2_z, 8);
        if (a->spe == 'u')
            a->arg_str_conv = ft_itoa_base_unsigned(a->a_g2_z, 10);
        if (a->spe == 'x' || a->spe == 'X')
            a->arg_str_conv = ft_itoa_base_unsigned(a->a_g2_z, 16);
    }
}

void ft_select_args_len_1_group2(t_data *a, va_list arg)
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
        ft_select_args_len_1_group2_part1(a, arg);
        ft_select_args_len_1_group2_part2(a, arg);
    }
}

void ft_select_args_len_1_group1(t_data *a, va_list arg)
{
    if (a->len[0] == 'h')
    {
        if (a->spe == 's')
        {
            a->a_g1_s_hs = va_arg(arg, char*);
            a->arg_str_conv = a->a_g1_s_hs;
            a->wtp = 2;
        }
        if (a->spe == 'c')
        {
            a->a_g1_c_hc = va_arg(arg, int);
            a->arg_char_conv = a->a_g1_c_hc;
            a->wtp = 4;
        }
    }
    if (a->len[0] == 'l')
    {
        if (a->spe == 'p')
        {
            a->a_g1_p = va_arg(arg, void*);
            a->arg_str_conv = ft_itoa_base_unsigned((unsigned long long)a->a_g1_p, 16);
            a->wtp = 6;
        }
        if (a->spe == 's') {
            a->a_g1_S_ls = va_arg(arg, unsigned int*);
            a->arg_uni_str_conv = a->a_g1_S_ls;
            a->wtp = 2;
        }
        if (a->spe == 'c') {
            a->a_g1_C_lc = va_arg(arg, unsigned int);
            a->arg_uni_char_conv = a->a_g1_C_lc;
            a->wtp = 4;
        }
    }
}

void ft_select_args_len_0_group3(t_data *a, va_list arg)
{
    if (a->spe == 'D')
    {
        a->a_g3_D_l = va_arg(arg, long int);
        a->arg_str_conv = ft_itoa_base_signed(a->a_g3_D_l, 10);
    }
    if (a->spe == 'd' || a->spe == 'i')
    {
        a->a_g3_h = va_arg(arg, int);
        a->arg_str_conv = ft_itoa_base_signed(a->a_g3_h, 10);
    }
}

void ft_select_args_len_0_group2(t_data *a, va_list arg)
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
    if (a->spe == 'O' || a->spe == 'U')
    {
        a->a_g2_O_U_l = va_arg(arg, unsigned long int);
        if (a->spe == 'O')
            a->arg_str_conv = ft_itoa_base_unsigned(a->a_g2_O_U_l, 8);
        if (a->spe == 'U')
            a->arg_str_conv = ft_itoa_base_unsigned(a->a_g2_O_U_l, 10);
    }
}

void ft_select_args_len_0_group1(t_data *a, va_list arg)
{
    if (a->spe == 's')
    {
        a->a_g1_s_hs = va_arg(arg, char*);
        a->arg_str_conv = a->a_g1_s_hs;
        a->wtp = 2;
    }
    if (a->spe == 'c')
    {
        a->a_g1_c_hc = va_arg(arg, int);
        a->arg_char_conv = a->a_g1_c_hc;
        a->wtp = 4;
    }
    if (a->spe == 'S')
    {
        a->a_g1_S_ls = va_arg(arg, unsigned int*);
        a->arg_uni_str_conv = a->a_g1_S_ls;
        a->wtp = 3;
    }
    if (a->spe == 'C')
    {
        a->a_g1_C_lc = va_arg(arg, unsigned int);
        a->arg_uni_char_conv = a->a_g1_C_lc;
        a->wtp = 5;
    }
    if (a->spe == 'p')
    {
        a->a_g1_p = va_arg(arg, void*);
        a->arg_str_conv = ft_itoa_base_unsigned((unsigned long long)a->a_g1_p, 16);
        a->wtp = 6;
    }
}

void ft_get_arg_type(t_data *a, va_list arg)
{
    size_t i;
    if (a->len == NULL)
    {
        if (a->grp == 1)
            ft_select_args_len_0_group1(a, arg);
        if (a->grp == 2)
            ft_select_args_len_0_group2(a, arg);
        if (a->grp == 3)
            ft_select_args_len_0_group3(a, arg);
    }
    else
    {
        i = ft_strlen(a->len);
        if (i == 1)
        {
            if (a->grp == 1)
                ft_select_args_len_1_group1(a, arg);
            if (a->grp == 2)
                ft_select_args_len_1_group2(a, arg);
            if (a->grp == 3)
                ft_select_args_len_1_group3(a, arg);
        }
        if (i == 2)
        {
            if (a->grp == 2)
                ft_select_args_len_2_group2(a, arg);
            if (a->grp == 3)
                ft_select_args_len_2_group3(a, arg);
        }
    }
}

/* ***** END ***** SELECT THE RIGHT ARGUMENT TYPE */