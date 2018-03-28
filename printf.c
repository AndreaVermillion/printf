#include "printf.h"

#include <limits.h>
#include <locale.h>

void ft_start_search(t_data *a, va_list arg, char **temp, char **ret)
{
    ft_set_everything_to_zero(a);
    ft_find_group(a);
    ft_find_format(*temp + 1, a->spe, a);
    ft_find_all_fields(a, a->spe);
    if (ft_verify_all_fields(a, a->spe))
    {
        ft_get_arg_type(a, arg);
        ft_apply_fields(a);
//        ft_count_printed_characters(a);
        a->printed_char_counter = a->printed_char_counter + a->arg_len;
        *temp = *ret + 1;
    }
    else if (a->len_len > 0)
        *temp = *ret + a->len_len;
    else
        (*temp)++;
}

void ft_start_processs(t_data *a, char **temp, char **ret, va_list arg)
{
    if (ft_find_percent_with_percent(*temp))
        *temp = ft_print_percent_with_percent(*temp, a);
    else if (ft_find_percent_to_percent(*temp))
        *temp = ft_print_percent_to_wrong_type(*temp + 1, a, '%');
    else if ((*ret = ft_find_spe(*temp + 1, a)))
        ft_start_search(a, arg, temp, ret);
    else if (a->wrong_type)
        *temp = ft_print_percent_to_wrong_type(*temp + 1, a, a->wrong_type);
    else if (ft_find_percent_is_alone(*temp))
        (*temp)++;
}

int ft_printf(const char* fmt,...)
{
    char *temp;
    char *ret;
    int result;
    char *ptr;
    t_data  *a;
    a = (t_data*)malloc(sizeof(t_data));
    va_list arg;
    va_start(arg, fmt);
    ft_set_everything_to_zero(a);
    temp = ft_strdup(fmt);
    ptr = temp;
    a->printed_char_counter = 0;
    if (temp)
    {
        while (*temp)
        {
            a->wrong_type = 0;
            while (*temp != '\0' && *temp != '%' )
             ft_print_no_format_characters(a, &temp);
            if (*temp == '%')
                ft_start_processs(a, &temp, &ret, arg);
        }
    }
    va_end(arg);
    result = a->printed_char_counter;
    free(ptr);
    ft_memdel((void**)&a->len);
    free(a);
    return (result);
}

/*
int main(void)
{
    int r_o;
    int r_m;

    char *test_simple_mix;

    setlocale(LC_ALL, "");

    r_o = printf("%zi", LLONG_MIN);
printf("\n");
    r_m = ft_printf("%zi", LLONG_MIN);

printf("\n");
    printf("ret_origin => %i\n", r_o);
    printf("ret_mine_1 => %i\n", r_m);

}
*/
