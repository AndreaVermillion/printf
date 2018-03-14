#include "printf.h"


int	    ft_find_percent_glued_percent(char *s) //c C d D i o O u U x X e E f F g G a A n p s S
{
    size_t len;

    len = ft_strlen(s);
    if ((len > 1) && (*(s + 1) == '%'))
        return (1);
    return(0);
}

int	    ft_find_percent_to_wrong_type(char *s) //c C d D i o O u U x X e E f F g G a A n p s S h l j z t L I w
{
    size_t len;
    size_t	i;

    i = 1;
    len = ft_strlen(s);

    while (*(s + i) == '+' || *(s + i) == '-' || *(s + i) == ' ' || *(s + i) == '.' ||
            *(s + i) == '0' || *(s + i) == '#' || ((*(s + i)) >= '1' && *(s + i) <= '9'))
        i++;

    if (i + 1 <= len)
    {
        if (*(s + i) == 'c' || *(s + i) == 'C' || *(s + i) == 'd' || *(s + i) == 'D' ||
                *(s + i) == 'i' || *(s + i) == 'o' || *(s + i) == 'O' ||
                *(s + i) == 'u' || *(s + i) == 'x' || *(s + i) == 'X' ||
                *(s + i) == 'f' || *(s + i) == 'F' || *(s + i) == 'g' ||
                *(s + i) == 'a' || *(s + i) == 'A' || *(s + i) == 'n' ||
                *(s + i) == 's' || *(s + i) == 'S' || *(s + i) == 'e' || *(s + i) == 'E' ||
                *(s + i) == 'h' || *(s + i) == 'l' || *(s + i) == 'j' || *(s + i) == 'z' ||
                *(s + i) == 't' || *(s + i) == 'L' || *(s + i) == 'I' || *(s + i) == 'w')
            return(0);
    }
    return(1);
}

int	    ft_find_percent_to_percent(char *s)
{
    size_t len;
    size_t	i;

    i = 1;
    len = ft_strlen(s);

    while ((*(s + i) == '+' || *(s + i) == '-' || *(s + i) == ' ' ||
            *(s + i) == '0' || *(s + i) == '#' ) && (i + 1 < len))
    {
        if (*(s + i + 1) == '%')
            return (1);
        i++;
    }
    return(0);
}

int	    ft_find_percent_is_alone(char *s)
{
    size_t len;
    size_t	i;

    i = 0;
    len = ft_strlen(s) + 1;
    while (i < len)
    {
        if (*(s + i + 1) != '+' && *(s + i + 1) != '-' && *(s + i + 1) != ' ' &&
            *(s + i + 1) != '0' && *(s + i + 1) != '#' && *(s + i + 1) != 'D' &&
            *(s + i + 1) != 'i' && *(s + i + 1) != 'o' && *(s + i + 1) != 'O' &&
            *(s + i + 1) != 'u' && *(s + i + 1) != 'x' && *(s + i + 1) != 'X' &&
            *(s + i + 1) != 'e' && *(s + i + 1) != 'E' && *(s + i + 1) != 'f' &&
            *(s + i + 1) != 'F' && *(s + i + 1) != 'g' && *(s + i + 1) != 'a' &&
            *(s + i + 1) != 'A' && *(s + i + 1) != 'n' && *(s + i + 1) != 's' &&
            *(s + i + 1) != 'S')
            return (1);
        i++;
    }
    return(0);
}