/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_writers_1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lporoshi <lporoshi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 14:16:17 by lporoshi          #+#    #+#             */
/*   Updated: 2023/10/26 12:09:27 by lporoshi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	write_chr(va_list args)
{
	char	c;

	c = va_arg(args, int);
	if (write(1, &c, 1) == -1)
		return (-1);
	return (1);
}

int	write_str(va_list args)
{
	char	*s;

	s = va_arg(args, char *);
	if (!s)
		return (ft_putstr_fd("(null)", 1));
	return (ft_putstr_fd(s, 1));
}

int	write_ptr(va_list args)
{
	char	*addr;
	void	*ptr;
	int		res;

	addr = (char *)ft_calloc(1, 20);
	if (!addr)
		return (-1);
	ptr = va_arg(args, void *);
	ptr_to_hex(ptr, addr + 2);
	addr[0] = '0';
	addr[1] = 'x';
	res = ft_strlen(addr);
	if (ft_putstr_fd(addr, 1) == -1)
		res = -1;
	free(addr);
	return (res);
}

int	write_dec(va_list args)
{
	char	*d_strrepr;
	int		d;

	d = va_arg(args, int);
	d_strrepr = ft_itoa(d);
	if (!d_strrepr)
		return (-1);
	d = ft_putstr_fd(d_strrepr, 1);
	if (d == -1)
	{
		free(d_strrepr);
		return (-1);
	}
	free(d_strrepr);
	return (d);
}

int	write_int(va_list args)
{
	return (write_dec(args));
}
