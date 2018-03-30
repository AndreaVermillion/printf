/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_fields.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancardi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/30 16:15:18 by ancardi           #+#    #+#             */
/*   Updated: 2018/03/30 20:28:44 by ancardi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	ft_find_group(t_data *a)
{
	if (a->spe == 's' || a->spe == 'S' ||
		a->spe == 'c' || a->spe == 'C' || a->spe == 'p')
		a->grp = 1;
	else if (a->spe == 'o' || a->spe == 'O' ||
		a->spe == 'x' || a->spe == 'X' ||
		a->spe == 'u' || a->spe == 'U')
		a->grp = 2;
	else if (a->spe == 'd' || a->spe == 'D' || a->spe == 'i')
		a->grp = 3;
}

int		is_conversion(char x)
{
	if (x == 's' || x == 'S' || x == 'd' || x == 'D' || x == 'i' ||
		x == 'o' || x == 'O' || x == 'u' || x == 'U' || x == 'x' ||
		x == 'X' || x == 'c' || x == 'C' || x == 'p')
		return (1);
	return (0);
}

int		check_modifier(t_data *a, char *s, int i, int len)
{
	if (is_conversion(*(s + i)))
		a->spe = *(s + i);
	else if (((*(s + i) == 'h') || (*(s + i) == 'l')) && (i + 1 < len))
	{
		i++;
		if (is_conversion(*(s + i)))
			a->spe = *(s + i);
	}
	else
	{
		a->wrong_type = *(s + i);
		return (-1);
	}
	return (i);
}

char	*ft_find_spe(char *s, t_data *a, int i)
{
	int	len;

	a->spe = '0';
	len = (int)ft_strlen(s);
	while (++i < len)
	{
		if (IS_LETTER(*(s + i)))
		{
			if (IS_MODIFIER(*(s + i)) && (i + 1 < len))
			{
				i++;
				if ((i = check_modifier(a, s, i, len)) == -1)
					return (NULL);
			}
			else if (is_conversion(*(s + i)))
				a->spe = *(s + i);
			else
			{
				a->wrong_type = *(s + i);
				return (NULL);
			}
			return (s + i);
		}
	}
	return (NULL);
}
