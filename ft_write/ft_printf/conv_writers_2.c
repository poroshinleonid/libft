/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_writers_2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lporoshi <lporoshi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 14:36:30 by lporoshi          #+#    #+#             */
/*   Updated: 2023/10/20 21:55:34 by lporoshi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	write_usd(va_list args)
{
	unsigned int	ui;
	char			*ui_strrepr;

	ui = va_arg(args, unsigned int);
	ui_strrepr = ft_uitoa(ui);
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

int	write_hxl(va_list args)
{
	char			*n_hexrepr;
	unsigned int	n;

	n = va_arg(args, unsigned int);
	if (n == 0)
	{
		if (write(1, "0", 1) == -1)
			return (-1);
		return (1);
	}
	n_hexrepr = ft_itoha_lower(n);
	if (!n_hexrepr)
		return (-1);
	n = ft_strlen(n_hexrepr);
	if (ft_putstr_fd(n_hexrepr, 1) == -1)
		n = -1;
	free(n_hexrepr);
	return (n);
}

int	write_hxu(va_list args)
{
	char			*n_hexrepr;
	unsigned int	n;

	n = va_arg(args, int);
	if (n == 0)
	{
		if (write(1, "0", 1) == -1)
			return (-1);
		return (1);
	}
	n_hexrepr = ft_itoha_upper(n);
	if (!n_hexrepr)
		return (-1);
	n = ft_strlen(n_hexrepr);
	if (ft_putstr_fd(n_hexrepr, 1) == -1)
		n = -1;
	free(n_hexrepr);
	return (n);
}

int	write_prc(void)
{
	if (write(1, "%", 1) != -1)
		return (1);
	else
		return (-1);
}
