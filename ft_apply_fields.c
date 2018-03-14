#include "printf.h"

void    ft_find_diff_arg_len_vs_wid_vs_pre(t_data *a)
{
    if (a->arg_len >= a->wid_int)
        a->wid_gap = 0;
    if (a->arg_len < a->wid_int)
        a->wid_gap = a->arg_len;
}

void    ft_apply_special_zero_conditions_for_s_c(t_data *a)
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
        (a->fla_len == 2 && (a->fla[0] == ' ' && a->fla[1] == '0')) ||
        (a->fla_len == 2 && (a->fla[0] == ' ' && a->fla[1] == '-')))
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
    if ((a->fla_len == 0) ||
        (a->fla_len > 0 && a->fla[0] == '-') ||
        (a->fla_len > 0 && a->fla[0] == '0'))
    {
        if (a->wid_int == 0)
            a->arg_str_conv = ft_strdup("");
        else
            a->arg_str_conv = ft_strdup(" ");
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
    if (a->pre_int == 1 && (a->pre_raw[0] == '.' || a->pre_raw[0] == '0'))
    {
        if (a->wid_int <= 1)
            ft_apply_special_zero_conditions_wid_smaller_or_equal_to_1(a);
        else
            ft_apply_special_zero_conditions_wid_bigger_than_1(a);
    }
    if (a->spe == 's')
        ft_apply_special_zero_conditions_for_s_c(a);


}

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
    if (a->fla[0] == '0' || a->fla[0] == '+' || a->fla[0] == ' ')
    {
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
        }
    }
    if (a->fla[0] == '-')
        a->arg_str_conv = ft_cpy_to_nb(temp, a->arg_str_conv, 0, a->wid_int);
}

void    ft_apply_width_grp_3(t_data *a)
{
    char *temp;

    temp = ft_strnew(a->wid_int);
    ft_memset(temp, ' ', a->wid_int);
    if (a->wid_gap > 0)
    {
        if (a->fla_len == 0)
            a->arg_str_conv = ft_cpy_to_nb(temp, a->arg_str_conv, a->wid_int - a->wid_gap, a->wid_int);
        if (a->fla_len == 1)
            ft_apply_width_grp_3_len_1(a, temp, 0);
        if (a->fla_len == 2)
            ft_apply_width_grp_3_len_2(a, temp, 0);
    }
}

void    ft_apply_width_grp_2_len_2(t_data *a, char *temp, int i)
{
    if (a->wid_int >= a->arg_len)
    {
        if (a->fla[0] == '-' && a->fla[1] == '#')
            a->arg_str_conv = ft_cpy_to_nb(temp, a->arg_str_conv, 0, a->wid_int);
        if (a->fla[0] == '0' && a->fla[1] == '#')
            a->arg_str_conv = ft_cpy_to_nb(temp, a->arg_str_conv, a->wid_int - a->arg_len, a->wid_int);

        if (a->pre_int == 0 && a->fla[0] == '0') {
            if (a->spe == 'o' || a->spe == 'O') {
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

    temp_pointer = ft_strnew(a->arg_len + 2);
    ft_memset(temp_pointer, ' ', a->arg_len + 2);
    temp_pointer[0] = '0';
    temp_pointer[1] = 'x';
    a->arg_str_conv = ft_cpy_to_nb(temp_pointer, a->arg_str_conv,  2, a->arg_len + 2);
    a->arg_len = ft_strlen(a->arg_str_conv);
    if (a->wid_int > a->arg_len)
    {
        temp_pointer = ft_strnew(a->wid_int);
        ft_memset(temp_pointer, ' ', a->wid_int);
        if (a->fla_len == 0)
            a->arg_str_conv = ft_cpy_to_nb(temp_pointer, a->arg_str_conv, a->wid_int - a->arg_len, a->wid_int);
        if (a->fla_len == 1)
            a->arg_str_conv = ft_cpy_to_nb(temp_pointer, a->arg_str_conv,  0, a->wid_int + 2);
    }
    a->arg_len = ft_strlen(a->arg_str_conv);
}

void    ft_apply_width_grp_1_c(t_data *a)
{
    char *temp;
    char *temp_c;
    int  i;

    i = -1;
    temp_c = ft_strnew(1);
    temp_c[0] = a->arg_char_conv;
    temp = ft_strnew(a->wid_int);
    ft_memset(temp, ' ', a->wid_int);
    if (a->wid_int <= 1 && (a->pre_int == 0 || (a->pre_int == 1 && (a->pre_raw[0] == '.' || a->pre_raw[0] == '0'))))
    {
        ft_putchar(a->arg_char_conv);
        a->printed_char_counter++;
    }
    else
    {
        if (a->fla_len == 0)
        {
            a->arg_str_conv = ft_cpy_to_nb(temp, temp_c, a->wid_int - 1, a->wid_int);
            while (temp[++i] == ' ')
            {
                a->printed_char_counter++;
                ft_putchar(temp[i]);
            }
            ft_putchar(a->arg_char_conv);
            a->printed_char_counter++;
        }
        if (a->fla_len != 0)
        {
            a->arg_str_conv = ft_cpy_to_nb(temp, temp_c, 0, a->wid_int);
            ft_putchar(a->arg_char_conv);
            a->printed_char_counter++;
            while (temp[++i] == ' ')
            {
                a->printed_char_counter++;
                ft_putchar(temp[i]);
            }
        }
    }
}

void    ft_apply_width(t_data *a)
{
    if (a->grp == 1)
        ft_apply_width_grp_1(a);
    if (a->grp == 2)
        ft_apply_width_grp_2(a);
    if (a->grp == 3)
        ft_apply_width_grp_3(a);
}

void    ft_apply_fields(t_data *a)
{
    char *temp;
    temp = NULL;

    if (a->wtp == 1) // W// What to print? or What to process //  by default it is 1 = numbers || 2 == string of characters  || 3 = string of characters in unicode || 4 = just one character || 5 = just one character in unicode || 6 = pointer
    {
        a->arg_atoi_int = ft_atoi(a->arg_str_conv);
        ft_apply_precision(a);
        temp = ft_strdup(a->arg_str_conv);
        a->arg_len = ft_strlen(temp);
        ft_find_diff_arg_len_vs_wid_vs_pre(a);
        ft_apply_width(a);
        temp = ft_strdup(a->arg_str_conv);
        a->arg_len = ft_strlen(temp);
        if (a->arg_atoi_int == 0)
            ft_apply_special_zero_conditions(a);
        a->arg_len = ft_strlen(a->arg_str_conv);
    }
    if (a->wtp == 2)
    {
        ft_apply_pre_grp1(a);
        temp = ft_strdup(a->arg_str_conv);
        a->arg_len = ft_strlen(temp);
        ft_find_diff_arg_len_vs_wid_vs_pre(a);
        ft_apply_width_grp_1(a);
        if (a->arg_len == 0)
            ft_apply_special_zero_conditions_for_s_c(a);
        temp = ft_strdup(a->arg_str_conv);
        a->arg_len = ft_strlen(temp);
    }
    if (a->wtp == 4)
    {
        ft_apply_width_grp_1_c(a);
        if (a->arg_len == 0)
            ft_apply_special_zero_conditions_for_s_c(a);
        temp = ft_strdup(a->arg_str_conv);
        a->arg_len = ft_strlen(temp);
    }
    if (a->wtp == 6)
        ft_apply_width_grp_1_p(a);
}
