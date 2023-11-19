/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_dec_utils_bonus_2.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lporoshi <lporoshi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 14:07:48 by lporoshi          #+#    #+#             */
/*   Updated: 2023/10/26 18:15:48 by lporoshi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

char	*add_sign_b(char *s, t_flags flags, int i)
{
	if (i < 0)
		s = add_sign_minus_b(s, flags);
	else if (flags.plus)
		s = add_sign_plus_b(s, flags);
	else if (flags.blank)
		s = add_sign_blank_b(s, flags);
	return (s);
}

char	*get_d_minw_padded_b(char *s, t_flags flags, char pad_char)
{
	int		s_len;
	char	*res_s;

	s_len = ft_strlen(s);
	if (s_len >= flags.minw)
		return (s);
	if (flags.minus)
	{
		res_s = get_d_of_minw_rightpad_b(s, flags, pad_char);
		if (!res_s)
			return (NULL);
	}
	else
	{
		res_s = get_d_of_minw_leftpad_b(s, flags, pad_char);
		if (!res_s)
			return (NULL);
	}
	return (res_s);
}

char	*get_d_of_minw_rightpad_b(char *s, t_flags flags, char pad_char)
{
	int		right_pad;
	char	*res_s;
	int		i;

	right_pad = flags.minw - ft_strlen(s);
	if (right_pad > 0)
	{
		res_s = (char *)ft_calloc(flags.minw + 1, 1);
		if (!res_s)
		{
			free(s);
			s = NULL;
			return (NULL);
		}
		ft_strncpy_b(res_s, s, flags.minw - right_pad);
		i = flags.minw - right_pad;
		while (i < flags.minw)
			res_s[i++] = pad_char;
		free(s);
		s = NULL;
		return (res_s);
	}
	return (s);
}

char	*get_d_of_minw_leftpad_b(char *s, t_flags flags, char pad_char)
{
	int		left_pad;
	char	*res_s;
	int		i;

	left_pad = flags.minw - ft_strlen(s);
	if (left_pad > 0)
	{
		res_s = (char *)ft_calloc(flags.minw + 1, 1);
		if (!res_s)
		{
			free(s);
			s = NULL;
			return (NULL);
		}
		i = 0;
		while (i < left_pad)
			res_s[i++] = pad_char;
		ft_strncpy_b(res_s + i, s, flags.minw - left_pad);
		free(s);
		s = NULL;
		return (res_s);
	}
	return (s);
}

int	get_int_len_b(int number, t_flags flags)
{
	int	i;

	if (number == 0)
	{
		if (flags.dot == -2)
		{
			return (0);
		}
		else
			return (1);
	}
	i = 0;
	if (number < 0)
		number *= -1;
	while (number)
	{
		number /= 10;
		i++;
	}
	return (i);
}
