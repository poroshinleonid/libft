/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_writers_2_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lporoshi <lporoshi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 15:41:14 by lporoshi          #+#    #+#             */
/*   Updated: 2023/10/26 18:17:21 by lporoshi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

int	write_usd_b(va_list args, t_flags flags)
{
	unsigned int	ui;
	char			*ui_strrepr;

	ui = va_arg(args, unsigned int);
	if (ui == 0 && flags.dot == -2)
		ui_strrepr = ft_strdup("");
	else
		ui_strrepr = ft_uitoa_b(ui, flags);
	ui_strrepr = pad_digit_precision_b(ui_strrepr, flags);
	ui_strrepr = pad_digit_minw_b(ui_strrepr, flags);
	if (!ui_strrepr)
		return (-1);
	if (ft_putstr_fd(ui_strrepr, 1) == -1)
	{
		free(ui_strrepr);
		return (-1);
	}
	ui = ft_strlen(ui_strrepr);
	free(ui_strrepr);
	return (ui);
}

char	*get_hex_basic_repr_b(int n, t_flags flags)
{
	char	*n_hexrepr;

	if (n == 0 && flags.dot == -2)
		n_hexrepr = ft_strdup("");
	else if (n == 0)
		n_hexrepr = ft_strdup("0");
	else
		n_hexrepr = ft_itoha_lower_b(n, flags);
	return (n_hexrepr);
}

int	write_hxl_b(va_list args, t_flags flags)
{
	char			*n_hexrepr;
	unsigned int	n;
	int				res;

	n = va_arg(args, unsigned int);
	n_hexrepr = get_hex_basic_repr_b(n, flags);
	if (!n_hexrepr)
		return (-1);
	n_hexrepr = pad_digit_precision_b(n_hexrepr, flags);
	if (!n_hexrepr)
		return (-1);
	n_hexrepr = pad_minw_and_0x_b(n_hexrepr, n, flags);
	if (!n_hexrepr)
		return (-1);
	res = ft_putstr_fd(n_hexrepr, 1);
	free(n_hexrepr);
	return (res);
}

int	write_hxu_b(va_list args, t_flags flags)
{
	char			*n_hexrepr;
	unsigned int	n;
	int				res;

	n = va_arg(args, unsigned int);
	n_hexrepr = get_hex_basic_repr_b(n, flags);
	if (!n_hexrepr)
		return (-1);
	n_hexrepr = pad_digit_precision_b(n_hexrepr, flags);
	if (!n_hexrepr)
		return (-1);
	n_hexrepr = pad_minw_and_0x_b(n_hexrepr, n, flags);
	if (!n_hexrepr)
		return (-1);
	str_toupper_b(&n_hexrepr);
	res = ft_putstr_fd(n_hexrepr, 1);
	free(n_hexrepr);
	return (res);
}

int	write_prc_b(t_flags flags)
{
	char	*s;
	int		res;

	s = ft_strdup("%");
	if (!s)
		return (-1);
	s = pad_digit_precision_b(s, flags);
	if (!s)
		return (-1);
	s = pad_percent_minw_b(s, flags);
	if (!s)
		return (-1);
	res = ft_putstr_fd(s, 1);
	free(s);
	return (res);
}
