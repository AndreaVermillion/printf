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
    free(sub);
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

void    ft_find_arg_len(t_data *a)
{
    size_t i;
    char *temp;

    i = 0;
    if (a->grp == 1)
    {
        if ((a->spe == 'p') || (a->spe == 's' && a->arg_str_conv != NULL))
            a->arg_len = ft_strlen(a->arg_str_conv);

        else if ((a->spe == 's') && (a->arg_str_conv == NULL))
        {
            temp = ft_strdup("(null)");
            a->arg_str_conv = temp;
            a->arg_len = ft_strlen(temp);
            free(temp);
        }
        else if ((a->spe == 'c' || a->spe == 'C') && (a->arg_char_conv != 0))
            a->arg_len = 1;

        else if ((a->spe == 'c' || a->spe == 'C') && (a->arg_char_conv == 0))
            a->arg_len = 0;

        else if (a->spe == 'S')
        {
            while (a->arg_uni_str_conv[i])
                i++;
            a->arg_len = i;
        }
    }
    else
        a->arg_len = ft_strlen(a->arg_str_conv);
}