/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_elements_1.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancardi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/30 16:43:53 by ancardi           #+#    #+#             */
/*   Updated: 2018/03/30 18:34:34 by ancardi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	ft_print_per_wr_type_no_flag(t_data *a, int i)
{
	while (i < a->wid_int)
	{
		ft_putchar(' ');
		i++;
		a->printed_char_counter++;
	}
	ft_putchar(a->wrong_type);
	a->printed_char_counter++;
}

void	ft_print_per_wr_type_flag_only_0(t_data *a, int i)
{
	while (i < a->wid_int)
	{
		ft_putchar('0');
		i++;
		a->printed_char_counter++;
	}
	ft_putchar(a->wrong_type);
	a->printed_char_counter++;
}

void	ft_print_per_wr_type_flag_mins_0(t_data *a, int i)
{
	ft_putchar(a->wrong_type);
	a->printed_char_counter++;
	while (i < a->wid_int)
	{
		ft_putchar(' ');
		i++;
		a->printed_char_counter++;
	}
}

void	ft_print_per_wr_type_flag_minus(t_data *a, int i)
{
	ft_putchar(a->wrong_type);
	a->printed_char_counter++;
	while (i < a->wid_int)
	{
		ft_putchar(' ');
		i++;
		a->printed_char_counter++;
	}
}
