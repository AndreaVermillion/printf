#include "printf.h"


void    ft_get_arg_type(t_data *a, va_list arg)
{
    size_t i;
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
            if (a->grp == 2)
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
        ft_apply_precision(a);
        temp = ft_strdup(a->arg_str_conv);
        a->arg_len = ft_strlen(temp);
        ft_find_diff_arg_len_vs_wid_vs_pre(a);
        ft_apply_width_grp_1(a);
        if (a->arg_len == 0)
            ft_apply_special_zero_conditions_for_s(a);
        temp = ft_strdup(a->arg_str_conv);
        a->arg_len = ft_strlen(temp);
    }
    if (a->wtp == 4)
    {
        if (a->arg_len == 0)
            ft_apply_special_zero_conditions_for_c(a);
        else
            ft_apply_width_grp_1_c(a);
    }
    if (a->wtp == 6)
            ft_apply_width_grp_1_p(a);
}
