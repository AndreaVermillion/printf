/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_zero_conditions_2.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancardi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/30 15:25:08 by ancardi           #+#    #+#             */
/*   Updated: 2018/03/30 18:06:30 by ancardi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	ft_apply_special_0_wid_bigger_1_part_2(t_data *a, char *temp)
{
	int i;

	i = -1;
	while (++i < a->wid_int)
	{
		temp[i] = '+';
		temp[i - 1] = ' ';
	}
}

void	ft_apply_special_0_wid_bigger_1_part_1(t_data *a, char *temp)
{
	int i;

	i = -1;
	while (++i < a->wid_int)
	{
		if (i == 0)
			temp[i] = '+';
		else
			temp[i] = ' ';
	}
}

void	ft_apply_special_0_wid_bigger_than_1(t_data *a)
{
	char	*temp;
	int		i;

	temp = ft_strnew(a->wid_int);
	if ((a->fla_len == 0) ||
		(a->fla_len == 1 && a->fla[0] == ' ') ||
		(a->fla_len == 1 && a->fla[0] == '-') ||
		(a->fla_len == 1 && a->fla[0] == '0') ||
		((a->fla_len == 1) && (a->fla[0] == '#') &&
		(a->spe == 'x' || a->spe == 'X')) ||
		(a->fla_len == 2 && (a->fla[0] == ' ' && a->fla[1] == '0')) ||
		(a->fla_len == 2 && (a->fla[0] == ' ' && a->fla[1] == '-')) ||
		(a->fla_len == 2 && (a->fla[0] == '-' && a->fla[1] == '#')) ||
		(a->fla_len == 2 && (a->fla[0] == '0' && a->fla[1] == '#')))
	{
		i = -1;
		while (++i < a->wid_int)
			temp[i] = ' ';
	}
	else if (a->fla_len == 2 && (a->fla[0] == '+' && a->fla[1] == '-'))
		ft_apply_special_0_wid_bigger_1_part_1(a, temp);
	else if ((a->fla_len == 1 && a->fla[0] == '+') ||
			(a->fla_len == 2 && (a->fla[0] == '+' && a->fla[1] == '0')))
		ft_apply_special_0_wid_bigger_1_part_2(a, temp);
	a->arg_str_conv = temp;
}

void	ft_apply_special_0_wid_smaller_to_1(t_data *a)
{
	if ((a->fla_len == 2) && (a->fla[0] == '-') &&
		(a->fla[1] == '#') && (a->spe == 'o' || a->spe == 'O'))
		a->arg_str_conv = ft_strdup("0");
	else if ((a->fla_len == 0) ||
			(a->fla_len > 0 && a->fla[0] == '-') ||
			(a->fla_len > 0 && a->fla[0] == '0') ||
			(a->fla_len > 0 && a->fla[0] == '#' &&
			(a->spe == 'x' || a->spe == 'X')))
	{
		if (a->wid_int == 0)
		{
			a->arg_str_conv = ft_strdup("");
		}
		else
		{
			a->arg_str_conv = ft_strdup(" ");
		}
	}
	else
	{
		if (a->fla[0] == '+')
			a->arg_str_conv = ft_strdup("+");
		if (a->fla[0] == ' ')
			a->arg_str_conv = ft_strdup(" ");
	}
}
