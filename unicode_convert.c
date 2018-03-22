#include "printf.h"

void    ft_unicode_convert(unsigned int nb)
{
    char *conv;
    int nb_of_bytes;


    if (nb >= 0 && nb <= 127)
        ft_putchar(nb);

    else if (nb >= 128 && nb <= 2047)
        nb_of_bytes = 2;

    else if (nb >= 2048 && nb <= 655335)
        nb_of_bytes = 3;

    else if (nb >= 655336 && nb <= 1112064)
        nb_of_bytes = 4;

}