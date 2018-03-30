/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_precision_group3.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancardi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/30 01:34:28 by ancardi           #+#    #+#             */
/*   Updated: 2018/03/30 01:47:31 by ancardi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	ft_apply_pre_grp3_negative_value(t_data *a)
{
	char	*temp;
	int		pre_gap;

	if (a->pre_int >= a->arg_len)
	{
		if (a->pre_int == a->arg_len)
			pre_gap = 2;
		else
			pre_gap = a->pre_int - a->arg_len + 2;
		temp = ft_strnew(a->pre_int + 1);
		ft_memset(temp, '0', a->pre_int + 1);
		temp[0] = '-';
		a->arg_str_conv = ft_cpy_to_nb(temp, a->arg_str_conv + 1,
				pre_gap, a->pre_int + 1);
	}
}

void	ft_apply_pre_grp2_grp3_positive_value_no_flags(t_data *a)
{
	char *temp;

	if (a->pre_int <= a->arg_len)
	{
		temp = ft_strnew(a->arg_len);
		ft_memset(temp, '0', a->arg_len);
		a->arg_str_conv = ft_cpy_to_nb(temp, a->arg_str_conv,
				0, a->arg_len + 1);
	}
	else if (a->pre_int > a->arg_len)
	{
		temp = ft_strnew(a->pre_int);
		ft_memset(temp, '0', a->pre_int);
		a->arg_str_conv = ft_cpy_to_nb(temp, a->arg_str_conv,
				a->pre_int - a->arg_len, a->pre_int);
	}
}

void	ft_apply_pre_grp3_positive_value_len_2(t_data *a)
{
	char *temp;

	ft_apply_pre_grp2_grp3_positive_value_no_flags(a);
	if ((a->fla[0] == '+' && a->fla[1] == '-') ||
			(a->fla[0] == '+' && a->fla[1] == '0'))
	{
		a->arg_len = ft_strlen(a->arg_str_conv);
		temp = ft_strnew(a->arg_len + 1);
		temp[0] = '+';
		a->arg_str_conv = ft_cpy_to_nb(temp, a->arg_str_conv,
				1, a->arg_len + 1);
	}
	if ((a->fla[0] == ' ' && a->fla[1] == '0') ||
			(a->fla[0] == ' ' && a->fla[1] == '-'))
	{
		a->arg_len = ft_strlen(a->arg_str_conv);
		temp = ft_strnew(a->arg_len + 1);
		temp[0] = ' ';
		a->arg_str_conv = ft_cpy_to_nb(temp, a->arg_str_conv,
				1, a->arg_len + 1);
	}
}

void	ft_apply_pre_grp3_positive_value_len_1(t_data *a)
{
	char *temp;

	ft_apply_pre_grp2_grp3_positive_value_no_flags(a);
	if (a->fla[0] == '+')
	{
		a->arg_len = ft_strlen(a->arg_str_conv);
		temp = ft_strnew(a->arg_len + 1);
		temp[0] = '+';
		a->arg_str_conv = ft_cpy_to_nb(temp, a->arg_str_conv,
				1, a->arg_len + 1);
	}
	if (a->fla[0] == ' ')
	{
		a->arg_len = ft_strlen(a->arg_str_conv);
		temp = ft_strnew(a->arg_len + 1);
		temp[0] = ' ';
		a->arg_str_conv = ft_cpy_to_nb(temp, a->arg_str_conv,
				1, a->arg_len + 1);
	}
}

void	ft_apply_pre_grp3(t_data *a)
{
	if (a->arg_atoi_int >= 0)
	{
		if (a->fla_len == 0)
			ft_apply_pre_grp2_grp3_positive_value_no_flags(a);
		else if (a->fla_len == 1)
			ft_apply_pre_grp3_positive_value_len_1(a);
		else if (a->fla_len == 2)
			ft_apply_pre_grp3_positive_value_len_2(a);
	}
	else if (a->arg_atoi_int < 0)
		ft_apply_pre_grp3_negative_value(a);
}
