/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_ls_s_part_1.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancardi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/30 00:13:44 by ancardi           #+#    #+#             */
/*   Updated: 2018/03/30 18:11:36 by ancardi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	ft_apply_width_ls_s_pre_fla_len_equal_zero(t_data *a)
{
	int i;
	int d;

	i = -1;
	d = -1;
	if (a->arg_len >= a->wid_int)
	{
		while (a->arg_uni_str_conv[++i])
			ft_unicode_convert(a->arg_uni_str_conv[i]);
	}
	else
	{
		while (++i < a->wid_int - a->arg_len)
			ft_putchar(' ');
		while (a->arg_uni_str_conv[++d])
			ft_unicode_convert(a->arg_uni_str_conv[d]);
		a->arg_len = a->arg_len + i;
	}
}

void	ft_apply_width_ls_s_pre_int_greater_arg_len(t_data *a)
{
	int i;
	int d;

	i = -1;
	d = -1;
	if (a->fla_len == 0)
		ft_apply_width_ls_s_pre_fla_len_equal_zero(a);
	else
	{
		while (a->arg_uni_str_conv[++d])
			ft_unicode_convert(a->arg_uni_str_conv[d]);
		while (++i < a->wid_int - a->arg_len)
			ft_putchar(' ');
		a->arg_len = a->arg_len + i;
	}
}

void	ft_apply_width_ls_s_pre_int_zero_len_equal_zero(t_data *a)
{
	int i;
	int d;

	i = -1;
	d = -1;
	if (a->arg_len >= a->wid_int)
	{
		while (a->arg_uni_str_conv[++i])
			ft_unicode_convert(a->arg_uni_str_conv[i]);
	}
	else
	{
		while (++i < a->wid_int - a->arg_len)
			ft_putchar(' ');
		while (a->arg_uni_str_conv[++d])
			ft_unicode_convert(a->arg_uni_str_conv[d]);
		a->arg_len = a->arg_len + i;
	}
}

void	ft_apply_width_ls_s_pre_int_zero(t_data *a)
{
	int i;
	int d;

	d = -1;
	i = -1;
	if (a->fla_len == 0)
		ft_apply_width_ls_s_pre_int_zero_len_equal_zero(a);
	else
	{
		while (a->arg_uni_str_conv[++d])
			ft_unicode_convert(a->arg_uni_str_conv[d]);
		while (++i < a->wid_int - a->arg_len)
			ft_putchar(' ');
		a->arg_len = a->arg_len + i;
	}
}

void	ft_apply_width_ls_s(t_data *a)
{
	if (!(a->arg_len == 6 && a->arg_uni_str_conv == NULL))
	{
		if (a->pre_int == 0)
			ft_apply_width_ls_s_pre_int_zero(a);
		else if (a->pre_int >= a->arg_len)
			ft_apply_width_ls_s_pre_int_greater_arg_len(a);
		else if (a->pre_int < a->arg_len)
			ft_apply_width_pre_small_arg_len(a);
	}
}
