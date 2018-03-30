/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verify_fields_part_2.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancardi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/30 20:50:07 by ancardi           #+#    #+#             */
/*   Updated: 2018/03/30 20:53:04 by ancardi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	ft_verify_fla_group3_array_part2(char **checker, char *array, t_data *a)
{
	char	*res;
	int		d;
	int		i;
	int		j;

	d = 0;
	j = 0;
	while (d <= 14)
	{
		i = 0;
		while (array[i] == checker[d][i])
			i++;
		if (i == 4)
			break ;
		d++;
	}
	i = 4;
	res = ft_strnew(3);
	while (checker[d][i] != '\0')
		res[j++] = checker[d][i++];
	a->fla = res;
}

void	ft_verify_fla_group3_array_part1(char *array, t_data *a)
{
	char	**checker;
	int		n;

	checker = (char **)malloc(sizeof(char *) * 16);
	checker[15] = NULL;
	n = -1;
	while (++n < 15)
		checker[n] = (char*)malloc(sizeof(char) * 8);
	checker[0] = ft_strcpy(checker[0], "1111+-");
	checker[1] = ft_strcpy(checker[1], "1101+-");
	checker[2] = ft_strcpy(checker[2], "1110+-");
	checker[3] = ft_strcpy(checker[3], "1100+-");
	checker[4] = ft_strcpy(checker[4], "0111+0");
	checker[5] = ft_strcpy(checker[5], "1011 -");
	checker[6] = ft_strcpy(checker[6], "0110+0");
	checker[7] = ft_strcpy(checker[7], "1010-");
	checker[8] = ft_strcpy(checker[8], "0011 0");
	checker[9] = ft_strcpy(checker[9], "0101+");
	checker[10] = ft_strcpy(checker[10], "1001 -");
	checker[11] = ft_strcpy(checker[11], "1000-");
	checker[12] = ft_strcpy(checker[12], "0100+");
	checker[13] = ft_strcpy(checker[13], "00100");
	checker[14] = ft_strcpy(checker[14], "0001 ");
	ft_verify_fla_group3_array_part2(checker, array, a);
}

int		ft_verify_fla_group3(t_data *a)
{
	char	*temp;
	char	*array;
	int		i;

	temp = a->fla;
	if (ft_strchr(temp, '#'))
		return (0);
	i = 0;
	array = ft_strnew(4);
	ft_memset(array, '0', 4);
	while (temp[i])
	{
		if (temp[i] == '-')
			array[0] = '1';
		if (temp[i] == '+')
			array[1] = '1';
		if (temp[i] == '0')
			array[2] = '1';
		if (temp[i] == ' ')
			array[3] = '1';
		i++;
	}
	ft_verify_fla_group3_array_part1(array, a);
	return (1);
}
