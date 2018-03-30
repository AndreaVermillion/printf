/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_lc_C.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancardi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/29 23:32:23 by ancardi           #+#    #+#             */
/*   Updated: 2018/03/29 23:35:55 by ancardi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	ft_apply_width_lc_c_fla_len_greater_than_zero(t_data *a)
{
	int	i;

	i = 0;
	if (a->arg_len >= a->wid_int)
		ft_unicode_convert(a->arg_uni_char_conv);
	else
	{
		i = a->arg_len - 1;
		ft_unicode_convert(a->arg_uni_char_conv);
		while (++i < a->wid_int)
			ft_putchar(' ');
		a->arg_len = i;
	}
}

void	ft_apply_width_lc_c_fla_len_zero(t_data *a)
{
	int i;

	if (a->arg_len >= a->wid_int)
		ft_unicode_convert(a->arg_uni_char_conv);
	else
	{
		i = -1;
		while (++i < a->wid_int - a->arg_len)
			ft_putchar(' ');
		ft_unicode_convert(a->arg_uni_char_conv);
		a->arg_len = a->arg_len + i;
	}
}

void	ft_apply_width_lc_c(t_data *a)
{
	if (a->fla_len == 0)
		ft_apply_width_lc_c_fla_len_zero(a);
	else
		ft_apply_width_lc_c_fla_len_greater_than_zero(a);
}
