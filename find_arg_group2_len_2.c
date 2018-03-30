/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_arg_group2_len_2.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancardi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/30 16:13:18 by ancardi           #+#    #+#             */
/*   Updated: 2018/03/30 16:14:03 by ancardi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	ft_select_args_group2_len_2_part1(t_data *a, va_list arg)
{
	if (a->len[0] == 'h' && a->len[1] == 'h')
	{
		a->a_g2_hh = (unsigned char)va_arg(arg, int);
		if (a->spe == 'o')
			a->arg_str_conv = ft_itoa_base_unsigned(a->a_g2_hh, 8);
		else if (a->spe == 'u')
			a->arg_str_conv = ft_itoa_base_unsigned(a->a_g2_hh, 10);
		else if (a->spe == 'x' || a->spe == 'X')
			a->arg_str_conv = ft_itoa_base_unsigned(a->a_g2_hh, 16);
	}
}

void	ft_select_args_group2_len_2_part2(t_data *a, va_list arg)
{
	if (a->len[0] == 'l' && a->len[1] == 'l')
	{
		a->a_g2_ll = va_arg(arg, unsigned long long int);
		if (a->spe == 'o')
			a->arg_str_conv = ft_itoa_base_unsigned(a->a_g2_ll, 8);
		else if (a->spe == 'u')
			a->arg_str_conv = ft_itoa_base_unsigned(a->a_g2_ll, 10);
		else if (a->spe == 'x' || a->spe == 'X')
			a->arg_str_conv = ft_itoa_base_unsigned(a->a_g2_ll, 16);
	}
}

void	ft_select_args_group2_len_2(t_data *a, va_list arg)
{
	if (a->spe == 'O' || a->spe == 'U')
	{
		a->a_g2_o_u_l = va_arg(arg, unsigned long int);
		if (a->spe == 'O')
			a->arg_str_conv = ft_itoa_base_unsigned(a->a_g2_o_u_l, 8);
		if (a->spe == 'U')
			a->arg_str_conv = ft_itoa_base_unsigned(a->a_g2_o_u_l, 10);
	}
	else
	{
		ft_select_args_group2_len_2_part1(a, arg);
		ft_select_args_group2_len_2_part2(a, arg);
	}
}
