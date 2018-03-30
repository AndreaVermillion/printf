/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reset_structures.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancardi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/30 20:33:36 by ancardi           #+#    #+#             */
/*   Updated: 2018/03/30 20:33:55 by ancardi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	ft_set_everything_to_zero_part_2(t_data *a)
{
	a->a_g1_s_hs = NULL;
	a->a_g1_c_hc = 0;
	a->a_g1_s_ls = NULL;
	a->a_g1_c_lc = 0;
	a->a_g1_p = NULL;
	a->a_g2_o_u_x = 0;
	a->a_g2_hh = 0;
	a->a_g2_o_u_l = 0;
	a->a_g2_h = 0;
	a->a_g2_ll = 0;
	a->a_g2_j = 0;
	a->a_g2_z = 0;
	a->a_g3_h = 0;
	a->a_g3_hh = 0;
	a->a_g3_d_l = 0;
	a->a_g3_ll = 0;
	a->a_g3_j = 0;
	a->a_g3_z = 0;
}

void	ft_set_everything_to_zero_part_1(t_data *a)
{
	a->f_s = NULL;
	a->f_r = NULL;
	a->grp = 0;
	a->wtp = 1;
	a->fla = NULL;
	a->fla_len = 0;
	a->wid_raw = NULL;
	a->wid_int = 0;
	a->wid_gap = 0;
	a->pre_raw = NULL;
	a->pre_int = 0;
	a->len = NULL;
	a->len_len = 0;
	a->arg_char_conv = 0;
	a->arg_uni_char_conv = 0;
	a->arg_atoi_int = 1;
	a->arg_str_conv = NULL;
	a->arg_uni_str_conv = 0;
	a->arg_len = 0;
}

void	ft_set_everything_to_zero(t_data *a)
{
	ft_set_everything_to_zero_part_1(a);
	ft_set_everything_to_zero_part_2(a);
}
