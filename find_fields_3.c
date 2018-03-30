/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_fields.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancardi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/30 16:15:18 by ancardi           #+#    #+#             */
/*   Updated: 2018/03/30 20:25:02 by ancardi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int		ft_find_percent_with_percent(char *s)
{
	size_t len;

	len = ft_strlen(s);
	if ((len > 1) && (*(s + 1) == '%'))
		return (1);
	return (0);
}

int		ft_find_percent_to_percent(char *s)
{
	size_t	len;
	size_t	i;

	i = 1;
	len = ft_strlen(s);
	while ((*(s + i) == '+' || *(s + i) == '-' ||
			*(s + i) == ' ' || *(s + i) == '.' ||
			*(s + i) == '0' || *(s + i) == '#' ||
			(*(s + i) > '0' && (*(s + i) <= '9'))) && (i + 1 < len))
	{
		if (*(s + i + 1) == '%')
			return (1);
		i++;
	}
	return (0);
}

int		ft_find_percent_is_alone(char *s)
{
	size_t	len;
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
	return (0);
}
