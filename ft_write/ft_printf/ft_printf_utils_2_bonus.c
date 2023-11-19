/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils_2_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lporoshi <lporoshi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 19:29:19 by lporoshi          #+#    #+#             */
/*   Updated: 2023/10/26 19:47:20 by lporoshi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

int	check_precision_edgecases_b(char *s, t_flags *flags)
{
	if (!ft_in_b(*s, DIGITS))
	{
		if (ft_in_b(*s, CONVS_L))
		{
			flags->dot = -2;
			return (1);
		}
		flags->dot = -1;
		return (1);
	}
	return (0);
}

int	check_precision_b(char *s, t_flags *flags)
{
	int	len;
	int	precision;

	precision = 0;
	len = 0;
	if (*s++ != '.')
		return (0);
	if (check_precision_edgecases_b(s, flags))
		return (0);
	while (ft_in_b(*s, DIGITS))
	{
		precision *= 10;
		precision += *s - '0';
		s++;
		len++;
	}
	if (!ft_in_b(*s, CONVS_L))
		return (-1);
	if (precision == 0)
		flags->dot = -2;
	else
		flags->dot = precision;
	return (len + 1);
}

int	check_conv_b(char *s, t_flags *flags)
{
	int	len;

	len = 0;
	flags->dot += 0;
	if (!ft_in_b(*s, CONVS_L))
	{
		return (-1);
	}
	return (0);
}

void	init_flags_b(t_flags *flags)
{
	flags->minus = 0;
	flags->zero = 0;
	flags->plus = 0;
	flags->blank = 0;
	flags->sharp = 0;
	flags->dot = 0;
	flags->minw = 0;
}

int	ft_in_b(char c, char *s)
{
	while (*s)
	{
		if (*s == c)
			return (1);
		else
			s++;
	}
	return (0);
}
