#include "printf.h"

void    ft_unicode_convert(unsigned int nb)
{
    unsigned int mask1 = 49280;
    unsigned int mask2= 14712960;
    unsigned int mask3= 4034953344;
    unsigned char octet;


    if (nb <= 127)
        ft_putchar(nb);

    else if (nb >= 128 && nb <= 2047)
    {
        unsigned char o2 = (nb << 26) >> 26; // Восстановление первых 6 бит 110xxxxx 10(xxxxxx)
        unsigned char o1 = ((nb >> 6) << 27) >> 27; // Восстановление последних 5 бит 110(xxxxx) 10xxxxxx

        octet = ( mask1 >> 8 ) | o1 ; // Apply the first bitmask to the first byte
        write(1, &octet, 1);
        octet = ( ( mask1 << 24 ) >> 24 ) | o2 ; // Apply the second bitmask to the second byte
        write(1, &octet, 1);
    }

    else if (nb >= 2048 && nb <= 65535)
    {
        unsigned char o3 = (nb << 26) >> 26; // Восстановление первых 6 бит 1110xxxx 10xxxxxx 10(xxxxxx)
        unsigned char o2 = ((nb >> 6) << 26) >> 26; // Восстановление вторых 6 бит 1110xxxx 10(xxxxxx) 10xxxxxx
        unsigned char o1 = ((nb >> 12) << 28) >> 28; // Восстановление последних 4 бит 1110(xxxx) 10xxxxxx 10xxxxxx

        octet = ( mask2 >> 16 ) | o1 ; // Apply the first bitmask to the first byte
        write(1, &octet, 1);
        octet = ( ( mask2 << 16 ) >> 24 ) | o2 ; // Apply the second bitmask to the second byte
        write(1, &octet, 1);
        octet = ( ( mask2 << 24 ) >> 24 ) | o3 ; // Apply the third bit mask to the third byte
        write(1, &octet, 1);
    }

    else if (nb >= 65536 && nb <= 1114111)
    {
        unsigned char o4 = (nb << 26) >> 26; // Восстановление первых 6 11110xxx 10xxxxxx 10xxxxxx 10(xxxxxx)
        unsigned char o3 = ((nb >> 6) << 26) >> 26; // Восстановление вторых 6 бит 11110xxx 10xxxxxx 10(xxxxxx) 10xxxxxx
        unsigned char o2 = ((nb >> 12) << 26) >> 26;  // Восстановление третьих 6 бит bits 11110xxx 10(xxxxxx) 10xxxxxx 10xxxxxx
        unsigned char o1 = ((nb >> 18) << 29) >> 29; // Восстановление последних 3 бита 11110(xxx) 10xxxxxx 10xxxxxx 10xxxxxx

        octet = ( mask3 >> 24 ) | o1 ; // Apply the first byte bits to the first byte of the mask
        write(1, &octet, 1);
        octet = ( ( mask3 << 8 ) >> 24 ) | o2 ; // Apply the second bitmask to the second byte
        write(1, &octet, 1);
        octet = ( ( mask3 << 16 ) >> 24 ) | o3 ; // Apply the third bit mask to the third byte
        write(1, &octet, 1);
        octet = ( ( mask3 << 24 ) >> 24 ) | o4 ; // Apply the last bitmask to the last byte
        write(1, &octet, 1);
    }
}