/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_dec_utils_2_bonus.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lporoshi <lporoshi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 14:36:51 by lporoshi          #+#    #+#             */
/*   Updated: 2023/10/26 18:20:47 by lporoshi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

char	*add_sign_minus_b(char *s, t_flags flags)
{
	char	*temp;
	int		s_len;

	s_len = ft_strlen(s);
	if (s_len == flags.minw && flags.zero && s[0] == '0' && s[1] && !flags.dot)
	{
		s[0] = '-';
		return (s);
	}
	temp = (char *)ft_calloc(s_len + 2, 1);
	if (!temp)
	{
		free(s);
		return (NULL);
	}
	temp[0] = '-';
	ft_strncpy_b(temp + 1, s, s_len);
	free(s);
	return (temp);
}

char	*add_sign_plus_b(char *s, t_flags flags)
{
	char	*temp;
	int		s_len;

	s_len = ft_strlen(s);
	if (s_len == flags.minw && flags.zero && s[0] == '0' && s[1] && !flags.dot)
	{
		s[0] = '+';
		return (s);
	}
	temp = (char *)ft_calloc(s_len + 2, 1);
	if (!temp)
	{
		free(s);
		return (NULL);
	}
	temp[0] = '+';
	ft_strncpy_b(temp + 1, s, s_len);
	free(s);
	return (temp);
}

char	*add_sign_blank_b(char *s, t_flags flags)
{
	char	*temp;
	int		s_len;

	s_len = ft_strlen(s);
	if (s_len == flags.minw && flags.zero && s[0] == '0' && s[1] && !flags.dot)
	{
		s[0] = ' ';
		return (s);
	}
	temp = (char *)ft_calloc(s_len + 2, 1);
	if (!temp)
	{
		free(s);
		return (NULL);
	}
	temp[0] = ' ';
	ft_strncpy_b(temp + 1, s, s_len);
	free(s);
	return (temp);
}

char	*ft_itoa_pad_and_sign_b(char *res_str, t_flags flags, int i)
{
	if (flags.zero && !flags.dot)
	{
		res_str = pad_digit_minw_b(res_str, flags);
		if (!res_str)
			return (NULL);
		res_str = add_sign_b(res_str, flags, i);
		if (!res_str)
			return (NULL);
	}
	else
	{
		res_str = add_sign_b(res_str, flags, i);
		if (!res_str)
			return (NULL);
		res_str = pad_digit_minw_b(res_str, flags);
		if (!res_str)
			return (NULL);
	}
	return (res_str);
}

char	*ft_uitoa_b(unsigned int un, t_flags flags)
{
	int		wlen;
	char	*w;
	char	*res;

	if (un == 0 && flags.dot == -2)
	{
		res = ft_strdup("");
		return (res);
	}
	wlen = get_uint_len_b(un);
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
