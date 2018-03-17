#include "printf.h"

static int		ft_result(size_t result, int negative, int count)
{
    if (result > 9223372036854775807 && negative == 1)
        return (0);
    if (result > 9223372036854775807 && negative == 0)
        return (-1);
    if (negative == 1 && count > 19)
        return (0);
    if (negative == 1 && count <= 19)
        return (-(int)result);
    if (negative == 0 && count > 19)
        return (-1);
    else
        return ((int)result);
}

int     ft_atoi(const char *str)
{
    int		negative;
    size_t	result;
    int		i;
    int		count;

    negative = 0;
    result = 0;
    i = 0;
    count = 0;
    while ((str[i] == ' ') || (str[i] == '\t') || (str[i] == '\v') ||
           (str[i] == '\n') || (str[i] == '\r') || (str[i] == '\f') ||
           (str[i] == '0'))
        i++;
    if (str[i] == '-')
        negative = 1;
    if (str[i] == '+' || str[i] == '-')
        i++;
    while (str[i] == '0')
        i++;
    while (str[i] >= '0' && str[i] <= '9')
    {
        result = (result * 10) + str[i++] - '0';
        count++;
    }
    return (ft_result(result, negative, count));
}

int		ft_isdigit(int a)
{
    if (a >= '0' && a <= '9')
        return (1);
    return (0);
}

void	*ft_memset(void *dst, int c, size_t n)
{
    size_t	counter;
    char	*str;

    str = (char *)dst;
    if (n == 0)
        return (str);
    counter = 0;
    while (counter < n)
    {
        str[counter] = (char)c;
        counter++;
    }
    return (dst);
}

void	ft_putchar(char c)
{
    write(1, &c, 1);
}

void	ft_putstr(char const *s)
{
    char	*str;
    int		i;

    if (s == NULL)
        return ;
    i = 0;
    str = (char*)s;
    while (str[i] != '\0')
    {
        ft_putchar(str[i]);
        i++;
    }
}

char	*ft_strchr(const char *s, int c)
{
    size_t	len;
    size_t	i;

    i = 0;
    len = ft_strlen(s) + 1;
    while (i < len)
    {
        if (*(s + i) == (char)c)
            return ((char *)s + i);
        i++;
    }
    return (NULL);
}

int		ft_strcmp(const char *dst, const char *src)
{
    int				diff;
    int				i;
    unsigned char	*d;
    unsigned char	*s;

    diff = 0;
    i = 0;
    d = (unsigned char*)dst;
    s = (unsigned char*)src;
    while (d[i] || s[i])
    {
        diff = d[i] - s[i];
        if (diff != 0)
            return (diff);
        i++;
    }
    return (d[i] - s[i]);
}

char	*ft_strcpy(char *dst, const char *src)
{
    int	i;

    i = 0;
    while (src[i] != '\0')
    {
        dst[i] = src[i];
        i++;
    }
    dst[i] = '\0';
    return (dst);
}

char	*ft_strdup(const char *s1)
{
    unsigned	i;
    size_t		len;
    char		*s2;

    len = ft_strlen(s1);
    if (!(s2 = (char*)malloc(sizeof(*s2) * len + 1)))
        return (NULL);
    i = 0;
    while (i < len)
    {
        s2[i] = s1[i];
        i++;
    }
    s2[i] = '\0';
    return (s2);
}

size_t		ft_strlen(const char *str)
{
    size_t i;

    i = 0;
    while (str[i])
        i++;
    return (i);
}

char	*ft_strncpy(char *dst, const char *src, size_t n)
{
    size_t	i;

    i = 0;
    while (i < n && src[i] != 0)
    {
        dst[i] = src[i];
        i++;
    }
    while (i < n)
        dst[i++] = 0;
    return (dst);
}

char	*ft_strnew(size_t size)
{
    char	*s;
    size_t	i;

    i = 0;
    if (!(s = (char*)(malloc(size + 1))))
        return (NULL);
    while (i < size)
    {
        s[i] = 0;
        i++;
    }
    s[i] = '\0';
    return (s);
}

static char	*ft_convert_unsigned(unsigned long long int n, int base, char *str, int i)
{
    unsigned long long int	d;
    char			temp;

    d = 1;
    while (n / d >= (unsigned long long int)base)
        d *= base;
    while (d > 0)
    {
        temp = '0' + n / d;
        if (temp > '9')
            str[i] = (temp + 39);
        else
            str[i] = temp;
        n %= d;
        d /= base;
        i++;
    }
    return (str);
}

char		*ft_itoa_base_unsigned(unsigned long long int n, int base)
{
    char	*str;
    int		i;

    str = (char *)malloc(sizeof(*str) * 21);
    i = 0;
    while (i < 21)
    {
        str[i] = '\0';
        i++;
    }
    i = 0;
    return (ft_convert_unsigned(n, base, str, i));
}

static char	*ft_convert_signed(signed long long int n, unsigned int base, char *str, int i)
{
    signed long long int	d;
    unsigned long long int num;
    char			temp;

    d = 1;
    num = n;
    if (n < 0)
    {
        num = n * (-1);
        str[i] = '-';
        i++;
    }
    while (num / d >= base)
        d *= base;
    while (d > 0)
    {
        temp = '0' + num / d;
        if (temp > '9')
            str[i] = (temp + 39);
        else
            str[i] = temp;
        num %= d;
        d /= base;
        i++;
    }
    return (str);
}

char		*ft_itoa_base_signed(signed long long int n, int base)
{
    char	*str;
    int		i;

    str = (char *)malloc(sizeof(*str) * 21);
    i = 0;
    while (i < 21)
    {
        str[i] = '\0';
        i++;
    }
    i = 0;
    return (ft_convert_signed(n, base, str, i));
}
