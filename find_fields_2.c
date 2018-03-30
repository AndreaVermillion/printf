/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_fields.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancardi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/30 16:15:18 by ancardi           #+#    #+#             */
/*   Updated: 2018/03/30 20:23:58 by ancardi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

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
			(*(a->f_s + i) == 'h') || (*(a->f_s + i) == 'l') ||
			(*(a->f_s + i) == 'j')
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
