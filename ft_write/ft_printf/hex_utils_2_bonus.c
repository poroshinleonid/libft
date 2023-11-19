/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hex_utils_2_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lporoshi <lporoshi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 18:11:56 by lporoshi          #+#    #+#             */
/*   Updated: 2023/10/26 18:54:36 by lporoshi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

char	*ft_itoha_lower_b(unsigned int n, t_flags flags)
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
	flags.zero = flags.zero;
	s = ft_calloc(i + 1, 1);
	if (!s)
		return (NULL);
	n = temp;
	i--;
	while (n)
	{
		s[i] = dig_to_hex_b(n % 16);
		n /= 16;
		i--;
	}
	return (s);
}

char	*ft_itoha_upper_b(unsigned int n, t_flags flags)
{
	char	*s;

	s = ft_itoha_lower_b(n, flags);
	if (!s)
		return (NULL);
	str_toupper_b(&s);
	return (s);
}

char	dig_to_hex_b(int d)
{
	if (d < 10)
		return (d + '0');
	else
		return (d - 10 + 'a');
}

void	ptr_to_hex_b(void *ptr, char *addr)
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
	while (byte_to_hex_2_b(byte + i) == '0' && byte_to_hex_1_b(byte + i) == '0')
		i--;
	if (byte_to_hex_2_b(byte + i) == '0')
		addr--;
	while (i >= 0)
	{
		*(addr++) = byte_to_hex_2_b(byte + i);
		*(addr++) = byte_to_hex_1_b(byte + i);
		i--;
	}
}

char	byte_to_hex_1_b(unsigned char *c)
{
	char	res;

	if ((*c % 16) < 10)
		res = (*c % 16) + '0';
	else
		res = (*c % 16) + 'a' - 10;
	return (res);
}
