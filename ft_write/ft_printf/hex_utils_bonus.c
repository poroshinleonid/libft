/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hex_utils_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lporoshi <lporoshi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 16:12:01 by lporoshi          #+#    #+#             */
/*   Updated: 2023/10/26 18:09:15 by lporoshi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

static char	*add_0x_shift_1_b(char *s, int i)
{
	char	*temp;

	i = ft_strlen(s);
	temp = ft_calloc(i + 2, 1);
	if (!temp)
	{
		free(s);
		return (NULL);
	}
	ft_strncpy_b(temp + 1, s, i);
	free(s);
	return (temp);
}

static char	*add_0x_shift_2_b(char *s, int i)
{
	char	*temp;

	i = ft_strlen(s);
	temp = ft_calloc(i + 3, 1);
	if (!temp)
	{
		free(s);
		return (NULL);
	}
	ft_strncpy_b(temp + 2, s, i);
	free(s);
	return (temp);
}

char	*add_0x_b(char *s, unsigned int n, t_flags flags)
{
	char	*temp;
	int		i;

	if (!flags.sharp || n == 0)
		return (s);
	i = 0;
	while (s[i] == '0' || s[i] == ' ')
		i++;
	if (flags.dot || (!flags.dot && i == 0))
	{
		temp = add_0x_shift_2_b(s, i);
		if (!temp)
			return (NULL);
	}
	else if (i == 1)
	{
		temp = add_0x_shift_1_b(s, i);
		if (!temp)
			return (NULL);
	}
	else
		temp = s;
	temp[0] = '0';
	temp[1] = 'x';
	return (temp);
}

void	str_toupper_b(char **s)
{
	char	*ss;

	ss = *s;
	while (*ss)
	{
		*ss = ft_toupper(*ss);
		ss++;
	}
}

char	*pad_minw_and_0x_b(char *n_hexrepr, int n, t_flags flags)
{
	if (flags.dot || !flags.zero)
	{
		n_hexrepr = add_0x_b(n_hexrepr, n, flags);
		if (!n_hexrepr)
			return (NULL);
		n_hexrepr = pad_digit_minw_b(n_hexrepr, flags);
		if (!n_hexrepr)
			return (NULL);
	}
	else
	{
		n_hexrepr = pad_digit_minw_b(n_hexrepr, flags);
		if (!n_hexrepr)
			return (NULL);
		n_hexrepr = add_0x_b(n_hexrepr, n, flags);
		if (!n_hexrepr)
			return (NULL);
	}
	return (n_hexrepr);
}
