/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_zero_conditions_1.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancardi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/30 15:23:20 by ancardi           #+#    #+#             */
/*   Updated: 2018/03/30 17:59:54 by ancardi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	ft_apply_special_zero_conditions_for_c(t_data *a)
{
	int i;

	i = 1;
	if (a->wid_int > 1)
	{
		i = 0;
		while (++i < a->wid_int)
			ft_putchar(' ');
	}
	ft_putchar(a->arg_char_conv);
	a->arg_len = i;
}

void	ft_apply_special_zero_conditions_for_s(t_data *a)
{
	char	*temp;
	int		i;

	temp = ft_strnew(a->wid_int);
	i = -1;
	while (++i < a->wid_int)
		temp[i] = ' ';
	a->arg_str_conv = temp;
}

void	ft_apply_special_zero_conditions(t_data *a)
{
	if ((a->pre_int == 1 && (a->pre_raw[0] == '.' || a->pre_raw[0] == '0')))
	{
		if (a->wid_int <= 1)
			ft_apply_special_0_wid_smaller_to_1(a);
		else
			ft_apply_special_0_wid_bigger_than_1(a);
	}
}

void	ft_apply_pre_grp2_hash_o_zero_condition(t_data *a)
{
	char *temp;

	if (a->pre_int == 0)
		a->arg_str_conv = ft_strdup("0");
	else
	{
		temp = ft_strnew(a->pre_int);
		ft_memset(temp, '0', a->pre_int);
		a->arg_str_conv = temp;
	}
}

void	ft_apply_pre_grp2_hash_x_zero_condition(t_data *a)
{
	char *temp;

	if (a->pre_int == 0)
		a->arg_str_conv = ft_strdup("0");
	else
	{
		temp = ft_strnew(a->pre_int);
		ft_memset(temp, '0', a->pre_int);
		a->arg_str_conv = temp;
	}
}
