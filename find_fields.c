#include "printf.h"

void    ft_find_group(t_data *a)
{
    if (a->spe == 's' || a->spe == 'S' || a->spe == 'c' || a->spe == 'C' || a->spe == 'p')                 /* for group 1 ===> // s_S_c_C_p */
        a->grp = 1;
    else if (a->spe == 'o' || a->spe == 'O' || a->spe == 'x' || a->spe == 'X' || a->spe == 'u' || a->spe == 'U')   /* for group 2 ===> // o_O_x_X_u_U */
        a->grp = 2;
    else if (a->spe == 'd' || a->spe == 'D' || a->spe  == 'i')                                            /* for group 3 ===> // d_D_i */
        a->grp = 3;
}

char	*ft_find_spe(char *s, t_data *a)
{
    size_t	len;
    size_t	i;

    i = 0;
    a->spe = '0'; //char
    len = ft_strlen(s);
    while (i < len)
    {
        if ((*(s + i) >= 'a' && *(s + i)  <= 'z') || (*(s + i) >= 'A' && *(s + i)  <= 'Z'))
        {
            if (((*(s + i) == 'h') || (*(s + i) == 'l') || (*(s + i) == 'j') || (*(s + i) == 'z')) && (i + 1 < len))
            {
                i++;
                if (*(s + i) == 's' || *(s + i) == 'S' || *(s + i) == 'd' || *(s + i) == 'D' || *(s + i) == 'i' || *(s + i) == 'o'
                    || *(s + i) == 'O' || *(s + i) == 'u' || *(s + i) == 'U' || *(s + i) == 'x' || *(s + i) == 'X' || *(s + i) == 'c'
                    || *(s + i) == 'C' || *(s + i) == 'p')
                {
                    a->spe = *(s + i);
                    return(s + i);
                }
                else if (((*(s + i) == 'h') || (*(s + i) == 'l')) && (i + 1 < len))
                {
                    i++;
                    if (*(s + i) == 's' || *(s + i) == 'S' || *(s + i) == 'd' || *(s + i) == 'D' || *(s + i) == 'i' || *(s + i) == 'o'
                        || *(s + i) == 'O' || *(s + i) == 'u' || *(s + i) == 'U' || *(s + i) == 'x' || *(s + i) == 'X' || *(s + i) == 'c'
                        || *(s + i) == 'C' || *(s + i) == 'p')
                    {
                        a->spe = *(s + i);
                        return(s + i);
                    }
                }
                else
                {
                    a->wrong_type = *(s + i);
                    break;
                }
            }
            else if (*(s + i) == 's' || *(s + i) == 'S' || *(s + i) == 'd'
                     || *(s + i) == 'D' || *(s + i) == 'i' || *(s + i) == 'o'
                     || *(s + i) == 'O' || *(s + i) == 'u' || *(s + i) == 'U'
                     || *(s + i) == 'x' || *(s + i) == 'X' || *(s + i) == 'c'
                     || *(s + i) == 'C' || *(s + i) == 'p')
            {
                a->spe = *(s + i);
                return(s + i);
            }
            else
            {
                a->wrong_type = *(s + i);
                break;
            }
        }
        i++;
    }
    return (NULL);
}

char	*ft_find_fla(t_data *a, char c)
{
    size_t	len;
    size_t	i;

    i = 0;
    len = ft_strlen(a->f_s) + 1;
    while (i < len)
    {
        if ((*(a->f_s + i) == c) || ((*(a->f_s + i) >= '1') &&
            (*(a->f_s + i) <= '9')) || (*(a->f_s + i) == '.') ||
            (*(a->f_s + i) == 'h') || (*(a->f_s + i) == 'l') || (*(a->f_s + i) == 'j')
            || (*(a->f_s + i) == 'z'))
            return (a->f_s + i);
        i++;
    }
    return (NULL);
}

char	*ft_find_wid(t_data *a, char c)
{
    size_t	len;
    size_t	i;

    i = 0;
    len = ft_strlen(a->f_r) + 1;
    while (i < len)
    {
        if ((*(a->f_r + i) == c) || (*(a->f_r + i) == '.') ||
            (*(a->f_r + i) == 'h') || (*(a->f_r + i) == 'l') ||
            (*(a->f_r + i) == 'j') || (*(a->f_r + i) == 'z'))
            return (a->f_r + i);
        i++;
    }
    return (NULL);
}

char	*ft_find_pre(t_data *a, char c)
{
    size_t	len;
    size_t	i;

    i = 0;
    len = ft_strlen(a->f_r) + 1;
    while (i < len)
    {
        if ((*(a->f_r + i) == c) || (*(a->f_r + i) == 'h') ||
            (*(a->f_r + i) == 'l') || (*(a->f_r + i) == 'j') ||
            (*(a->f_r + i) == 'z'))
            return (a->f_r + i);
        i++;
    }
    return (NULL);
}

char	*ft_find_len(t_data *a, char c)
{
    size_t	len;
    size_t	i;

    i = 0;
    len = ft_strlen(a->f_r) + 1;
    while (i < len)
    {
        if (*(a->f_r + i) == c)
            return (a->f_r + i);
        i++;
    }
    return (NULL);
}

int	    ft_find_percent_with_percent(char *s)
{
    size_t len;

    len = ft_strlen(s);
    if ((len > 1) && (*(s + 1) == '%'))
        return (1);
    return(0);
}

int	    ft_find_percent_to_percent(char *s)
{
    size_t len;
    size_t	i;

    i = 1;
    len = ft_strlen(s);

    while ((*(s + i) == '+' || *(s + i) == '-' || *(s + i) == ' ' || *(s + i) == '.' ||
            *(s + i) == '0' || *(s + i) == '#' || (*(s + i) > '0' && (*(s + i) <= '9'))) && (i + 1 < len))
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