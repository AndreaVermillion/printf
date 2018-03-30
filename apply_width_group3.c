/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_width_group3.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancardi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/30 15:10:46 by ancardi           #+#    #+#             */
/*   Updated: 2018/03/30 15:16:52 by ancardi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	ft_apply_width_grp_3_len_2_part1(t_data *a, char *temp, int i)
{
	a->arg_str_conv = ft_cpy_to_nb(temp, a->arg_str_conv,
			a->wid_int - a->wid_gap, a->wid_int);
	if (a->pre_int == 0 && a->fla[0] == '+' && a->fla[1] == '0')
	{
		if (a->arg_atoi_int >= 0)
			temp[0] = '+';
		else
			temp[0] = '-';
		while (++i < a->wid_int - a->wid_gap + 1)
			temp[i] = '0';
		a->arg_str_conv = temp;
	}
	if (a->pre_int == 0 && a->fla[0] == ' ' && a->fla[1] == '0')
	{
		if (a->arg_atoi_int < 0)
			temp[0] = '-';
		while (++i < a->wid_int - a->wid_gap + 1)
			temp[i] = '0';
		a->arg_str_conv = temp;
	}
}

void	ft_apply_width_grp_3_len_2(t_data *a, char *temp, int i)
{
	if ((a->fla[0] == '+' && a->fla[1] == '-') ||
			(a->fla[0] == ' ' && a->fla[1] == '-'))
		a->arg_str_conv = ft_cpy_to_nb(temp, a->arg_str_conv, 0, a->wid_int);
	if ((a->fla[0] == '+' && a->fla[1] == '0') ||
			(a->fla[0] == ' ' && a->fla[1] == '0'))
		ft_apply_width_grp_3_len_2_part1(a, temp, i);
}

void	ft_apply_width_grp_3_len_1(t_data *a, char *temp, int i)
{
	if (a->fla[0] == '0' || a->fla[0] == '+' || a->fla[0] == ' ')
	{
		a->arg_str_conv = ft_cpy_to_nb(temp, a->arg_str_conv,
				a->wid_int - a->wid_gap, a->wid_int);
		if (a->pre_int == 0 && a->fla[0] == '0')
		{
			if (a->arg_atoi_int >= 0)
			{
				i = -1;
				while (temp[++i] == ' ')
					temp[i] = '0';
			}
			if (a->arg_atoi_int < 0)
			{
				temp[0] = '-';
				while (++i < a->wid_int - a->wid_gap + 1)
					temp[i] = '0';
			}
			a->arg_str_conv = temp;
		}
	}
	if (a->fla[0] == '-')
		a->arg_str_conv = ft_cpy_to_nb(temp, a->arg_str_conv, 0, a->wid_int);
}

void	ft_apply_width_grp_3(t_data *a)
{
	char *temp;

	if (a->wid_gap > 0)
	{
		temp = ft_strnew(a->wid_int);
		ft_memset(temp, ' ', a->wid_int);
		if (a->fla_len == 0)
			a->arg_str_conv = ft_cpy_to_nb(temp, a->arg_str_conv,
					a->wid_int - a->wid_gap, a->wid_int);
		if (a->fla_len == 1)
			ft_apply_width_grp_3_len_1(a, temp, 0);
		if (a->fla_len == 2)
			ft_apply_width_grp_3_len_2(a, temp, 0);
	}
}
