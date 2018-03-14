#include "printf.h"

#include <limits.h>

int ft_printf(char* fmt,...)
{
    char *temp;
    char *ret;

    t_data  *a;
    a = (t_data*)malloc(sizeof(t_data));
    va_list arg;
    va_start(arg, fmt); // init
    temp = fmt;

    a->printed_char_counter = 0;
    if (temp != NULL)
    {
        while (*temp)
        {
            while (*temp != '\0' && *temp != '%' )
            {
                a->printed_char_counter++;
                ft_putchar(*temp);
                temp++;
            }
            if (*temp == '%')
            {
                if (ft_find_percent_glued_percent(temp))
                    temp = ft_print_percent_glued_percent(temp, a);
                else if (ft_find_percent_to_percent(temp))
                    temp = ft_print_percent_to_percent(temp, a);
//                else if (ft_find_percent_to_wrong_type(temp))
//                    temp = ft_print_percent_to_wrong_type(temp);
                if ((ret = ft_find_spe(temp)))                /* Step 1: Find '%' */
                {
                    ft_set_everything_to_zero(a);
                    ft_find_group(ret[0], a);                                      /* Step 2: Find appropriate group ---  group 1 ===> // s_S_c_C_p) || for group 2 ===> // o_O_x_X_u_U || for group 3 ===> // d_D_i */
                    ft_find_format(temp + 1, ret[0], a);                           /* Step 3: Store the entire format in struct */
                    ft_find_all_fields(a, ret[0]);                                 /* Step 4: From the format, find and store each separate fields in struct */
                    if (ft_verify_all_fields(a, ret[0]))                           /* Step 5: Validate the content for each fields */
                    {
                        ft_get_arg_type(a, arg);                                /* Step 6: Get the right arg type in struct */
                        ft_find_arg_len(a);                                     /* Step 7: Find lengths of different args */
                        ft_apply_fields(a);                                     /* Step 8: Apply fields on arg */
                        ft_count_printed_characters(a);                         /* Step 9: Count everything has been printed (selected based on the type) */
                    }
                    temp = ret;
                    temp++;
                }
                else if (ft_find_percent_is_alone(temp))
                    temp++;
            }
        }
    }       /* Step 10: Print the results (selected based on the type) */
    va_end(arg); // close
    return (a->printed_char_counter);
}
//int main(void)
//{
//    int ret = 0;
//    int ret_mine = 0;
//    char str[5] = "hell";
//
//
//    /* UNTESTED */
//
//    printf("\n-----\n");
//
//    printf("\n");
//    ret = printf("%.2c", NULL);
//    printf("\n");
//    ret_mine = ft_printf("%.2c", NULL);
//    printf("\n\n");
//    printf("Or_ret->|%i|", ret);
//    printf("\n");
//    printf("My_ret->|%i|", ret_mine);
//    printf("\n");
//
//    printf("\n-----\n");
//
//}



