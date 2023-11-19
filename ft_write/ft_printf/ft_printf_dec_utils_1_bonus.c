/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_dec_utils_1_bonus.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lporoshi <lporoshi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 19:41:58 by lporoshi          #+#    #+#             */
/*   Updated: 2023/10/26 18:20:40 by lporoshi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

char	*ft_itoa_w_flags_b(int i, t_flags flags)
{
	char	*res_str;

	res_str = ft_itoa_no_sign_b(i, flags);
	if (!res_str)
		return (NULL);
	res_str = pad_digit_precision_b(res_str, flags);
	if (!res_str)
		return (NULL);
	res_str = ft_itoa_pad_and_sign_b(res_str, flags, i);
	if (!res_str)
		return (NULL);
	return (res_str);
}

char	*ft_itoa_no_sign_b(int i, t_flags flags)
{
	int		wlen;
	char	*w;
	char	*res;

	if (i == INT_MIN)
		return (ft_strdup("2147483648"));
	wlen = get_int_len_b(i, flags);
	if (wlen == 0)
		return (ft_strdup(""));
	if (i == 0)
		return (ft_strdup("0"));
	w = (char *)ft_calloc(wlen + 1, 1);
	if (!w)
		return (NULL);
	res = w;
	if (i < 0)
		i *= -1;
	w += wlen - 1;
	while (i)
	{
		*(w--) = i % 10 + '0';
		i /= 10;
	}
	return (res);
}

char	*pad_digit_precision_b(char *s, t_flags flags)
{
	int		left_pad;
	char	*res_s;
	int		i;

	if (flags.dot <= 0)
		return (s);
	left_pad = flags.dot - ft_strlen(s);
	if (left_pad > 0)
	{
		res_s = (char *)ft_calloc(flags.dot + 1, 1);
		if (!res_s)
		{
			free(s);
			return (NULL);
		}
		i = 0;
		while (i < left_pad)
		{
			res_s[i++] = '0';
		}
		ft_strncpy_b(res_s + i, s, flags.dot - left_pad);
		free(s);
		return (res_s);
	}
	return (s);
}

char	*pad_digit_minw_b(char *s, t_flags flags)
{
	int		res_len;
	char	pad_char;

	if (!s)
		return (s);
	res_len = ft_strlen(s);
	if (flags.minw > res_len)
	{
		if (!flags.dot && flags.zero)
			pad_char = '0';
		else
			pad_char = ' ';
		s = get_d_minw_padded_b(s, flags, pad_char);
		if (!s)
			return (NULL);
	}
	return (s);
}

char	*pad_percent_minw_b(char *s, t_flags flags)
{
	int		res_len;
	char	pad_char;

	res_len = ft_strlen(s);
	if (flags.minw > res_len)
	{
		if (flags.zero)
			pad_char = ' ';
		else
			pad_char = ' ';
		s = get_d_minw_padded_b(s, flags, pad_char);
	}
	return (s);
}
