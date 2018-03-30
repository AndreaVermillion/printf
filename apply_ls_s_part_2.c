/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_ls_s_part_2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancardi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/30 00:24:38 by ancardi           #+#    #+#             */
/*   Updated: 2018/03/30 18:10:34 by ancardi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	ft_apply_width_smaller_arg_len_fla_len_more_zero(t_data *a)
{
	int i;
	int d;
	int nb_char;
	int nb_bytes;

	d = -1;
	i = 0;
	nb_bytes = ft_find_nb_prtble_bytes(a->arg_uni_str_conv, a->pre_int);
	nb_char = ft_find_nb_prtble_char(a->arg_uni_str_conv, a->pre_int);
	while (++d < nb_char)
		ft_unicode_convert(a->arg_uni_str_conv[d]);
	if (a->wid_int > nb_bytes)
	{
		i = -1;
		while (++i < a->wid_int - nb_bytes)
			ft_putchar(' ');
	}
	a->arg_len = i + nb_bytes;
}

void	ft_apply_width_smaller_arg_len_fla_len_equal_zero(t_data *a)
{
	int i;
	int d;
	int nb_char;
	int nb_bytes;

	d = -1;
	i = 0;
	nb_bytes = ft_find_nb_prtble_bytes(a->arg_uni_str_conv, a->pre_int);
	nb_char = ft_find_nb_prtble_char(a->arg_uni_str_conv, a->pre_int);
	if (a->wid_int > nb_bytes)
	{
		i = -1;
		while (++i < a->wid_int - nb_bytes)
			ft_putchar(' ');
	}
	while (++d < nb_char)
		ft_unicode_convert(a->arg_uni_str_conv[d]);
	a->arg_len = i + nb_bytes;
}

void	ft_apply_width_pre_small_arg_len(t_data *a)
{
	if (a->fla_len == 0)
		ft_apply_width_smaller_arg_len_fla_len_equal_zero(a);
	else
		ft_apply_width_smaller_arg_len_fla_len_more_zero(a);
}
