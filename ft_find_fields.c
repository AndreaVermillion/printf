#include "printf.h"

void ft_find_group(char spe, t_data *a)
{
    if (spe == 's' || spe == 'S' || spe == 'c' || spe == 'C' || spe == 'p')                 /* for group 1 ===> // s_S_c_C_p */
        a->grp = 1;
    if (spe == 'o' || spe == 'O' || spe == 'x' || spe == 'X' || spe == 'u' || spe == 'U')   /* for group 2 ===> // o_O_x_X_u_U */
        a->grp = 2;
    if (spe == 'd' || spe == 'D' || spe  == 'i')                                            /* for group 3 ===> // d_D_i */
        a->grp = 3;
}

char	*ft_find_spe(char *s)
{
    size_t	len;
    size_t	i;

    i = 0;
    len = ft_strlen(s) + 1;
    while (i < len)
    {
        if (*(s + i) == 's' || *(s + i) == 'S' || *(s + i) == 'd'
            || *(s + i) == 'D' || *(s + i) == 'i' || *(s + i) == 'o'
            || *(s + i) == 'O' || *(s + i) == 'u' || *(s + i) == 'U'
            || *(s + i) == 'x' || *(s + i) == 'X' || *(s + i) == 'c'
            || *(s + i) == 'C' || *(s + i) == 'p' )
            return (s + i);
        i++;
    }
    return (NULL);
}

char	*ft_find_fla(t_data *a)
{
    size_t	len;
    size_t	i;

    i = 0;
    len = ft_strlen(a->f_s) + 1;
    while (i < len)
    {
        if ((*(a->f_s + i) == a->spe) || ((*(a->f_s + i) >= '1') &&
            (*(a->f_s + i) <= '9')) || (*(a->f_s + i) == '.') ||
            (*(a->f_s + i) == 'h') || (*(a->f_s + i) == 'l') || (*(a->f_s + i) == 'j')
            || (*(a->f_s + i) == 'z'))
            return (a->f_s + i);
        i++;
    }
    return (NULL);
}

char	*ft_find_wid(t_data *a)
{
    size_t	len;
    size_t	i;

    i = 0;
    len = ft_strlen(a->f_r) + 1;
    while (i < len)
    {
        if ((*(a->f_r + i) == a->spe) || (*(a->f_r + i) == '.') ||
            (*(a->f_r + i) == 'h') || (*(a->f_r + i) == 'l') ||
            (*(a->f_r + i) == 'j') || (*(a->f_r + i) == 'z'))
            return (a->f_r + i);
        i++;
    }
    return (NULL);
}

char	*ft_find_pre(t_data *a)
{
    size_t	len;
    size_t	i;

    i = 0;
    len = ft_strlen(a->f_r) + 1;
    while (i < len)
    {
        if ((*(a->f_r + i) == a->spe) || (*(a->f_r + i) == 'h') ||
            (*(a->f_r + i) == 'l') || (*(a->f_r + i) == 'j') ||
            (*(a->f_r + i) == 'z'))
            return (a->f_r + i);
        i++;
    }
    return (NULL);
}

char	*ft_find_len(t_data *a)
{
    size_t	len;
    size_t	i;

    i = 0;
    len = ft_strlen(a->f_r) + 1;
    while (i < len)
    {
        if (*(a->f_r + i) == a->spe)
            return (a->f_r + i);
        i++;
    }
    return (NULL);
}