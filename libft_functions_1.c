/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_functions_1.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancardi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/30 16:30:59 by ancardi           #+#    #+#             */
/*   Updated: 2018/03/30 16:31:49 by ancardi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

static int	ft_result(size_t result, int negative, int count)
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

int			ft_atoi(const char *str)
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

int			ft_isdigit(int a)
{
	if (a >= '0' && a <= '9')
		return (1);
	return (0);
}

void		*ft_memset(void *dst, int c, size_t n)
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

void		ft_putchar(char c)
{
	write(1, &c, 1);
}
