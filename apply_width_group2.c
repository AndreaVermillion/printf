#include "printf.h"

void    ft_apply_width_grp_2_len_2(t_data *a, char *temp, int i)
{
    if (a->wid_int >= a->arg_len)
    {
        if (a->fla[0] == '-' && a->fla[1] == '#')
            a->arg_str_conv = ft_cpy_to_nb(temp, a->arg_str_conv, 0, a->wid_int);
        else if (a->fla[0] == '0' && a->fla[1] == '#')
            a->arg_str_conv = ft_cpy_to_nb(temp, a->arg_str_conv, a->wid_int - a->arg_len, a->wid_int);
        if (a->pre_int == 0 && a->fla[0] == '0')
        {
            if (a->spe == 'o' || a->spe == 'O')
            {
                i = -1;
                while (temp[++i] == ' ')
                    temp[i] = '0';
            }
            if (a->spe == 'x' || a->spe == 'X')
            {
                i = 1;
                temp[0] = '0';
                temp[1] = 'x';
                while (temp[++i])
                {
                    if (temp[i] == ' ')
                        temp[i] = '0';
                    if (temp[i] == 'x')
                    {
                        temp[i] = '0';
                        break;
                    }
                }
            }
            a->arg_str_conv = temp;
        }
    }
}

void    ft_apply_width_grp_2_len_1(t_data *a, char *temp, int i)
{
    if (a->fla[0] == '0')
        a->arg_str_conv = ft_cpy_to_nb(temp, a->arg_str_conv, a->wid_int - a->wid_gap, a->wid_int);
    if (a->fla[0] == '-')
        a->arg_str_conv = ft_cpy_to_nb(temp, a->arg_str_conv, 0, a->wid_int);
    if (a->wid_int > a->arg_len && a->fla[0] == '#')
        a->arg_str_conv = ft_cpy_to_nb(temp, a->arg_str_conv,  a->wid_int - a->arg_len, a->wid_int);
    if (a->pre_int == 0 && a->fla[0] == '0')
    {
        i = -1;
        while (temp[++i] == ' ')
            temp[i] = '0';
        a->arg_str_conv = temp;
    }
}

void    ft_apply_width_grp_2(t_data *a)
{
    char *temp;
    int i;

    temp = ft_strnew(a->wid_int);
    ft_memset(temp, ' ', a->wid_int);
    if (a->wid_gap > 0)
    {
        if (a->fla_len == 0)
            a->arg_str_conv = ft_cpy_to_nb(temp, a->arg_str_conv, a->wid_int - a->wid_gap, a->wid_int);
        if (a->fla_len == 1)
            ft_apply_width_grp_2_len_1(a, temp, 0);
        if (a->fla_len == 2)
            ft_apply_width_grp_2_len_2(a, temp, 0);
    }
    if (a->spe == 'X')
    {
        temp = NULL;
        temp = ft_strdup(a->arg_str_conv);
        i = 0;
        while (temp[i])
        {
            if (temp[i] >=97 && temp [i] <= 122)
                temp[i] = temp[i] - 32;
            i++;
        }
        a->arg_str_conv = temp;
    }
}

