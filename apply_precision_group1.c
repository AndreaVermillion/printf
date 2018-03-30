/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_precision_group1.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancardi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/30 01:04:37 by ancardi           #+#    #+#             */
/*   Updated: 2018/03/30 01:10:56 by ancardi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	ft_apply_pre_grp1(t_data *a)
{
	char *temp;

	if (a->pre_raw != NULL)
	{
		if (a->spe == 's')
		{
			if ((a->pre_int == 0 && a->pre_raw[0] == '0') ||
					(a->pre_int == 1 && a->pre_raw[0] == '.'))
			{
				temp = ft_strnew(1);
				temp[0] = ' ';
				a->arg_str_conv = temp;
			}
			else if (a->pre_int < a->arg_len)
			{
				temp = ft_strnew(a->pre_int);
				a->arg_str_conv = ft_strncpy(temp, a->arg_str_conv, a->pre_int);
			}
		}
	}
}
