/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_elements_2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancardi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/30 16:45:21 by ancardi           #+#    #+#             */
/*   Updated: 2018/03/30 18:40:38 by ancardi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	ft_print_per_wr_type_with_flag(char *temp, t_data *a, int i)
{
	if (ft_strchr(temp, '-') && !(ft_strchr(temp, '0')))
		ft_print_per_wr_type_flag_minus(a, i);
	else if (ft_strchr(temp, '-') && (ft_strchr(temp, '0')))
		ft_print_per_wr_type_flag_mins_0(a, i);
	else if (!(ft_strchr(temp, '-')) && (ft_strchr(temp, '0')))
		ft_print_per_wr_type_flag_only_0(a, i);
	else
		ft_print_per_wr_type_no_flag(a, i);
}

char	*ft_print_per_to_wr_type(char *s, t_data *a, char c)
{
	char	*temp;
	int		nb;
	int		i;

	nb = 0;
	i = 1;
	if (c == '%')
		a->wrong_type = '%';
	temp = ft_strdup(s);
	ft_set_everything_to_zero(a);
	ft_find_format(temp, a->wrong_type, a);
	ft_find_all_fields(a, a->wrong_type);
	ft_verify_all_fields(a, a->wrong_type);
	if (a->fla_len)
		ft_print_per_wr_type_with_flag(temp, a, i);
	else
		ft_print_per_wr_type_no_flag(a, i);
	while (temp[nb] == '+' || temp[nb] == '-' || temp[nb] == ' ' ||
			temp[nb] == '#' || temp[nb] == '.' ||
			(temp[nb] >= '0' && temp[nb] <= '9'))
		nb++;
	while (nb-- >= 0)
		s++;
	return (s);
}

char	*ft_print_percent_with_percent(char *s, t_data *a)
{
	char	*temp_percent;
	int		nb_of_percent;
	int		i;

	nb_of_percent = 0;
	temp_percent = ft_strdup(s);
	while (temp_percent[nb_of_percent] == '%')
		nb_of_percent++;
	i = nb_of_percent / 2;
	while (i-- > 0)
	{
		ft_putchar('%');
		a->printed_char_counter++;
	}
	if (nb_of_percent % 2 == 0)
		i = 0;
	else
		i = 1;
	while (nb_of_percent > i)
	{
		nb_of_percent--;
		s++;
	}
	return (s);
}

void	ft_print_no_format_characters(t_data *a, char **temp)
{
	a->printed_char_counter++;
	ft_putchar(**temp);
	(*temp)++;
}
