#include "printf.h"

void    ft_apply_special_zero_conditions_for_c(t_data *a)
{
    int i;

    i = 1;
    if (a->wid_int > 1)
    {
        i = 0;
        while (++i < a->wid_int)
            ft_putchar(' ');
    }
    ft_putchar(a->arg_char_conv);
    a->arg_len = i;
}

void    ft_apply_special_zero_conditions_for_s(t_data *a)
{
    char *temp;
    int i;

    temp = ft_strnew(a->wid_int);
    i = -1;
    while (++i < a->wid_int)
        temp[i] = ' ';
    a->arg_str_conv = temp;
}

void    ft_apply_special_zero_conditions_wid_bigger_than_1(t_data *a)
{
    char *temp;
    int i;

    temp = ft_strnew(a->wid_int);
    if ((a->fla_len == 0) ||
        (a->fla_len == 1 && a->fla[0] == ' ') ||
        (a->fla_len == 1 && a->fla[0] == '-') ||
        (a->fla_len == 1 && a->fla[0] == '0') ||
        ((a->fla_len == 1) && (a->fla[0] == '#') && (a->spe == 'x' || a->spe == 'X')) ||
        (a->fla_len == 2 && (a->fla[0] == ' ' && a->fla[1] == '0')) ||
        (a->fla_len == 2 && (a->fla[0] == ' ' && a->fla[1] == '-'))||
        (a->fla_len == 2 && (a->fla[0] == '-' && a->fla[1] == '#')) ||
        (a->fla_len == 2 && (a->fla[0] == '0' && a->fla[1] == '#')))
    {
        i = -1;
        while (++i < a->wid_int)
            temp[i] = ' ';
    }
    if (a->fla_len == 2 && (a->fla[0] == '+' && a->fla[1] == '-'))
    {
        i = -1;
        while (++i < a->wid_int)
        {
            if (i == 0)
                temp[i] = '+';
            else
                temp[i] = ' ';
        }
    }

    else if ((a->fla_len == 1 && a->fla[0] == '+') ||
             (a->fla_len == 2 && (a->fla[0] == '+' && a->fla[1] == '0')))
    {
        i = -1;
        while (++i < a->wid_int)
        {
            temp[i] = '+';
            temp[i - 1] = ' ';
        }
    }
    a->arg_str_conv = temp;
}

void    ft_apply_special_zero_conditions_wid_smaller_or_equal_to_1(t_data *a)
{
    if ((a->fla_len == 2) && (a->fla[0] == '-') && (a->fla[1] == '#') && (a->spe == 'o' || a->spe == 'O'))
        a->arg_str_conv = ft_strdup("0");
    else if ((a->fla_len == 0) ||
             (a->fla_len > 0 && a->fla[0] == '-') ||
             (a->fla_len > 0 && a->fla[0] == '0') ||
             (a->fla_len > 0 && a->fla[0] == '#' && (a->spe == 'x' || a->spe == 'X')))
    {
        if (a->wid_int == 0)
        {
            a->arg_str_conv = ft_strdup("");
        }
        else
        {
            a->arg_str_conv = ft_strdup(" ");
        }
    }
    else
    {
        if (a->fla[0] == '+')
            a->arg_str_conv = ft_strdup("+");
        if (a->fla[0] == ' ')
            a->arg_str_conv = ft_strdup(" ");
    }
}

void    ft_apply_special_zero_conditions(t_data *a)
{
    if ((a->pre_int == 1 && (a->pre_raw[0] == '.' || a->pre_raw[0] == '0')))
    {
        if (a->wid_int <= 1)
            ft_apply_special_zero_conditions_wid_smaller_or_equal_to_1(a);
        else
            ft_apply_special_zero_conditions_wid_bigger_than_1(a);
    }
}
