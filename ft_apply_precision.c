#include "printf.h"

char	*ft_cpy_to_nb(char *dst, const char *src, size_t start, int n)
{
    size_t	i;

    i = 0;
    while (start < (size_t)n && src[i] != 0)
    {
        dst[start] = src[i];
        i++;
        start++;
    }
    return (dst);
}

void    ft_apply_pre_grp3_negative_value(t_data *a)
{
    char *temp;
    int pre_gap;

    if (a->pre_int >= a->arg_len)
    {
        if (a->pre_int == a->arg_len)
            pre_gap = 2;
        else
            pre_gap = a->pre_int - a->arg_len + 2;

        temp = ft_strnew(a->pre_int + 1);
        ft_memset(temp, '0', a->pre_int +1);
        temp[0] = '-';
        a->arg_str_conv = ft_cpy_to_nb(temp, a->arg_str_conv + 1, pre_gap,  a->pre_int + 1);
    }
}

void    ft_apply_pre_grp2_grp3_positive_value_no_flags(t_data *a)
{
    char *temp;

    if (a->pre_int <= a->arg_len)
    {
        temp = ft_strnew(a->arg_len);
        ft_memset(temp, '0', a->arg_len );
        a->arg_str_conv = ft_cpy_to_nb(temp, a->arg_str_conv,0, a->arg_len + 1);
    }
    if (a->pre_int > a->arg_len)
    {
        temp = ft_strnew(a->pre_int);
        ft_memset(temp, '0', a->pre_int);
        a->arg_str_conv = ft_cpy_to_nb(temp, a->arg_str_conv, a->pre_int - a->arg_len, a->pre_int);
    }
}

void    ft_apply_pre_grp3_positive_value_len_2(t_data *a)
{
    char *temp;

    ft_apply_pre_grp2_grp3_positive_value_no_flags(a);
    if ((a->fla[0] == '+' && a->fla[1] == '-')|| (a->fla[0] == '+' && a->fla[1] == '0'))
    {
        a->arg_len = ft_strlen(a->arg_str_conv);
        temp = ft_strnew(a->arg_len + 1);
        temp[0] = '+';
        a->arg_str_conv = ft_cpy_to_nb(temp, a->arg_str_conv, 1, a->arg_len + 1);
    }
    if ((a->fla[0] == ' ' && a->fla[1] == '0') || (a->fla[0] == ' ' && a->fla[1] == '-'))
    {
        a->arg_len = ft_strlen(a->arg_str_conv);
        temp = ft_strnew(a->arg_len + 1);
        temp[0] = ' ';
        a->arg_str_conv = ft_cpy_to_nb(temp, a->arg_str_conv, 1, a->arg_len + 1);
    }
}

void    ft_apply_pre_grp3_positive_value_len_1(t_data *a)
{
    char *temp;

    ft_apply_pre_grp2_grp3_positive_value_no_flags(a);
    if (a->fla[0] == '+')
    {
        a->arg_len = ft_strlen(a->arg_str_conv);
        temp = ft_strnew(a->arg_len + 1);
        temp[0] = '+';
        a->arg_str_conv = ft_cpy_to_nb(temp, a->arg_str_conv, 1, a->arg_len + 1);
    }
    if (a->fla[0] == ' ')
    {
        a->arg_len = ft_strlen(a->arg_str_conv);
        temp = ft_strnew(a->arg_len + 1);
        temp[0] = ' ';
        a->arg_str_conv = ft_cpy_to_nb(temp, a->arg_str_conv, 1, a->arg_len + 1);
    }
}

void    ft_apply_pre_grp2_hash_x(t_data *a)
{
    char *temp;
    int i;
    int d;

    if (a->arg_len == 1 && a->pre_int == 2)
    {
        temp = ft_strnew(a->arg_len + 3);
        ft_memset(temp, '0', a->arg_len + 3);
        temp[1] = 'x';
        a->arg_str_conv = ft_cpy_to_nb(temp, a->arg_str_conv, 3, a->arg_len + 3);
    }
    else
    {
        if (a->arg_len <= 2)
            i = 2;
        else
            i = a->arg_len;
    if (a->pre_int <= i) {
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
}

void    ft_apply_pre_grp2_hash_o(t_data *a)
{
    char *temp;
    int i;

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

void    ft_apply_pre_grp3(t_data *a)
{
    if (a->arg_atoi_int >= 0)
    {
        if (a->fla_len == 0)
            ft_apply_pre_grp2_grp3_positive_value_no_flags(a);
        if (a->fla_len == 1)
            ft_apply_pre_grp3_positive_value_len_1(a);
        if (a->fla_len == 2)
            ft_apply_pre_grp3_positive_value_len_2(a);
    }
    if (a->arg_atoi_int < 0)
            ft_apply_pre_grp3_negative_value(a);

}

void    ft_apply_pre_grp2(t_data *a)
{
    if (a->fla_len == 0)
        ft_apply_pre_grp2_grp3_positive_value_no_flags(a);
    if (a->fla_len == 1)
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

void    ft_apply_pre_grp1(t_data *a)
{
    char *temp;
    if (a->pre_raw != NULL)
    {
        if (a->spe == 's') {
            if ((a->pre_int == 0 && a->pre_raw[0] == '0') || (a->pre_int == 1 && a->pre_raw[0] == '.'))
            {
                temp = ft_strnew(1);
                temp[0] = ' ';
                a->arg_str_conv = temp;
            }
            else if (a->pre_int < a->arg_len)
            {
                temp = ft_strnew(a->pre_int);
                a->arg_str_conv = ft_strncpy(temp, a->arg_str_conv, a->pre_int);
            }
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
