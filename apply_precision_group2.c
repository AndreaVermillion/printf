#include "printf.h"


void    ft_apply_pre_grp2_hash_x_part_2(t_data *a)
{
    char *temp;
    int i;
    int d;

    if (a->arg_len <= 2)
        i = 2;
    else
        i = a->arg_len;
    if (a->pre_int <= i)
    {
        temp = ft_strnew(a->arg_len + 2);
        ft_memset(temp, '0', a->arg_len + 2);
        temp[1] = 'x';
        a->arg_str_conv = ft_cpy_to_nb(temp, a->arg_str_conv, 2, a->arg_len + 2);
    }
    if (a->pre_int > i)
    {
        temp = ft_strnew(a->pre_int + 2);
        ft_memset(temp, '0', a->pre_int + 2);
        temp[1] = 'x';
        if (a->arg_len < a->pre_int)
            d = a->pre_int - a->arg_len + 2;
        else
            d = a->pre_int;
        a->arg_str_conv = ft_cpy_to_nb(temp, a->arg_str_conv, d, a->pre_int + 2);
    }
}

void    ft_apply_pre_grp2_hash_x_part_1(t_data *a)
{
    char *temp;

    temp = ft_strnew(a->arg_len + 3);
    ft_memset(temp, '0', a->arg_len + 3);
    temp[1] = 'x';
    a->arg_str_conv = ft_cpy_to_nb(temp, a->arg_str_conv, 3, a->arg_len + 3);
}

void    ft_apply_pre_grp2_hash_x_zero_condition(t_data *a)
{
    char *temp;

    if (a->pre_int == 0)
        a->arg_str_conv = ft_strdup("0");
    else
    {
        temp = ft_strnew(a->pre_int);
        ft_memset(temp, '0', a->pre_int);
        a->arg_str_conv = temp;
    }
}

void    ft_apply_pre_grp2_hash_x(t_data *a)
{
    if (a->arg_atoi_int == 0)
        ft_apply_pre_grp2_hash_x_zero_condition(a);
    else if (a->arg_len == 1 && a->pre_int == 2)
        ft_apply_pre_grp2_hash_x_part_1 (a);
    else
        ft_apply_pre_grp2_hash_x_part_2(a);
}

void    ft_apply_pre_grp2_hash_o_zero_condition(t_data *a)
{
    char *temp;

    if (a->pre_int == 0)
        a->arg_str_conv = ft_strdup("0");
    else
    {
        temp = ft_strnew(a->pre_int);
        ft_memset(temp, '0', a->pre_int);
        a->arg_str_conv = temp;
    }
}

void    ft_apply_pre_grp2_hash_o(t_data *a)
{
    char *temp;
    int i;

    if (a->arg_atoi_int == 0)
        ft_apply_pre_grp2_hash_o_zero_condition(a);
    else
    {
        if (a->arg_len <= 1)
            i = 1;
        else
            i = a->arg_len;
        if (a->pre_int <= i)
        {
            temp = ft_strnew(a->arg_len);
            ft_memset(temp, '0', a->arg_len);
            a->arg_str_conv = ft_cpy_to_nb(temp, a->arg_str_conv, 1, a->arg_len + 1);
        }
        if (a->pre_int > i)
        {
            temp = ft_strnew(a->pre_int);
            ft_memset(temp, '0', a->pre_int);
            a->arg_str_conv = ft_cpy_to_nb(temp, a->arg_str_conv, (a->pre_int) - a->arg_len, a->pre_int);
        }
    }
}

void    ft_apply_pre_grp2(t_data *a)
{
    if (a->fla_len == 0)
        ft_apply_pre_grp2_grp3_positive_value_no_flags(a);
    else if (a->fla_len == 1)
    {
        if (a->fla[0] != '#')
            ft_apply_pre_grp2_grp3_positive_value_no_flags(a);

        if ((a->fla[0] == '#') && !(a->spe == 'u' || a->spe == 'U'))
        {
            if (a->spe == 'x' || a->spe == 'X')
                ft_apply_pre_grp2_hash_x(a);

            if (a->spe == 'o' || a->spe == 'O')
                ft_apply_pre_grp2_hash_o(a);
        }
    }
    if ((a->fla_len == 2) && !(a->spe == 'u' || a->spe == 'U'))
    {
        if (a->spe == 'x' || a->spe == 'X')
            ft_apply_pre_grp2_hash_x(a);

        if (a->spe == 'o' || a->spe == 'O')
            ft_apply_pre_grp2_hash_o(a);
    }
}