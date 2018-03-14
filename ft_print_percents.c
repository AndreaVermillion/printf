#include "printf.h"


char  *ft_print_percent_to_percent(char *s, t_data *a)
{
    char *temp_spaces;
    int nb_of_spaces;

    nb_of_spaces = 1;
    temp_spaces = ft_strdup(s);
    while (temp_spaces[nb_of_spaces])
    {
        if (temp_spaces[nb_of_spaces] == '+' ||
            temp_spaces[nb_of_spaces] == '-' ||
            temp_spaces[nb_of_spaces] == ' ' ||
            temp_spaces[nb_of_spaces] == '#' ||
            temp_spaces[nb_of_spaces] == '0')
            nb_of_spaces++;
        else
            break ;
    }
    while (nb_of_spaces >= 0)
    {
        nb_of_spaces--;
        s++;
    }
    ft_putchar('%');
    a->printed_char_counter++;
    return (s);
}

char  *ft_print_percent_to_wrong_type(char *s)
{
    char *temp_spaces;
    int nb_of_spaces;

    nb_of_spaces = 1;
    temp_spaces = ft_strdup(s);
    while (temp_spaces[nb_of_spaces])
    {
        if (temp_spaces[nb_of_spaces] == '+' ||
            temp_spaces[nb_of_spaces] == '-' ||
            temp_spaces[nb_of_spaces] == ' ' ||
            temp_spaces[nb_of_spaces] == '#' ||
            temp_spaces[nb_of_spaces] == '0')
            nb_of_spaces++;
        else
            break ;
    }
    while (nb_of_spaces > 0)
    {
        nb_of_spaces--;
        s++;
    }
    return (s);
}


char  *ft_print_percent_glued_percent(char *s, t_data *a)
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



//char  *ft_remove_flags(char *s)
//{
//    char *temp_spaces;
//    int nb_of_spaces;
//
//    nb_of_spaces = 1;
//    temp_spaces = ft_strdup(s);
//    while (temp_spaces[nb_of_spaces])
//    {
//        if (temp_spaces[nb_of_spaces] == '+' ||
//            temp_spaces[nb_of_spaces] == '-' ||
//            temp_spaces[nb_of_spaces] == ' ' ||
//            temp_spaces[nb_of_spaces] == '#' ||
//            temp_spaces[nb_of_spaces] == '0')
//            nb_of_spaces++;
//        else
//            break ;
//    }
//    while (nb_of_spaces > 0)
//    {
//        nb_of_spaces--;
//        s++;
//    }
//    return (s);
//}
