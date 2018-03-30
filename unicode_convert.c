/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unicode_convert.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancardi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/30 20:34:17 by ancardi           #+#    #+#             */
/*   Updated: 2018/03/30 20:41:29 by ancardi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	ft_unicode_convert_65536_to_1114111(unsigned char octet,
		unsigned int nb, unsigned int m3)
{
	unsigned char o4;
	unsigned char o3;
	unsigned char o2;
	unsigned char o1;

	o4 = (nb << 26) >> 26;
	o3 = ((nb >> 6) << 26) >> 26;
	o2 = ((nb >> 12) << 26) >> 26;
	o1 = ((nb >> 18) << 29) >> 29;
	octet = (m3 >> 24) | o1;
	write(1, &octet, 1);
	octet = ((m3 << 8) >> 24) | o2;
	write(1, &octet, 1);
	octet = ((m3 << 16) >> 24) | o3;
	write(1, &octet, 1);
	octet = ((m3 << 24) >> 24) | o4;
	write(1, &octet, 1);
}

void	ft_unicode_convert_2048_to_65535(unsigned char octet,
		unsigned int nb, unsigned int m2)
{
	unsigned char o3;
	unsigned char o2;
	unsigned char o1;

	o3 = (nb << 26) >> 26;
	o2 = ((nb >> 6) << 26) >> 26;
	o1 = ((nb >> 12) << 28) >> 28;
	octet = (m2 >> 16) | o1;
	write(1, &octet, 1);
	octet = ((m2 << 16) >> 24) | o2;
	write(1, &octet, 1);
	octet = ((m2 << 24) >> 24) | o3;
	write(1, &octet, 1);
}

void	ft_unicode_convert_128_to_2047(unsigned char octet,
		unsigned int nb, unsigned int m1)
{
	unsigned char o2;
	unsigned char o1;

	o2 = (nb << 26) >> 26;
	o1 = ((nb >> 6) << 27) >> 27;
	octet = (m1 >> 8) | o1;
	write(1, &octet, 1);
	octet = ((m1 << 24) >> 24) | o2;
	write(1, &octet, 1);
}

void	ft_unicode_convert(unsigned int nb)
{
	unsigned int	m1;
	unsigned int	m2;
	unsigned int	m3;
	unsigned char	octet;

	m1 = 49280;
	m2 = 14712960;
	m3 = 4034953344;
	octet = '\0';
	if (nb <= 127 || (nb <= 255 && MB_CUR_MAX == 1))
		ft_putchar(nb);
	else if (nb >= 128 && nb <= 2047)
		ft_unicode_convert_128_to_2047(octet, nb, m1);
	else if (nb >= 2048 && nb <= 65535)
		ft_unicode_convert_2048_to_65535(octet, nb, m2);
	else if (nb >= 65536 && nb <= 1114111)
		ft_unicode_convert_65536_to_1114111(octet, nb, m3);
}
