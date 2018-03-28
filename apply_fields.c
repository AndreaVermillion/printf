#include "printf.h"


void    ft_get_arg_type(t_data *a, va_list arg)
{
    size_t i;
    a->wtp = 1;
    if (a->len == NULL)
    {
        if (a->grp == 1)
            ft_select_args_group1_len_0(a, arg);
        else if (a->grp == 2)
            ft_select_args_group2_len_0(a, arg);
        else
            ft_select_args_group3_len_0(a, arg);
    }
    else
    {
        i = ft_strlen(a->len);
        if (i == 1)
        {
            if (a->grp == 1)
                ft_select_args_group1_len_1(a, arg);
            else if (a->grp == 2)
                ft_select_args_group2_len_1(a, arg);
            else
                ft_select_args_group3_len_1(a, arg);
        }
        if (i == 2)
        {
            if (a->grp == 1)
                ft_select_args_group1_len_2(a, arg);
            else if (a->grp == 2)
                ft_select_args_group2_len_2(a, arg);
            else
                ft_select_args_group3_len_2(a, arg);
        }
    }
}

void    ft_apply_precision(t_data *a)
{
    if (a->grp == 1)
        ft_apply_pre_grp1(a);
    if (a->grp == 2)
        ft_apply_pre_grp2(a);
    if (a->grp == 3)
        ft_apply_pre_grp3(a);
}

void    ft_apply_width(t_data *a)
{
    if (a->grp == 1)
        ft_apply_width_grp_1(a);
    else if (a->grp == 2)
        ft_apply_width_grp_2(a);
    else
        ft_apply_width_grp_3(a);
}

int    ft_find_number_of_printable_bytes(unsigned int *tab, int size)
{
    int nb_of_printable_bytes;
    int bytes;
    int i;

    i = 0;
    bytes = 0;
    nb_of_printable_bytes = 0;
    while (nb_of_printable_bytes < size)
    {
        if (tab[i] <= 127)
            bytes = 1;
        else if (tab[i] >= 128 && tab[i] <= 2047)
            bytes = 2;
        else if (tab[i] >= 2048 && tab[i] <= 65335)
            bytes = 3;
        else if (tab[i] >= 65536 && tab[i] <= 1114111)
            bytes = 4;
        nb_of_printable_bytes += bytes;
        i++;
    }
    if (nb_of_printable_bytes > size)
        return(nb_of_printable_bytes - bytes);
    return (nb_of_printable_bytes);
}

int    ft_find_number_of_printable_characters(unsigned int *tab, int size)
{
    int nb_of_printable_bytes;
    int bytes;
    int i;

    i = 0;
    bytes = 0;
    nb_of_printable_bytes = 0;
    while (nb_of_printable_bytes < size)
    {
        if (tab[i] <= 127)
            bytes = 1;
        else if (tab[i] >= 128 && tab[i] <= 2047)
            bytes = 2;
        else if (tab[i] >= 2048 && tab[i] <= 65335)
            bytes = 3;
        else if (tab[i] >= 65536 && tab[i] <= 1114111)
            bytes = 4;
        nb_of_printable_bytes += bytes;
        i++;
    }
    if (nb_of_printable_bytes > size)
        return(i - 1);
    return (i);
}

void    ft_apply_width_ls_S_ls_S_pre_int_smaller_arg_len_fla_len_greater_than_zero(t_data *a)
{
    int i;
    int d;
    int nb_of_characters;
    int nb_of_bytes;

    nb_of_bytes = ft_find_number_of_printable_bytes(a->arg_uni_str_conv, a->pre_int);
    nb_of_characters = ft_find_number_of_printable_characters(a->arg_uni_str_conv, a->pre_int);

    d = -1;
    i = 0;
    while (++d < nb_of_characters)
        ft_unicode_convert(a->arg_uni_str_conv[d]);
    if (a->wid_int > nb_of_bytes)
    {
        i = -1;
        while (++i < a->wid_int - nb_of_bytes)
            ft_putchar(' ');
    }
    a->arg_len = i + nb_of_bytes;

}

void    ft_apply_width_ls_S_ls_S_pre_int_smaller_arg_len_fla_len_equal_zero(t_data *a)
{
    int i;
    int d;
    int nb_of_characters;
    int nb_of_bytes;

    nb_of_bytes = ft_find_number_of_printable_bytes(a->arg_uni_str_conv, a->pre_int);
    nb_of_characters = ft_find_number_of_printable_characters(a->arg_uni_str_conv, a->pre_int);
    i = 0;
    if (a->wid_int > nb_of_bytes)
    {
        i = -1;
        while (++i < a->wid_int - nb_of_bytes)
            ft_putchar(' ');
    }
    d = -1;
    while (++d < nb_of_characters)
        ft_unicode_convert(a->arg_uni_str_conv[d]);
    a->arg_len = i + nb_of_bytes;
}

void    ft_apply_width_ls_S_ls_S_pre_int_smaller_arg_len(t_data *a)
{
    if (a->fla_len == 0)
        ft_apply_width_ls_S_ls_S_pre_int_smaller_arg_len_fla_len_equal_zero(a);
    else
        ft_apply_width_ls_S_ls_S_pre_int_smaller_arg_len_fla_len_greater_than_zero(a);
}

void    ft_apply_width_ls_S_pre_int_greater_arg_len(t_data *a)
{
    int i;
    int d;

    if (a->fla_len == 0)
    {
        if (a->arg_len >= a->wid_int)
        {
            i = -1;
            while (a->arg_uni_str_conv[++i])
                ft_unicode_convert(a->arg_uni_str_conv[i]);
        }
        else
        {
            i = -1;
            while (++i < a->wid_int - a->arg_len)
                ft_putchar(' ');
            d = -1;
            while (a->arg_uni_str_conv[++d])
                ft_unicode_convert(a->arg_uni_str_conv[d]);
            a->arg_len = a->arg_len + i;
        }
    }
    else
    {
        d = -1;
        while (a->arg_uni_str_conv[++d])
            ft_unicode_convert(a->arg_uni_str_conv[d]);
        i = -1;
        while (++i < a->wid_int - a->arg_len)
            ft_putchar(' ');
        a->arg_len = a->arg_len + i;
    }

}

void    ft_apply_width_ls_S_pre_int_zero_len_equal_zero(t_data *a)
{
    int i;
    int d;

    if (a->arg_len >= a->wid_int)
    {
        i = -1;
        while (a->arg_uni_str_conv[++i])
            ft_unicode_convert(a->arg_uni_str_conv[i]);
    }
    else
    {
        i = -1;
        while (++i < a->wid_int - a->arg_len)
            ft_putchar(' ');
        d = -1;
        while (a->arg_uni_str_conv[++d])
            ft_unicode_convert(a->arg_uni_str_conv[d]);
        a->arg_len = a->arg_len + i;
    }
}

void    ft_apply_width_ls_S_pre_int_zero(t_data *a)
{
    int i;
    int d;

    if (a->fla_len == 0)
        ft_apply_width_ls_S_pre_int_zero_len_equal_zero(a);
    else
    {
        d = -1;
        while (a->arg_uni_str_conv[++d])
            ft_unicode_convert(a->arg_uni_str_conv[d]);
        i = -1;
        while (++i < a->wid_int - a->arg_len)
            ft_putchar(' ');
        a->arg_len = a->arg_len + i;
    }
}

void    ft_apply_width_ls_S(t_data *a)
{
    if (!(a->arg_len == 6 && a->arg_uni_str_conv == NULL))
    {
        if (a->pre_int == 0)
            ft_apply_width_ls_S_pre_int_zero(a);
        else if (a->pre_int >= a->arg_len)
            ft_apply_width_ls_S_pre_int_greater_arg_len(a);
        else if (a->pre_int < a->arg_len)
            ft_apply_width_ls_S_ls_S_pre_int_smaller_arg_len(a);
    }
}

void    ft_apply_width_lc_C(t_data *a)
{
    int i;

    if (a->fla_len == 0)
    {
        if (a->arg_len >= a->wid_int)
            ft_unicode_convert(a->arg_uni_char_conv);
        else
        {
            i = -1;
            while (++i < a->wid_int - a->arg_len)
                ft_putchar(' ');
            ft_unicode_convert(a->arg_uni_char_conv);
            a->arg_len = a->arg_len + i;
        }
    }
    else
    {
        if (a->arg_len >= a->wid_int)
            ft_unicode_convert(a->arg_uni_char_conv);
        else
        {
            i = a->arg_len - 1;
            ft_unicode_convert(a->arg_uni_char_conv);
            while (++i < a->wid_int)
                ft_putchar(' ');
            a->arg_len = i;
        }
    }
}

void    ft_apply_fields(t_data *a)
{
    char *temp;

    if (a->wtp == 1) // W// What to print? or What to process //  by default it is 1 = numbers || 2 == string of characters  || 3 = string of characters in unicode || 4 = just one character || 5 = just one character in unicode || 6 = pointer
    {
        a->arg_len = ft_strlen(a->arg_str_conv); // 1 = numbers
        a->arg_atoi_int = ft_atoi(a->arg_str_conv);
        ft_apply_precision(a);
        temp = ft_strdup(a->arg_str_conv);
        a->arg_len = ft_strlen(temp);
        ft_find_diff_arg_len_vs_wid_vs_pre(a);
        ft_apply_width(a);
        free(temp);
        temp = ft_strdup(a->arg_str_conv);
        a->arg_len = ft_strlen(temp);
        if (a->arg_atoi_int == 0)
            ft_apply_special_zero_conditions(a);
        a->arg_len = ft_strlen(a->arg_str_conv);
        ft_memdel((void **)&a->fla);
        ft_memdel((void **)&a->pre_raw);
        ft_putstr(a->arg_str_conv);
        free(temp);
    }
    if (a->wtp == 2) //string of characters
    {
        a->arg_len = ft_strlen(a->arg_str_conv);
        ft_apply_precision(a);
        temp = ft_strdup(a->arg_str_conv);
        a->arg_len = ft_strlen(temp);
        ft_find_diff_arg_len_vs_wid_vs_pre(a);
        ft_apply_width_grp_1(a);
        if (a->arg_len == 0)
            ft_apply_special_zero_conditions_for_s(a);
        free(temp);
        temp = ft_strdup(a->arg_str_conv);
        a->arg_len = ft_strlen(temp);
        ft_memdel((void **)&a->fla);
        ft_memdel((void **)&a->pre_raw);
        ft_putstr(a->arg_str_conv);
        free(temp);
    }
    if (a->wtp == 3) //string of characters in unicode
    {
        ft_apply_width_ls_S(a);
    }

    if (a->wtp == 4) // just one character
    {
        if (a->arg_len == 0)
            ft_apply_special_zero_conditions_for_c(a);
        else
            ft_apply_width_grp_1_c(a);
        ft_memdel((void **)&a->fla);
    }
    if (a->wtp == 5) // 4 = just one character in unicode
    {
//        printf("arg_len[C or lc] -> %i", a->arg_len);
        ft_apply_width_lc_C(a);

    }
    if (a->wtp == 6)
    {
        ft_apply_width_grp_1_p(a);
        ft_memdel((void **)&a->fla);
        ft_memdel((void **)&a->pre_raw);
        ft_putstr(a->arg_str_conv);
    }
}
