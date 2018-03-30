/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_functions_4.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancardi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/30 16:35:40 by ancardi           #+#    #+#             */
/*   Updated: 2018/03/30 21:06:59 by ancardi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

static char		*ft_convert_signed(signed long long int n,
	unsigned int base, char *str, int i)
{
	signed long long int	d;
	unsigned long long int	num;
	char					temp;

	d = 1;
	if (n < 0)
		str[i++] = '-';
	num = n < 0 ? n * (-1) : n;
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

char			*ft_itoa_base_signed(signed long long int n, int base)
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

void			ft_memdel(void **ap)
{
	if (ap && *ap)
	{
		free(*ap);
		*ap = NULL;
	}
}

int				ft_check_if_there_is_a_char(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if ((str[i] >= 'a' && str[i] <= 'z') ||
			(str[i] >= 'A' && str[i] <= 'Z'))
			return (1);
		i++;
	}
	return (0);
}
