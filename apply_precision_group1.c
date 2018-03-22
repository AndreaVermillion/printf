#include "printf.h"

void    ft_apply_pre_grp1(t_data *a)
{
    char *temp;

    if (a->pre_raw != NULL)
    {
        if (a->spe == 's')
        {
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
                free(temp);
            }
        }
    }
}