#include "printf.h"

void    ft_apply_width_grp_3_len_2(t_data *a, char *temp, int i)
{
    if ((a->fla[0] == '+' && a->fla[1] == '-') || (a->fla[0] == ' ' && a->fla[1] == '-'))
        a->arg_str_conv = ft_cpy_to_nb(temp, a->arg_str_conv, 0, a->wid_int);
    if ((a->fla[0] == '+' && a->fla[1] == '0') || (a->fla[0] == ' ' && a->fla[1] == '0'))
    {

        a->arg_str_conv = ft_cpy_to_nb(temp, a->arg_str_conv, a->wid_int - a->wid_gap, a->wid_int);
        if (a->pre_int == 0 && a->fla[0] == '+' && a->fla[1] == '0')
        {
            if (a->arg_atoi_int >= 0)
                temp[0] = '+';
            else
                temp[0] = '-';
            while (++i < a->wid_int - a->wid_gap + 1)
                temp[i] = '0';
            a->arg_str_conv = temp;
        }
        if (a->pre_int == 0 && a->fla[0] == ' ' && a->fla[1] == '0')
        {
            if (a->arg_atoi_int < 0)
                temp[0] = '-';
            while (++i < a->wid_int - a->wid_gap + 1)
                temp[i] = '0';
            a->arg_str_conv = temp;
        }
    }
}

void    ft_apply_width_grp_3_len_1(t_data *a, char *temp, int i)
{
    char *clean_leaks;
    if (a->fla[0] == '0' || a->fla[0] == '+' || a->fla[0] == ' ')
    {
        clean_leaks = a->arg_str_conv;
        a->arg_str_conv = ft_cpy_to_nb(temp, a->arg_str_conv, a->wid_int - a->wid_gap, a->wid_int);
        if (a->pre_int == 0 && a->fla[0] == '0')
        {
            if (a->arg_atoi_int >= 0)
            {
                i = -1;
                while (temp[++i] == ' ')
                    temp[i] = '0';
            }
            if (a->arg_atoi_int < 0)
            {
                temp[0] = '-';
                while (++i < a->wid_int - a->wid_gap + 1)
                    temp[i] = '0';
            }
            a->arg_str_conv = temp;
            free(clean_leaks);
        }
    }
    if (a->fla[0] == '-')
    {
        clean_leaks = a->arg_str_conv;
        a->arg_str_conv = ft_cpy_to_nb(temp, a->arg_str_conv, 0, a->wid_int);
        // free(clean_leaks);
//        free(temp);
    }
}

void    ft_apply_width_grp_3(t_data *a)
{
    char *temp;
//    char *clean_leaks;

    if (a->wid_gap > 0)
    {
        temp = ft_strnew(a->wid_int);
        ft_memset(temp, ' ', a->wid_int);
        if (a->fla_len == 0)
        {
//            clean_leaks = a->arg_str_conv;
            a->arg_str_conv = ft_cpy_to_nb(temp, a->arg_str_conv, a->wid_int - a->wid_gap, a->wid_int);
//            free(clean_leaks);
        }
        if (a->fla_len == 1)
            ft_apply_width_grp_3_len_1(a, temp, 0);
        if (a->fla_len == 2)
            ft_apply_width_grp_3_len_2(a, temp, 0);
    }
}

