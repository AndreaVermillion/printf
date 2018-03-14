#include "printf.h"

void ft_verify_fla_group3_array_part2(char** checker, char *array, t_data *a)
{
    char *res;
    int d;
    int i;
    int j;

    d = 0;
    j = 0;
    while (d <= 14)
    {
        i = 0;
        while (array[i] == checker[d][i])
            i++;
        if (i == 4)
            break;
        d++;
    }
    i = 4;
    res =  ft_strnew(3);
    while (checker[d][i] != '\0')
        res[j++] = checker[d][i++];
    a->fla = res;
}

void ft_verify_fla_group3_array_part1(char *array, t_data *a)
{
    char **checker;
    int n;

    checker = (char **) malloc(sizeof(char *) * 16);
    checker[15] = NULL;
    n = -1;
    while (++n < 15)
        checker[n] = ft_strnew(8);
    checker[0] = ft_strcpy(checker[0], "1111+-");
    checker[1] = ft_strcpy(checker[1], "1101+-");
    checker[2] = ft_strcpy(checker[2], "1110+-");
    checker[3] = ft_strcpy(checker[3], "1100+-");
    checker[4] = ft_strcpy(checker[4], "0111+0");
    checker[5] = ft_strcpy(checker[5], "1011 -");
    checker[6] = ft_strcpy(checker[6], "0110+0");
    checker[7] = ft_strcpy(checker[7], "1010-");
    checker[8] = ft_strcpy(checker[8], "0011 0");
    checker[9] = ft_strcpy(checker[9], "0101+");
    checker[10] = ft_strcpy(checker[10], "1001 -");
    checker[11] = ft_strcpy(checker[11], "1000-");
    checker[12] = ft_strcpy(checker[12], "0100+");
    checker[13] = ft_strcpy(checker[13], "00100");
    checker[14] = ft_strcpy(checker[14], "0001 ");

    ft_verify_fla_group3_array_part2(checker, array, a);
}

int ft_verify_fla_group3(t_data *a) // group3 : d_D_i
{
    char *temp;
    char *array;
    int i;

    temp = a->fla;
    if  (ft_strchr(temp, '#'))
        return (0);
    i = 0;
    array = ft_strnew(4);
    ft_memset(array, '0', 4);
    while(temp[i])
    {
        if (temp[i] == '-')
            array[0] = '1';
        if (temp[i] == '+')
            array[1] = '1';
        if (temp[i] == '0')
            array[2] = '1';
        if (temp[i] == ' ')
            array[3] = '1';
        i++;
    }
    ft_verify_fla_group3_array_part1(array, a);
    return (1);
}

void ft_verify_fla_group2_array_part2(char** checker, char *array, t_data *a)
{
    char *res;
    int d;
    int i;
    int j;

    d = 0;
    j = 0;
    while (d <= 6)
    {
        i = 0;
        while (array[i] == checker[d][i])
            i++;
        if (i == 3)
            break;
        d++;
    }
    i = 3;
    res =  ft_strnew(2);
    while (checker[d][i] != '\0')
        res[j++] = checker[d][i++];
    a->fla = res;
}

void ft_verify_fla_group2_array_part1(char *array, t_data *a)
{
    char **checker;
    int n;

    checker = (char **) malloc(sizeof(char *) * 7);
    checker[7] = NULL;
    n = -1;
    while (++n < 7)
        checker[n] = ft_strnew(6);
    checker[0] = ft_strcpy(checker[0], "111-#");
    checker[1] = ft_strcpy(checker[1], "110-#");
    checker[2] = ft_strcpy(checker[2], "0110#");
    checker[3] = ft_strcpy(checker[3], "010#");
    checker[4] = ft_strcpy(checker[4], "100-");
    checker[5] = ft_strcpy(checker[5], "101-");
    checker[6] = ft_strcpy(checker[6], "0010");

    ft_verify_fla_group2_array_part2(checker, array, a);
}

int ft_verify_fla_group2(t_data *a, char c) // group2 : 'o_O_x_X_u_U'
{
    char *temp;
    char *array;
    int i;

    temp = a->fla;
    if ((ft_strchr(temp, '+') || ft_strchr(temp,' ')) ||
        ((c == 'u' || c == 'U') && ft_strchr(temp, '#')))
        return (0);
    i = 0;
    array = ft_strnew(3);
    ft_memset(array, '0', 3);
    while(temp[i])
    {
        if (temp[i] == '-')
            array[0] = '1';
        if (temp[i] == '#')
            array[1] = '1';
        if (temp[i] == '0')
            array[2] = '1';
        i++;
    }
    ft_verify_fla_group2_array_part1(array, a);
    return (1);
}

int ft_verify_fla_group1(t_data *a)         // group1 : 's_S_c_C_p'
{
    char *temp;
    size_t i;

    temp = a->fla;
    i = 0;
    while (temp[i] == '-')
        i++;
    if (ft_strlen(temp) == i)
    {
        a->fla = ft_strdup("-");
        return (1);
    }
    return (0);
}

int ft_verify_all_fla(t_data *a, char spe) // Step2
{
    char * temp;
    temp = a->fla;

    if (temp == NULL) // Step 1. Empty string - so no flags //
        return (1);
    if (((a->grp == 1) && !ft_verify_fla_group1(a)) ||
        (a->grp == 2 && !ft_verify_fla_group2(a, spe)) ||
        (a->grp == 3 && !ft_verify_fla_group3(a)))
        return (0);
    a->fla_len = ft_strlen(a->fla);
    return (1);
}

int ft_verify_all_wid(t_data *a)
{
    char * temp;
    int i;

    temp = a->wid_raw;
    i = 0;
    if (temp == NULL)           // Step 1. Empty string - so no width //
        return (1);
    while (temp[i])               // Step 2. Checking it is only digits
    {
        if (!ft_isdigit(temp[i]))
            return (0);
        i++;
    }
    a->wid_int = ft_atoi(a->wid_raw);
    return (1);
}

int ft_verify_all_pre(t_data *a)
{
    char * temp;
    int len;
    int i;

    temp = a->pre_raw;
    i = 1;
    if (temp == NULL)
    {
        a->pre_int = 0;
        return (1);
    }
    len = ft_strlen(temp);
    if ((len == 1 && temp[0] == '.') || (len == 2 && (temp[0] == '.' && temp[1] == '0')))         // Step 1. Empty string - so no pre  OR there is only "."//
    {
        a->pre_int = 1;
        return (1);
    }
    while (temp[i])                                // Step 2. Checking it is only digits
    {
        if (!ft_isdigit(temp[i]))
            return (0);
        i++;
    }
    a->pre_raw = ft_cpy_to_char(temp + 1,temp[i]);
    a->pre_int = ft_atoi(a->pre_raw);
    return (1);
}

int ft_verify_all_len(t_data *a, char c)
{
    char * temp;
    int len;

    temp = a->len;
    if (temp == NULL)                       // Step 1. Empty string means there is no lengths //
        return (1);
    len = ft_strlen(temp);
    if (len > 2)                            // Step 2. There cannot be more than 2 letters //
        return (0);                         // Step 3. Check content in pre //
    if ((len == 2) && !((temp[0] == 'h' || temp[1] == 'h') || (temp[0] == 'l' || temp[1] == 'l')))
        return (0);
    if ((len == 1) && !(temp[0] == 'h' || temp[0] == 'l' || temp[0] == 'j' || temp[0] == 'z'))
        return (0);
    if (c == 'S' || c == 'C') // Step 4. Check each spe //
        return (0);
    if ((c == 's' || c == 'c') && (len == 2))
        return (0);
    if ((c == 's' || c == 'c') && (temp[0] == 'h' || temp[0] == 'j' || temp[0] == 'z'))
        return (0);
    return (1);
}

int ft_verify_all_fields(t_data *a, char c) // Step1
{
    if (!(ft_verify_all_fla(a, c)) ||
        !(ft_verify_all_wid(a)) ||
        !(ft_verify_all_pre(a)) ||
        !(ft_verify_all_len(a, c)))
    {
        ft_putstr("UNDEF");
        return (0);
    }
    return(1);
}
