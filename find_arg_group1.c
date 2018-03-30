#include "printf.h"

void    ft_select_args_group1_len_0(t_data *a, va_list arg)
{
    if (a->spe == 's') //CORRECT
    {
        a->a_g1_s_hs = va_arg(arg, char*);
        a->arg_str_conv = a->a_g1_s_hs;
        a->wtp = 2;
        if (a->arg_str_conv)
            a->arg_len = ft_strlen(a->arg_str_conv);
        else
        {
            a->arg_str_conv = ft_strdup("(null)");
            a->arg_len = 6;
        }
    }
    else if (a->spe == 'c') //CORRECT
    {
        a->a_g1_c_hc = va_arg(arg, int);
        a->arg_char_conv = a->a_g1_c_hc;
        a->wtp = 4;
        if (a->arg_char_conv)
            a->arg_len = 1;
        else
            a->arg_len = 0;
    }
    else if (a->spe == 'S') // CORRECT
    {
        a->a_g1_S_ls = va_arg(arg, unsigned int*);
        a->arg_uni_str_conv = a->a_g1_S_ls;
        a->wtp = 3;
        if (a->arg_uni_str_conv)
            a->arg_len = ft_find_arg_len_string_unicode(a);
        else
        {
            ft_putstr("(null)");
            a->arg_len = 6;
        }
    }
    else if (a->spe == 'C') // CORRECT
    {
        a->a_g1_C_lc = va_arg(arg, unsigned int);
        a->arg_uni_char_conv = a->a_g1_C_lc;
        a->wtp = 5;
        a->arg_len = ft_find_arg_len_char_unicode(a);
    }
    else if (a->spe == 'p')
    {
        a->a_g1_p = va_arg(arg, void*);
        a->arg_str_conv = ft_itoa_base_unsigned((unsigned long long)a->a_g1_p, 16);
        a->wtp = 6;
        a->arg_len = ft_strlen(a->arg_str_conv);
    }
}

void    ft_select_args_group1_len_1(t_data *a, va_list arg)
{
    if (a->len[0] == 'h')
    {
        if (a->spe == 's') // CORRECT
        {
            a->a_g1_s_hs = va_arg(arg, char*);
            a->arg_str_conv = a->a_g1_s_hs;
            a->wtp = 2;
            a->arg_len = ft_strlen(a->arg_str_conv);
        }
        else if (a->spe == 'c') // CORRECT
        {
            a->a_g1_c_hc = va_arg(arg, int);
            a->arg_char_conv = a->a_g1_c_hc;
            a->wtp = 4;
            if (a->arg_char_conv)
                a->arg_len = 1;
            else
                a->arg_len = 0;
        }
    }
    else if (a->len[0] == 'l')
    {
        if (a->spe == 'p')  // CORRECT
        {
            a->a_g1_p = va_arg(arg, void*);
            a->arg_str_conv = ft_itoa_base_unsigned((unsigned long long)a->a_g1_p, 16);
            a->wtp = 6;
            a->arg_len = ft_strlen(a->arg_str_conv);
        }
        else if (a->spe == 's')  // CORRECT
        {
            a->a_g1_S_ls = va_arg(arg, unsigned int*);
            a->arg_uni_str_conv = a->a_g1_S_ls;
            a->wtp = 3;
            if (a->arg_uni_str_conv)
                a->arg_len = ft_find_arg_len_string_unicode(a);
            else
            {
                ft_putstr("(null)");
                a->arg_len = 6;
            }
        }
        else if (a->spe == 'c') // CORRECT
        {
            a->a_g1_C_lc = va_arg(arg, unsigned int);
            a->arg_uni_char_conv = a->a_g1_C_lc;
            a->wtp = 5;
            a->arg_len = ft_find_arg_len_char_unicode(a);
        }
    }
}

void    ft_select_args_group1_len_2(t_data *a, va_list arg) //--------------------///
{
    if (a->len[0] == 'h' && a->len[1] == 'h')
    {
        if (a->spe == 'S')
        {
            a->a_g1_S_ls = va_arg(arg, unsigned int*);
            a->arg_uni_str_conv = a->a_g1_S_ls;
            a->wtp = 3;
            if (a->arg_uni_str_conv)
                a->arg_len = ft_find_arg_len_string_unicode(a);
            else
            {
                ft_putstr("(null)");
                a->arg_len = 6;
            }
        }
        else if (a->spe == 'C') // CORRECT
        {
            a->a_g1_C_lc = va_arg(arg, unsigned int);
            a->arg_uni_char_conv = a->a_g1_C_lc;
            a->wtp = 5;
            a->arg_len = ft_find_arg_len_char_unicode(a);
        }
    }
}