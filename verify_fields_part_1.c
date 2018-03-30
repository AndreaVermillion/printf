/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verify_fields_part_1.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancardi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/30 20:41:42 by ancardi           #+#    #+#             */
/*   Updated: 2018/03/30 20:48:07 by ancardi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int		ft_verify_all_fla(t_data *a, char spe)
{
	char *temp;

	temp = a->fla;
	if (temp == NULL)
		return (1);
	if (((a->grp == 1) && !ft_verify_fla_group1(a)) ||
		(a->grp == 2 && !ft_verify_fla_group2(a, spe)) ||
		(a->grp == 3 && !ft_verify_fla_group3(a)))
		return (0);
	a->fla_len = ft_strlen(a->fla);
	return (1);
}

int		ft_verify_all_wid(t_data *a)
{
	char	*temp;
	int		i;

	temp = a->wid_raw;
	i = 0;
	if (temp == NULL)
		return (1);
	while (temp[i])
	{
		if (!ft_isdigit(temp[i]))
			return (0);
		i++;
	}
	a->wid_int = ft_atoi(a->wid_raw);
	return (1);
}

int		ft_verify_all_pre(t_data *a, int i)
{
	char	*temp;
	int		len;

	temp = a->pre_raw;
	if (temp == NULL)
	{
		a->pre_int = 0;
		return (1);
	}
	len = ft_strlen(temp);
	if ((len == 1 && temp[0] == '.') ||
		(len == 2 && (temp[0] == '.' && temp[1] == '0')))
	{
		a->pre_int = 1;
		return (1);
	}
	while (temp[i])
	{
		if (!ft_isdigit(temp[i]))
			return (0);
		i++;
	}
	a->pre_raw = ft_cpy_to_char(temp + 1, temp[i]);
	a->pre_int = ft_atoi(a->pre_raw);
	return (1);
}

int		ft_verify_all_len(t_data *a, char c)
{
	char *temp;

	temp = a->len;
	if (temp == NULL)
		return (1);
	a->len_len = ft_strlen(temp);
	if (a->len_len > 2)
		return (0);
	if ((a->len_len == 2) && !((temp[0] == 'h' || temp[1] == 'h')
		|| (temp[0] == 'l' || temp[1] == 'l')))
		return (0);
	if ((a->len_len == 1) && !(temp[0] == 'h' || temp[0] == 'l'
		|| temp[0] == 'j' || temp[0] == 'z'))
		return (0);
	if ((c == 'S' || c == 'C') && (a->len_len == 2 &&
		!((temp[0] == 'h') && (temp[1] == 'h'))))
		return (0);
	if ((c == 's' || c == 'c') && (a->len_len == 2))
		return (0);
	if ((c == 's' || c == 'c') && (temp[0] == 'h' ||
		temp[0] == 'j' || temp[0] == 'z'))
		return (0);
	return (1);
}

int		ft_verify_all_fields(t_data *a, char c)
{
	if (!(ft_verify_all_fla(a, c)) ||
		!(ft_verify_all_wid(a)) ||
		!(ft_verify_all_pre(a, 1)) ||
		!(ft_verify_all_len(a, c)))
	{
		ft_putstr("UNDEF");
		if (a->len)
			a->len_len = ft_strlen(a->len);
		a->arg_len = -1;
		return (0);
	}
	return (1);
}
