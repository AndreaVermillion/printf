/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_functions_2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancardi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/30 16:32:08 by ancardi           #+#    #+#             */
/*   Updated: 2018/03/30 16:33:08 by ancardi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	ft_putstr(char const *s)
{
	char	*str;
	int		i;

	if (s == NULL)
		return ;
	i = 0;
	str = (char*)s;
	while (str[i] != '\0')
	{
		ft_putchar(str[i]);
		i++;
	}
}

char	*ft_strchr(const char *s, int c)
{
	size_t	len;
	size_t	i;

	i = 0;
	len = ft_strlen(s) + 1;
	while (i < len)
	{
		if (*(s + i) == (char)c)
			return ((char *)s + i);
		i++;
	}
	return (NULL);
}

int		ft_strcmp(const char *dst, const char *src)
{
	int				diff;
	int				i;
	unsigned char	*d;
	unsigned char	*s;

	diff = 0;
	i = 0;
	d = (unsigned char*)dst;
	s = (unsigned char*)src;
	while (d[i] || s[i])
	{
		diff = d[i] - s[i];
		if (diff != 0)
			return (diff);
		i++;
	}
	return (d[i] - s[i]);
}

char	*ft_strcpy(char *dst, const char *src)
{
	int	i;

	i = 0;
	while (src[i] != '\0')
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}

char	*ft_strdup(const char *s1)
{
	unsigned	i;
	size_t		len;
	char		*s2;

	len = ft_strlen(s1);
	if (!(s2 = (char*)malloc(sizeof(*s2) * len + 1)))
		return (NULL);
	i = 0;
	while (i < len)
	{
		s2[i] = s1[i];
		i++;
	}
	s2[i] = '\0';
	return (s2);
}
