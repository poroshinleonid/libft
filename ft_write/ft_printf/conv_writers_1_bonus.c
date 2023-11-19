/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_writers_1_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lporoshi <lporoshi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 15:40:35 by lporoshi          #+#    #+#             */
/*   Updated: 2023/10/29 12:23:35 by lporoshi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

int	write_chr_b(va_list args, t_flags flags)
{
	char	*s;
	char	c;
	int		res;

	c = va_arg(args, int);
	if (!flags.minw)
		return (write(1, &c, 1));
	s = (char *)ft_calloc(flags.minw + 1, 1);
	if (!s)
		return (-1);
	ft_memset((void *)s, ' ', flags.minw);
	if (flags.minus && c)
		s[0] = c;
	else
		s[flags.minw - 1] = c;
	if (c)
		res = ft_putstr_fd(s, 1);
	else if (flags.minus)
		res = ft_putchar_fd(c, 1) + ft_putstr_fd(s, 1);
	else
		res = ft_putstr_fd(s, 1) + ft_putchar_fd(c, 1);
	free(s);
	return (res);
}

int	write_str_b(va_list args, t_flags flags)
{
	char	*s;
	char	*res_s;
	int		res_i;

	s = va_arg(args, char *);
	if (!s)
		res_s = ft_strdup("(null)");
	else
		res_s = ft_strdup(s);
	if (!res_s)
		return (-1);
	res_s = crop_strrepr_b(res_s, flags.dot);
	if (!res_s)
		return (-1);
	res_s = pad_strrepr_b(res_s, flags);
	if (!res_s)
		return (-1);
	res_i = ft_putstr_fd(res_s, 1);
	free(res_s);
	return (res_i);
}

int	write_ptr_b(va_list args, t_flags flags)
{
	char	*addr;
	void	*ptr;
	int		res;

	addr = (char *)ft_calloc(1, 20);
	if (!addr)
		return (-1);
	ptr = va_arg(args, void *);
	ptr_to_hex_b(ptr, addr + 2);
	addr[0] = '0';
	addr[1] = 'x';
	res = pad_str_b(&addr, flags);
	if (addr == NULL)
		return (-1);
	if (ft_putstr_fd(addr, 1) == -1)
		res = -1;
	free(addr);
	return (res);
}

int	write_dec_b(va_list args, t_flags flags)
{
	char	*d_strrepr;
	int		d;

	d = va_arg(args, int);
	d_strrepr = ft_itoa_w_flags_b(d, flags);
	if (!d_strrepr)
		return (-1);
	d = ft_putstr_fd(d_strrepr, 1);
	if (d == -1)
	{
		free(d_strrepr);
		return (d);
	}
	free(d_strrepr);
	return (d);
}

int	write_int_b(va_list args, t_flags flags)
{
	return (write_dec_b(args, flags));
}
