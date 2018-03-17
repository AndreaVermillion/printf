#include "printf.h"

void    ft_count_printed_characters(t_data *a)
{
    // What to print? //  // by default it is 1 = numbers || 2 == string of characters  || 3 = string of characters in unicode || 4 = just one character || 5 = just one character in unicode || 6 = pointer

    // 3 (char) and 5 (pointer) is directly printed when the width is applied;

    if (a->wtp == 1 || a->wtp == 2 ||  a->wtp == 6)
        ft_putstr(a->arg_str_conv);

    a->printed_char_counter = a->printed_char_counter + a->arg_len;
}

void    ft_print_percent_with_wrong_type_without_flag(t_data *a, int i)
{
    while (i < a->wid_int)
    {
        ft_putchar(' ');
        i++;
        a->printed_char_counter++;
    }
    ft_putchar(a->wrong_type);
    a->printed_char_counter++;
}

void    ft_print_percent_with_wrong_type_with_flag(char *temp, t_data *a, int i)
{
    if (ft_strchr(temp, '-'))
    {
        ft_putchar(a->wrong_type);
        a->printed_char_counter++;
        while (i < a->wid_int)
        {
            ft_putchar(' ');
            i++;
            a->printed_char_counter++;
        }
    }
    else
        ft_print_percent_with_wrong_type_without_flag(a, i);

}

char    *ft_print_percent_to_wrong_type(char *s, t_data *a, char c)
{
    char *temp;
    int nb;
    int i;

    nb = 0;
    i = 1;
    if (c == '%')
        a->wrong_type = '%';
    temp = ft_strdup(s);
    ft_set_everything_to_zero(a);
    ft_find_format(temp, a->wrong_type, a);
    ft_find_all_fields(a, a->wrong_type);
    ft_verify_all_fields(a, a->wrong_type);
    if (a->fla_len)
        ft_print_percent_with_wrong_type_with_flag(temp,a, i);
    else
        ft_print_percent_with_wrong_type_without_flag(a, i);
    while (temp[nb]  == '+' || temp[nb] == '-' || temp[nb] == ' ' ||
            temp[nb] == '#' || temp[nb] == '.'||
           (temp[nb] >= '0' && temp[nb] <= '9'))
        nb++;
    while (nb-- >= 0)
        s++;
    return (s);
}

char    *ft_print_percent_with_percent(char *s, t_data *a)
{
    char *temp_percent;
    int nb_of_percent;
    int i;

    nb_of_percent = 0;
    temp_percent = ft_strdup(s);
    while (temp_percent[nb_of_percent] == '%')
        nb_of_percent++;
    i = nb_of_percent / 2;
    while (i-- > 0)
    {
        ft_putchar('%');
        a->printed_char_counter++;
    }
    if (nb_of_percent % 2 == 0)
        i = 0;
    else
        i = 1;
    while (nb_of_percent > i)
    {
        nb_of_percent--;
        s++;
    }
    return (s);
}

void ft_print_no_format_characters(t_data *a, char **temp)
{
    a->printed_char_counter++;
    ft_putchar(**temp);
    (*temp)++;
}