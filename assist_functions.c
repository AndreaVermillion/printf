#include "printf.h"

char    *ft_cpy_to_nb(char *dst, const char *src, size_t start, int n)
{
    size_t	i;

    i = 0;
    while (start < (size_t)n && src[i] != 0)
    {
        dst[start] = src[i];
        i++;
        start++;
    }
    return (dst);
}

void    ft_find_diff_arg_len_vs_wid_vs_pre(t_data *a)
{
    if (a->arg_len >= a->wid_int)
        a->wid_gap = 0;
    if (a->arg_len < a->wid_int)
        a->wid_gap = a->arg_len;
}

int     ft_len_to_char(char *s, char c)
{
    int i;

    i = 0;
    while(s[i] != c)
        i++;
    return (i);
}

int     ft_find_format(char *s, char c, t_data *a)
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
    // free(sub);
    return(0);
}

char    *ft_cpy_to_char(char *s, char c)
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


int    ft_find_arg_len_string_unicode(t_data *a)
{
    int total_byte_size;
    int i;

    i = 0;
    total_byte_size = 0;
    while (a->arg_uni_str_conv[i])
    {
        if (a->arg_uni_str_conv[i] <= 127)
            total_byte_size = total_byte_size + 1;

        else if (a->arg_uni_str_conv[i] >= 128 && a->arg_uni_str_conv[i] <= 2047)
            total_byte_size = total_byte_size + 2;

        else if (a->arg_uni_str_conv[i] >= 2048 && a->arg_uni_str_conv[i] <= 65335)
            total_byte_size = total_byte_size + 3;

        else if (a->arg_uni_str_conv[i] >= 65536 && a->arg_uni_str_conv[i]<= 1114111)
            total_byte_size = total_byte_size + 4;
        i++;
    }
    return (total_byte_size);
}

int    ft_find_arg_len_char_unicode(t_data *a)
{
    if (a->arg_uni_char_conv <= 127)
        return(1);
    else if (a->arg_uni_char_conv >= 128 && a->arg_uni_char_conv <= 2047)
        return(2);
    else if (a->arg_uni_char_conv >= 2048 && a->arg_uni_char_conv <= 65335)
        return(3);
    else if (a->arg_uni_char_conv>= 65536 && a->arg_uni_char_conv<= 1114111)
        return(4);
    return(0);
}