#include "printf.h"

void    ft_apply_width_grp_1(t_data *a)
{
    char *temp;

    temp = ft_strnew(a->wid_int);
    ft_memset(temp, ' ', a->wid_int);
    if (a->wid_gap > 0 && a->fla_len == 0)
        a->arg_str_conv = ft_cpy_to_nb(temp, a->arg_str_conv, a->wid_int - a->wid_gap, a->wid_int);
    if (a->wid_gap > 0 && a->fla_len != 0)
        a->arg_str_conv = ft_cpy_to_nb(temp, a->arg_str_conv, 0, a->wid_int);
}

void    ft_apply_width_grp_1_p(t_data *a)
{
    char *temp_pointer;
    char *clean_leaks;
    int i;

    if (a->pre_int == 1 && (a->pre_raw[0] == '.' || a->pre_raw[0] == '0'))
        i = 1;
    else
        i = 2;
    temp_pointer = ft_strnew(a->arg_len + i);
    ft_memset(temp_pointer, ' ', a->arg_len + i);
    temp_pointer[0] = '0';
    temp_pointer[1] = 'x';
    clean_leaks = a->arg_str_conv;
    a->arg_str_conv = ft_cpy_to_nb(temp_pointer, a->arg_str_conv,  2, a->arg_len + i);
    a->arg_len = ft_strlen(a->arg_str_conv);
    if (a->wid_int > a->arg_len)
    {
        temp_pointer = ft_strnew(a->wid_int);
        ft_memset(temp_pointer, ' ', a->wid_int);
        if (a->fla_len == 0)
        {
            a->arg_str_conv = ft_cpy_to_nb(temp_pointer, a->arg_str_conv, a->wid_int - a->arg_len, a->wid_int);
            // free(clean_leaks);
            // free(temp_pointer);
        }
        if (a->fla_len == 1)
        {
            a->arg_str_conv = ft_cpy_to_nb(temp_pointer, a->arg_str_conv, 0, a->wid_int + 2);
            // free(clean_leaks);
            // free(temp_pointer);
        }
    }
    a->arg_len = ft_strlen(a->arg_str_conv);
}

void    ft_apply_width_grp_1_c(t_data *a)
{
    char *temp;
    char *clean_leaks;
    char *temp_c;
    int  i;

    temp_c = ft_strnew(1);
    temp_c[0] = a->arg_char_conv;
    temp = ft_strnew(a->wid_int);
    ft_memset(temp, ' ', a->wid_int);
    if (a->wid_int <= 1 && (a->pre_int == 0 || (a->pre_int == 1 && (a->pre_raw[0] == '.' || a->pre_raw[0] == '0'))))
    {
        ft_putchar(a->arg_char_conv);
        a->arg_len = 1;
    }
    else
    {
        if (a->fla_len == 0)
        {
            clean_leaks = a->arg_str_conv;
            a->arg_str_conv = ft_cpy_to_nb(temp, temp_c, a->wid_int - 1, a->wid_int);
            i = -1;
            while (temp[++i] == ' ')
                ft_putchar(temp[i]);
            ft_putchar(a->arg_char_conv);
            // free(clean_leaks);
        }
        if (a->fla_len != 0)
        {
            clean_leaks = a->arg_str_conv;
            a->arg_str_conv = ft_cpy_to_nb(temp, temp_c, 0, a->wid_int);
            ft_putchar(a->arg_char_conv);
            i = 0;
            while (temp[++i] == ' ')
                ft_putchar(temp[i]);
            // free(clean_leaks);
        }
        a->arg_len = ft_strlen(a->arg_str_conv);
        // free(temp);
    }
}

