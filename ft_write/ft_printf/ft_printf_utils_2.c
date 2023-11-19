/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils_2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lporoshi <lporoshi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 17:31:08 by lporoshi          #+#    #+#             */
/*   Updated: 2023/10/26 18:16:34 by lporoshi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	str_toupper(char *s)
{
	while (*s)
	{
		*s = ft_toupper(*s);
		s++;
	}
}

char	dig_to_hex(int d)
{
	if (d < 10)
		return (d + '0');
	else
		return (d - 10 + 'a');
}

int	get_uint_len(unsigned int un)
{
	int	i;

	if (un == 0)
		return (1);
	i = 0;
	while (un)
	{
		un /= 10;
		i++;
	}
	return (i);
}

char	*ft_uitoa(unsigned int un)
{
	int		wlen;
	char	*w;
	char	*res;

	wlen = get_uint_len(un);
	w = (char *)calloc(wlen + 1, 1);
	if (un == 0)
	{
		w[0] = '0';
		return (w);
	}
	res = w;
	w += wlen - 1;
	while (un)
	{
		*(w--) = un % 10 + '0';
		un /= 10;
	}
	return (res);
}
