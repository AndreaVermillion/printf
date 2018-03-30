/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assist_functions_1.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancardi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/30 15:30:34 by ancardi           #+#    #+#             */
/*   Updated: 2018/03/30 15:33:24 by ancardi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

char	*ft_cpy_to_nb(char *dst, const char *src, size_t start, int n)
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

void	ft_find_diff_arg_len_vs_wid_vs_pre(t_data *a)
{
	if (a->arg_len >= a->wid_int)
		a->wid_gap = 0;
	if (a->arg_len < a->wid_int)
		a->wid_gap = a->arg_len;
}

int		ft_len_to_char(char *s, char c)
{
	int i;

	i = 0;
	while (s[i] != c)
		i++;
	return (i);
}

int		ft_find_format(char *s, char c, t_data *a)
{
	int		i;
	int		len;
	char	*sub;

	i = 0;
	len = ft_len_to_char(s, c) + 1;
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
	return (0);
}
