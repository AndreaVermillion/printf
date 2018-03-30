/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_arg_group3.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancardi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/30 16:14:11 by ancardi           #+#    #+#             */
/*   Updated: 2018/03/30 18:44:45 by ancardi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	ft_select_args_group3_len_2(t_data *a, va_list arg)
{
	if (a->spe == 'D')
	{
		a->a_g3_d_l = va_arg(arg, long int);
		a->arg_str_conv = ft_itoa_base_signed(a->a_g3_d_l, 10);
	}
	else
	{
		if (a->len[0] == 'h' && a->len[1] == 'h')
		{
			a->a_g3_hh = (signed char)va_arg(arg, int);
			a->arg_str_conv = ft_itoa_base_signed(a->a_g3_hh, 10);
		}
		else if (a->len[0] == 'l' && a->len[1] == 'l')
		{
			a->a_g3_ll = va_arg(arg, long long int);
			a->arg_str_conv = ft_itoa_base_signed(a->a_g3_ll, 10);
		}
	}
}

void	ft_select_args_group3_len_1_part1(t_data *a, va_list arg)
{
	if (a->len[0] == 'l')
	{
		a->a_g3_d_l = va_arg(arg, long int);
		a->arg_str_conv = ft_itoa_base_signed(a->a_g3_d_l, 10);
	}
	else if (a->len[0] == 'h')
	{
		a->a_g3_h = (short int)va_arg(arg, int);
		a->arg_str_conv = ft_itoa_base_signed(a->a_g3_h, 10);
	}
	else if (a->len[0] == 'j')
	{
		a->a_g3_j = va_arg(arg, intmax_t);
		a->arg_str_conv = ft_itoa_base_signed(a->a_g3_j, 10);
	}
	else if (a->len[0] == 'z')
	{
		a->a_g3_z = va_arg(arg, size_t);
		a->arg_str_conv = ft_itoa_base_signed(a->a_g3_z, 10);
	}
}

void	ft_select_args_group3_len_1(t_data *a, va_list arg)
{
	if (a->spe == 'D')
	{
		a->a_g3_d_l = va_arg(arg, long int);
		a->arg_str_conv = ft_itoa_base_signed(a->a_g3_d_l, 10);
	}
	else
		ft_select_args_group3_len_1_part1(a, arg);
}

void	ft_select_args_group3_len_0(t_data *a, va_list arg)
{
	if (a->spe == 'D')
	{
		a->a_g3_d_l = va_arg(arg, long int);
		a->arg_str_conv = ft_itoa_base_signed(a->a_g3_d_l, 10);
	}
	else if (a->spe == 'd' || a->spe == 'i')
	{
		a->a_g3_h = va_arg(arg, int);
		a->arg_str_conv = ft_itoa_base_signed(a->a_g3_h, 10);
	}
}
