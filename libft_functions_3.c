/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_functions_3.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancardi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/30 16:33:28 by ancardi           #+#    #+#             */
/*   Updated: 2018/03/30 16:35:18 by ancardi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

size_t			ft_strlen(const char *str)
{
	size_t i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char			*ft_strncpy(char *dst, const char *src, size_t n)
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

char			*ft_strnew(size_t size)
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

static char		*ft_convert_unsigned(unsigned long long int n,
		int base, char *str, int i)
{
	unsigned long long int	d;
	char					temp;

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

char			*ft_itoa_base_unsigned(unsigned long long int n, int base)
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
