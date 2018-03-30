/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assist_functions_2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancardi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/30 15:33:50 by ancardi           #+#    #+#             */
/*   Updated: 2018/03/30 15:42:01 by ancardi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

char	*ft_cpy_to_char(char *s, char c)
{
	int		i;
	int		len;
	char	*sub;

	i = 0;
	len = ft_len_to_char(s, c);
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

int		ft_find_arg_len_string_unicode(t_data *a)
{
	int total_byte_size;
	int i;

	i = 0;
	total_byte_size = 0;
	while (a->arg_uni_str_conv[i])
	{
		if (a->arg_uni_str_conv[i] <= 127)
			total_byte_size = total_byte_size + 1;
		else if (a->arg_uni_str_conv[i] >= 128 &&
			a->arg_uni_str_conv[i] <= 2047)
			total_byte_size = total_byte_size + 2;
		else if (a->arg_uni_str_conv[i] >= 2048 &&
			a->arg_uni_str_conv[i] <= 65335)
			total_byte_size = total_byte_size + 3;
		else if (a->arg_uni_str_conv[i] >= 65536 &&
			a->arg_uni_str_conv[i] <= 1114111)
			total_byte_size = total_byte_size + 4;
		i++;
	}
	return (total_byte_size);
}

int		ft_find_arg_len_char_unicode(t_data *a)
{
	if (a->arg_uni_char_conv <= 127)
		return (1);
	else if (a->arg_uni_char_conv >= 128 && a->arg_uni_char_conv <= 2047)
		return (2);
	else if (a->arg_uni_char_conv >= 2048 && a->arg_uni_char_conv <= 65335)
		return (3);
	else if (a->arg_uni_char_conv >= 65536 && a->arg_uni_char_conv <= 1114111)
		return (4);
	return (0);
}

int		ft_find_nb_prtble_bytes(unsigned int *tab, int size)
{
	int nb_of_printable_bytes;
	int bytes;
	int i;

	i = 0;
	bytes = 0;
	nb_of_printable_bytes = 0;
	while (nb_of_printable_bytes < size)
	{
		if (tab[i] <= 127)
			bytes = 1;
		else if (tab[i] >= 128 && tab[i] <= 2047)
			bytes = 2;
		else if (tab[i] >= 2048 && tab[i] <= 65335)
			bytes = 3;
		else if (tab[i] >= 65536 && tab[i] <= 1114111)
			bytes = 4;
		nb_of_printable_bytes += bytes;
		i++;
	}
	if (nb_of_printable_bytes > size)
		return (nb_of_printable_bytes - bytes);
	return (nb_of_printable_bytes);
}

int		ft_find_nb_prtble_char(unsigned int *tab, int size)
{
	int nb_of_printable_bytes;
	int bytes;
	int i;

	i = 0;
	bytes = 0;
	nb_of_printable_bytes = 0;
	while (nb_of_printable_bytes < size)
	{
		if (tab[i] <= 127)
			bytes = 1;
		else if (tab[i] >= 128 && tab[i] <= 2047)
			bytes = 2;
		else if (tab[i] >= 2048 && tab[i] <= 65335)
			bytes = 3;
		else if (tab[i] >= 65536 && tab[i] <= 1114111)
			bytes = 4;
		nb_of_printable_bytes += bytes;
		i++;
	}
	if (nb_of_printable_bytes > size)
		return (i - 1);
	return (i);
}
