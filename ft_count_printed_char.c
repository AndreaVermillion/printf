#include "printf.h"

void ft_count_printed_characters(t_data *a)
{
   // What to print? //  // by default it is 1 = numbers || 2 == string of characters  || 3 = string of characters in unicode || 4 = just one character || 5 = just one character in unicode || 6 = pointer

    // 3 (char) and 5 (pointer) is directly printed when the width is applied;

    if (a->wtp == 1 || a->wtp == 2 || a->wtp == 6)
        ft_putstr(a->arg_str_conv);

    a->printed_char_counter = a->printed_char_counter + a->arg_len;
}
