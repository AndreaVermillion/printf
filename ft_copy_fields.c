#include "printf.h"

int    ft_len_to_char(char *s, char c)
{
    int i;

    i = 0;
    while(s[i] != c)
        i++;
    return (i);
}

int	ft_find_format(char *s, char c, t_data *a)
{
    int i;
    int len;
    char	*sub;

    i = 0;
    len = ft_len_to_char(s,c) + 1;
    if (s == NULL)
        return (0);
    if (!(sub = (char*)malloc(len + 1)))
        return (0);
    while (i < len)
    {
        sub[i] = s[i];
        i++;
    }
    sub[i] = '\0';
    a->f_s = sub;
    return(0);
}

char	*ft_cpy_to_char(char *s, char c)
{
    int i;
    int len;
    char	*sub;

    i = 0;
    len = ft_len_to_char(s,c);
    if (s == NULL)
        return (NULL);
    if (!(sub = (char*)malloc(len + 1)))
        return (NULL);
    while (i < len)
    {
        sub[i] = s[i];
        i++;
    }
    sub[i] = '\0';
    return (sub);
}
