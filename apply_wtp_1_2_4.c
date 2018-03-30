/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_wtp_1_2_4.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancardi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/30 15:17:40 by ancardi           #+#    #+#             */
/*   Updated: 2018/03/30 15:22:47 by ancardi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	ft_apply_fields_wtp_4(t_data *a)
{
	if (a->arg_len == 0)
		ft_apply_special_zero_conditions_for_c(a);
	else
		ft_apply_width_grp_1_c(a);
	ft_memdel((void **)&a->fla);
}

void	ft_apply_fields_wtp_2(t_data *a)
{
	char *temp;

	a->arg_len = ft_strlen(a->arg_str_conv);
	ft_apply_precision(a);
	temp = ft_strdup(a->arg_str_conv);
	a->arg_len = ft_strlen(temp);
	ft_find_diff_arg_len_vs_wid_vs_pre(a);
	ft_apply_width_grp_1(a);
	if (a->arg_len == 0)
		ft_apply_special_zero_conditions_for_s(a);
	temp = ft_strdup(a->arg_str_conv);
	a->arg_len = ft_strlen(temp);
	ft_memdel((void **)&a->fla);
	ft_memdel((void **)&a->pre_raw);
	ft_putstr(a->arg_str_conv);
}

void	ft_apply_fields_wtp_1(t_data *a)
{
	char *temp;

	a->arg_len = ft_strlen(a->arg_str_conv);
	if (!(ft_check_if_there_is_a_char(a->arg_str_conv)))
		a->arg_atoi_int = ft_atoi(a->arg_str_conv);
	ft_apply_precision(a);
	temp = ft_strdup(a->arg_str_conv);
	a->arg_len = ft_strlen(temp);
	ft_find_diff_arg_len_vs_wid_vs_pre(a);
	ft_apply_width(a);
	temp = ft_strdup(a->arg_str_conv);
	a->arg_len = ft_strlen(temp);
	if (a->arg_atoi_int == 0)
		ft_apply_special_zero_conditions(a);
	a->arg_len = ft_strlen(a->arg_str_conv);
	ft_memdel((void **)&a->fla);
	ft_memdel((void **)&a->pre_raw);
	ft_putstr(a->arg_str_conv);
}
