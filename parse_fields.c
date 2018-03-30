/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_fields.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancardi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/30 16:42:20 by ancardi           #+#    #+#             */
/*   Updated: 2018/03/30 16:43:33 by ancardi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	ft_find_all_fields(t_data *a, char c)
{
	a->f_r = a->f_s;
	a->fla = ft_search_fla(a, c);
	a->wid_raw = ft_search_wid(a, c);
	a->pre_raw = ft_search_pre(a, c);
	a->len = ft_search_len(a, c);
}

char	*ft_search_fla(t_data *a, char c)
{
	char *ret;
	char *str;
	char *temp;

	temp = ft_strdup(a->f_s);
	if (temp == NULL || ft_strlen(temp) == 1)
		return (NULL);
	if ((ret = ft_find_fla(a, c)))
		a->f_r = ret;
	if (ret == NULL || (ft_strcmp(ret, temp) == 0))
		return (NULL);
	str = ft_cpy_to_char(temp, ret[0]);
	return (str);
}

char	*ft_search_wid(t_data *a, char c)
{
	char *ret;
	char *str;
	char *temp;

	temp = ft_strdup(a->f_r);
	if (temp == NULL || ft_strlen(temp) == 1)
		return (NULL);
	if ((ret = ft_find_wid(a, c)))
		a->f_r = ret;
	if (ft_strcmp(ret, temp) == 0)
		return (NULL);
	str = ft_cpy_to_char(temp, ret[0]);
	return (str);
}

char	*ft_search_pre(t_data *a, char c)
{
	char *ret;
	char *str;
	char *temp;

	temp = ft_strdup(a->f_r);
	if (temp == NULL || ft_strlen(temp) == 1)
		return (NULL);
	if ((ret = ft_find_pre(a, c)))
		a->f_r = ret;
	if (ft_strcmp(ret, temp) == 0)
		return (NULL);
	str = ft_cpy_to_char(temp, ret[0]);
	return (str);
}

char	*ft_search_len(t_data *a, char c)
{
	char *ret;
	char *str;
	char *temp;

	temp = ft_strdup(a->f_r);
	if (temp == NULL || ft_strlen(temp) == 1)
		return (NULL);
	if ((ret = ft_find_len(a, c)))
		a->f_r = ret;
	if (ft_strcmp(ret, temp) == 0)
		return (NULL);
	str = ft_cpy_to_char(temp, ret[0]);
	return (str);
}
