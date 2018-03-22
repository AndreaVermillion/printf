#include "printf.h"

void    ft_apply_pre_grp3_negative_value(t_data *a)
{
    char *temp;
    int pre_gap;
    char *clean_leaks;

    if (a->pre_int >= a->arg_len)
    {
        if (a->pre_int == a->arg_len)
            pre_gap = 2;
        else
            pre_gap = a->pre_int - a->arg_len + 2;
        temp = ft_strnew(a->pre_int + 1);
        ft_memset(temp, '0', a->pre_int +1);
        temp[0] = '-';
        clean_leaks = a->arg_str_conv;
        a->arg_str_conv = ft_cpy_to_nb(temp, a->arg_str_conv + 1, pre_gap,  a->pre_int + 1);
        free(clean_leaks);
        free(temp);
    }
}

void    ft_apply_pre_grp2_grp3_positive_value_no_flags(t_data *a)
{
    char *temp;
    char *clean_leaks;

    if (a->pre_int <= a->arg_len)
    {
        temp = ft_strnew(a->arg_len);
        ft_memset(temp, '0', a->arg_len);
        clean_leaks = a->arg_str_conv;
        a->arg_str_conv = ft_cpy_to_nb(temp, a->arg_str_conv,0, a->arg_len + 1);
        free(clean_leaks);

    }
    else if (a->pre_int > a->arg_len)
    {
        temp = ft_strnew(a->pre_int);
        ft_memset(temp, '0', a->pre_int);
        clean_leaks = a->arg_str_conv;
        a->arg_str_conv = ft_cpy_to_nb(temp, a->arg_str_conv, a->pre_int - a->arg_len, a->pre_int);
        free(clean_leaks);
    }
}

void    ft_apply_pre_grp3_positive_value_len_2(t_data *a)
{
    char *temp;
    char *clean_leaks;

    ft_apply_pre_grp2_grp3_positive_value_no_flags(a);
    if ((a->fla[0] == '+' && a->fla[1] == '-')|| (a->fla[0] == '+' && a->fla[1] == '0'))
    {
        a->arg_len = ft_strlen(a->arg_str_conv);
        temp = ft_strnew(a->arg_len + 1);
        temp[0] = '+';
        clean_leaks = a->arg_str_conv;
        a->arg_str_conv = ft_cpy_to_nb(temp, a->arg_str_conv, 1, a->arg_len + 1);
        free(clean_leaks);
        free(temp);
    }
    if ((a->fla[0] == ' ' && a->fla[1] == '0') || (a->fla[0] == ' ' && a->fla[1] == '-'))
    {
        a->arg_len = ft_strlen(a->arg_str_conv);
        temp = ft_strnew(a->arg_len + 1);
        temp[0] = ' ';
        clean_leaks = a->arg_str_conv;
        a->arg_str_conv = ft_cpy_to_nb(temp, a->arg_str_conv, 1, a->arg_len + 1);
        free(clean_leaks);
        free(temp);
    }
}

void    ft_apply_pre_grp3_positive_value_len_1(t_data *a)
{
    char *temp;
    char *clean_leaks;

    ft_apply_pre_grp2_grp3_positive_value_no_flags(a);
    if (a->fla[0] == '+')
    {
        a->arg_len = ft_strlen(a->arg_str_conv);
        temp = ft_strnew(a->arg_len + 1);
        temp[0] = '+';
        clean_leaks = a->arg_str_conv;
        a->arg_str_conv = ft_cpy_to_nb(temp, a->arg_str_conv, 1, a->arg_len + 1);
        free(clean_leaks);
        free(temp);
    }
    if (a->fla[0] == ' ')
    {
        a->arg_len = ft_strlen(a->arg_str_conv);
        temp = ft_strnew(a->arg_len + 1);
        temp[0] = ' ';
        clean_leaks = a->arg_str_conv;
        a->arg_str_conv = ft_cpy_to_nb(temp, a->arg_str_conv, 1, a->arg_len + 1);
        free(clean_leaks);
        free(temp);
    }
}

void    ft_apply_pre_grp3(t_data *a)
{
    if (a->arg_atoi_int >= 0)
    {
        if (a->fla_len == 0)
            ft_apply_pre_grp2_grp3_positive_value_no_flags(a);
        else if (a->fla_len == 1)
            ft_apply_pre_grp3_positive_value_len_1(a);
        else if (a->fla_len == 2)
            ft_apply_pre_grp3_positive_value_len_2(a);
    }
    else if (a->arg_atoi_int < 0)
        ft_apply_pre_grp3_negative_value(a);
}
