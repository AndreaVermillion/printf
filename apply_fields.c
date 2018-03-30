/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_fields.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancardi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/29 23:27:08 by ancardi           #+#    #+#             */
/*   Updated: 2018/03/30 17:57:43 by ancardi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	ft_get_arg_type(t_data *a, va_list arg)
{
	a->wtp = 1;
	if (a->len_len == 0)
		ft_get_arg_type_len_len_0(a, arg);
	else if (a->len_len == 1)
		ft_get_arg_type_len_len_1(a, arg);
	else
		ft_get_arg_type_len_len_2(a, arg);
}

void	ft_apply_precision(t_data *a)
{
	if (a->grp == 1)
		ft_apply_pre_grp1(a);
	else if (a->grp == 2)
		ft_apply_pre_grp2(a);
	else
		ft_apply_pre_grp3(a);
}

void	ft_apply_width(t_data *a)
{
	if (a->grp == 1)
		ft_apply_width_grp_1(a);
	else if (a->grp == 2)
		ft_apply_width_grp_2(a, -1);
	else
		ft_apply_width_grp_3(a);
}

void	ft_apply_fields(t_data *a)
{
	if (a->wtp == 1)
		ft_apply_fields_wtp_1(a);
	else if (a->wtp == 2)
		ft_apply_fields_wtp_2(a);
	else if (a->wtp == 3)
		ft_apply_width_ls_s(a);
	else if (a->wtp == 4)
		ft_apply_fields_wtp_4(a);
	else if (a->wtp == 5)
		ft_apply_width_lc_c(a);
	else if (a->wtp == 6)
	{
		ft_apply_width_grp_1_p(a);
		ft_memdel((void **)&a->fla);
		ft_memdel((void **)&a->pre_raw);
		ft_putstr(a->arg_str_conv);
	}
}
