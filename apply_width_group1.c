/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_width_group1.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancardi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/30 01:49:08 by ancardi           #+#    #+#             */
/*   Updated: 2018/03/30 02:07:20 by ancardi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	ft_apply_width_grp_1(t_data *a)
{
	char *temp;

	temp = ft_strnew(a->wid_int);
	ft_memset(temp, ' ', a->wid_int);
	if (a->wid_gap > 0 && a->fla_len == 0)
		a->arg_str_conv = ft_cpy_to_nb(temp, a->arg_str_conv,
				a->wid_int - a->wid_gap, a->wid_int);
	if (a->wid_gap > 0 && a->fla_len != 0)
		a->arg_str_conv = ft_cpy_to_nb(temp, a->arg_str_conv, 0, a->wid_int);
}

void	ft_apply_width_grp_1_p_part1(t_data *a)
{
	char *t;

	t = ft_strnew(a->wid_int);
	ft_memset(t, ' ', a->wid_int);
	if (a->fla_len == 0)
		a->arg_str_conv = ft_cpy_to_nb(t, a->arg_str_conv,
			a->wid_int - a->arg_len, a->wid_int);
	if (a->fla_len == 1)
		a->arg_str_conv = ft_cpy_to_nb(t, a->arg_str_conv, 0,
				a->wid_int + 2);
}

void	ft_apply_width_grp_1_p(t_data *a)
{
	char	*t;
	int		i;

	if (a->pre_int == 1 && (a->pre_raw[0] == '.' || a->pre_raw[0] == '0'))
		i = 1;
	else
		i = 2;
	t = ft_strnew(a->arg_len + i);
	ft_memset(t, ' ', a->arg_len + i);
	t[0] = '0';
	t[1] = 'x';
	a->arg_str_conv = ft_cpy_to_nb(t, a->arg_str_conv, 2, a->arg_len + i);
	a->arg_len = ft_strlen(a->arg_str_conv);
	if (a->wid_int > a->arg_len)
		ft_apply_width_grp_1_p_part1(a);
	a->arg_len = ft_strlen(a->arg_str_conv);
}

void	ft_apply_c_more_than_one(t_data *a, char *temp, char *temp_c, int i)
{
	if (a->fla_len == 0)
	{
		a->arg_str_conv = ft_cpy_to_nb(temp, temp_c,
				a->wid_int - 1, a->wid_int);
		i = -1;
		while (temp[++i] == ' ')
			ft_putchar(temp[i]);
		ft_putchar(a->arg_char_conv);
	}
	if (a->fla_len != 0)
	{
		a->arg_str_conv = ft_cpy_to_nb(temp, temp_c, 0, a->wid_int);
		ft_putchar(a->arg_char_conv);
		i = 0;
		while (temp[++i] == ' ')
			ft_putchar(temp[i]);
	}
	a->arg_len = ft_strlen(a->arg_str_conv);
}

void	ft_apply_width_grp_1_c(t_data *a)
{
	char *temp;
	char *temp_c;

	temp_c = ft_strnew(1);
	temp_c[0] = a->arg_char_conv;
	temp = ft_strnew(a->wid_int);
	ft_memset(temp, ' ', a->wid_int);
	if (a->wid_int <= 1 && (a->pre_int == 0 ||
		(a->pre_int == 1 && (a->pre_raw[0] == '.'
		|| a->pre_raw[0] == '0'))))
	{
		ft_putchar(a->arg_char_conv);
		a->arg_len = 1;
	}
	else
		ft_apply_c_more_than_one(a, temp, temp_c, 0);
}
