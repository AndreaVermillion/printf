/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_arg_type_len_len_0_1_2.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancardi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/30 16:29:22 by ancardi           #+#    #+#             */
/*   Updated: 2018/03/30 16:30:35 by ancardi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	ft_get_arg_type_len_len_2(t_data *a, va_list arg)
{
	if (a->grp == 1)
		ft_select_args_group1_len_2(a, arg);
	else if (a->grp == 2)
		ft_select_args_group2_len_2(a, arg);
	else
		ft_select_args_group3_len_2(a, arg);
}

void	ft_get_arg_type_len_len_1(t_data *a, va_list arg)
{
	if (a->grp == 1)
		ft_select_args_group1_len_1(a, arg);
	else if (a->grp == 2)
		ft_select_args_group2_len_1(a, arg);
	else
		ft_select_args_group3_len_1(a, arg);
}

void	ft_get_arg_type_len_len_0(t_data *a, va_list arg)
{
	if (a->grp == 1)
		ft_select_args_group1_len_0(a, arg);
	else if (a->grp == 2)
		ft_select_args_group2_len_0(a, arg);
	else
		ft_select_args_group3_len_0(a, arg);
}
