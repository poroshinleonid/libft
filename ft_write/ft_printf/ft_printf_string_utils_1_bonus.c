/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_string_utils_bonus_1.c                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lporoshi <lporoshi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 17:55:08 by lporoshi          #+#    #+#             */
/*   Updated: 2023/10/26 18:07:12 by lporoshi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

char	*get_s_minmaxed_b(char *s, t_flags flags)
{
	int		s_len;
	int		res_len;
	char	*res_s;

	s_len = ft_strlen(s);
	if (s_len >= flags.dot && flags.dot >= flags.minw)
		res_len = flags.dot;
	else if (flags.dot >= s_len && s_len >= flags.minw)
		res_len = s_len;
	else
		res_len = flags.minw;
	if (flags.minus)
		res_s = get_s_of_minw_leftpad_b(s, flags.minw);
	else
		res_s = get_s_of_minw_rightpad_b(s, flags.dot);
	if (!res_s)
		return (NULL);
	return (res_s);
}

char	*get_s_of_minw_rightpad_b(char *s, int minw)
{
	int		right_pad;
	char	*res_s;
	int		i;

	right_pad = minw - ft_strlen(s);
	if (right_pad > 0)
	{
		res_s = (char *)ft_calloc(minw + 1, 1);
		if (!res_s)
			return (NULL);
		ft_strncpy_b(res_s, s, minw - right_pad);
		i = minw - right_pad;
		while (i < minw)
			res_s[i++] = ' ';
		return (res_s);
	}
	res_s = ft_strdup(s);
	if (!res_s)
		return (NULL);
	return (res_s);
}

char	*get_s_of_minw_leftpad_b(char *s, int minw)
{
	int		left_pad;
	char	*res_s;
	int		i;

	left_pad = minw - ft_strlen(s);
	if (left_pad > 0)
	{
		res_s = (char *)ft_calloc(minw + 1, 1);
		if (!res_s)
			return (NULL);
		i = 0;
		while (i < left_pad)
			res_s[i++] = ' ';
		ft_strncpy_b(res_s + i, s, minw - left_pad);
		return (res_s);
	}
	res_s = ft_strdup(s);
	if (!res_s)
		return (NULL);
	return (res_s);
}

int	ft_max_b(int a, int b)
{
	if (a > b)
		return (a);
	return (b);
}

char	*ft_strncpy_b(char *dst, char *src, size_t n)
{
	char	*og_dst;

	og_dst = dst;
	while (n > 0)
	{
		*dst = *src;
		if ((*src) == '\0')
			return (og_dst);
		dst++;
		src++;
		n--;
	}
	*dst = '\0';
	return (og_dst);
}
