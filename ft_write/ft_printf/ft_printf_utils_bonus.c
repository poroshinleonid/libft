/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lporoshi <lporoshi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 15:35:29 by lporoshi          #+#    #+#             */
/*   Updated: 2023/10/26 18:17:02 by lporoshi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

int	get_spec_len_b(int i, char *s)
{
	i = 0;
	s = NULL;
	return (0);
}

char	*get_res_s_b(char *s, t_flags flags)
{
	if (!flags.minw && !flags.dot)
		return (ft_strdup(s));
	else if (!flags.minw && flags.dot)
		return (crop_s_b(s, flags.dot));
	else if (!flags.minus && flags.minw && !flags.dot)
		return (get_s_of_minw_leftpad_b(s, flags.minw));
	else if (flags.minus && flags.minw && !flags.dot)
		return (get_s_of_minw_rightpad_b(s, flags.minw));
	else if (flags.minw && flags.dot)
		return (get_s_minmaxed_b(s, flags));
	else
		return (get_s_minmaxed_b(s, flags));
}

int	go_through_flags_b(char **s, t_flags *flags)
{
	int	spec_s_len;
	int	i;

	spec_s_len = 0;
	i = check_actual_flags_b(*s + spec_s_len, flags);
	spec_s_len += i;
	if (i == -1)
		return (-1);
	i = check_minw_b(*s + spec_s_len, flags);
	spec_s_len += i;
	if (i == -1)
		return (-1);
	i = check_precision_b(*s + spec_s_len, flags);
	spec_s_len += i;
	if (i == -1)
		return (-1);
	if (*(*s + spec_s_len) == '.')
	{
		spec_s_len++;
	}
	i = check_conv_b(*s + spec_s_len, flags);
	spec_s_len += i;
	if (i == -1)
		return (-1);
	return (spec_s_len);
}

int	check_actual_flags_b(char *s, t_flags *flags)
{
	int	len;

	len = 0;
	while (ft_in_b(*s, FLAGS_ONLY))
	{
		if (*s == '0')
			flags->zero = 1;
		else if (*s == '#')
			flags->sharp = 1;
		else if (*s == ' ')
			flags->blank = 1;
		else if (*s == '+')
			flags->plus = 1;
		else if (*s == '-')
			flags->minus = 1;
		else
			break ;
		len++;
		s++;
	}
	return (len);
}

int	check_minw_b(char *s, t_flags *flags)
{
	int	minw;
	int	len;

	minw = 0;
	len = 0;
	if (*s == '0')
		return (-1);
	if (!ft_in_b(*s, DIGITS))
		return (0);
	while (ft_in_b(*s, DIGITS))
	{
		minw *= 10;
		minw += *s - '0';
		s++;
		len++;
	}
	if (!ft_in_b(*s, CONVS_L) && *s != '.')
		return (-1);
	flags->minw = minw;
	return (len);
}
