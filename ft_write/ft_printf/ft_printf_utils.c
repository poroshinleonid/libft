/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lporoshi <lporoshi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 15:11:29 by lporoshi          #+#    #+#             */
/*   Updated: 2023/10/26 18:13:20 by lporoshi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	byte_to_hex_1(unsigned char *c)
{
	char	res;

	if ((*c % 16) < 10)
		res = (*c % 16) + '0';
	else
		res = (*c % 16) + 'a' - 10;
	return (res);
}

char	byte_to_hex_2(unsigned char *c)
{
	char	res;

	if ((*c >> 4) < 10)
		res = (*c >> 4) + '0';
	else
		res = (*c >> 4) + 'a' - 10;
	return (res);
}

void	ptr_to_hex(void *ptr, char *addr)
{
	unsigned char	*byte;
	int				i;

	if (!ptr)
	{
		*addr = '0';
		return ;
	}
	byte = (unsigned char *)(&ptr);
	i = 7;
	while (byte_to_hex_2(byte + i) == '0' && byte_to_hex_1(byte + i) == '0')
		i--;
	if (byte_to_hex_2(byte + i) == '0')
		addr--;
	while (i >= 0)
	{
		*(addr++) = byte_to_hex_2(byte + i);
		*(addr++) = byte_to_hex_1(byte + i);
		i--;
	}
}

char	*ft_itoha_lower(unsigned int n)
{
	char			*s;
	int				i;
	unsigned int	temp;

	i = 0;
	temp = n;
	while (n)
	{
		n /= 16;
		i++;
	}
	s = ft_calloc(i + 1, 1);
	if (!s)
		return (NULL);
	n = temp;
	i--;
	while (n)
	{
		s[i] = dig_to_hex(n % 16);
		n /= 16;
		i--;
	}
	return (s);
}

char	*ft_itoha_upper(unsigned int n)
{
	char	*s;

	s = ft_itoha_lower(n);
	if (!s)
		return (NULL);
	str_toupper(s);
	return (s);
}
