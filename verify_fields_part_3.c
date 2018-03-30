/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verify_fields_part_3.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancardi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/30 20:54:32 by ancardi           #+#    #+#             */
/*   Updated: 2018/03/30 20:57:08 by ancardi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	ft_verify_fla_group2_array_part2(char **checker, char *array, t_data *a)
{
	char	*res;
	int		d;
	int		i;
	int		j;

	d = 0;
	j = 0;
	while (d <= 6)
	{
		i = 0;
		while (array[i] == checker[d][i])
			i++;
		if (i == 3)
			break ;
		d++;
	}
	i = 3;
	res = ft_strnew(2);
	while (checker[d][i] != '\0')
		res[j++] = checker[d][i++];
	a->fla = res;
}

void	ft_verify_fla_group2_array_part1(char *array, t_data *a)
{
	char	**checker;
	int		n;

	checker = (char **)malloc(sizeof(char *) * 7);
	checker[7] = NULL;
	n = -1;
	while (++n < 7)
		checker[n] = ft_strnew(6);
	checker[0] = ft_strcpy(checker[0], "111-#");
	checker[1] = ft_strcpy(checker[1], "110-#");
	checker[2] = ft_strcpy(checker[2], "0110#");
	checker[3] = ft_strcpy(checker[3], "010#");
	checker[4] = ft_strcpy(checker[4], "100-");
	checker[5] = ft_strcpy(checker[5], "101-");
	checker[6] = ft_strcpy(checker[6], "0010");
	ft_verify_fla_group2_array_part2(checker, array, a);
}

int		ft_verify_fla_group2(t_data *a, char c)
{
	char	*temp;
	char	*array;
	int		i;

	temp = a->fla;
	if ((ft_strchr(temp, '+') || ft_strchr(temp, ' ')) ||
		((c == 'u' || c == 'U') && ft_strchr(temp, '#')))
		return (0);
	i = 0;
	array = ft_strnew(3);
	ft_memset(array, '0', 3);
	while (temp[i])
	{
		if (temp[i] == '-')
			array[0] = '1';
		if (temp[i] == '#')
			array[1] = '1';
		if (temp[i] == '0')
			array[2] = '1';
		i++;
	}
	ft_verify_fla_group2_array_part1(array, a);
	return (1);
}

int		ft_verify_fla_group1(t_data *a)
{
	char	*temp;
	size_t	i;

	temp = a->fla;
	i = 0;
	while (temp[i] == '-')
		i++;
	if (ft_strlen(temp) == i)
	{
		a->fla = ft_strdup("-");
		return (1);
	}
	return (0);
}
