/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   width_utils_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lporoshi <lporoshi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 19:27:58 by lporoshi          #+#    #+#             */
/*   Updated: 2023/11/20 20:52:13 by lporoshi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"
#include "../../libft.h"

char	*crop_strrepr_b(char *s, int maxw)
{
	int		s_len;
	char	*temp;

	if (maxw < 0)
	{
		free(s);
		s = ft_strdup("");
		return (s);
	}
	s_len = ft_strlen(s);
	if (maxw == 0 || s_len <= maxw)
		return (s);
	temp = s;
	s = (char *)ft_calloc(maxw + 1, 1);
	if (!s)
	{
		free(temp);
		return (NULL);
	}
	ft_strncpy_b(s, temp, maxw);
	free(temp);
	return (s);
}

char	*pad_strrepr_b(char *s, t_flags flags)
{
	int	len;

	len = ft_strlen(s);
	if (len < flags.minw && flags.minus)
		return (pad_right_b(s, flags));
	else if (len < flags.minw && !flags.minus)
		return (pad_left_b(s, flags));
	return (s);
}

char	*pad_left_b(char *s, t_flags flags)
{
	char	pad_char;
	int		s_len;
	char	*temp;

	s_len = ft_strlen(s);
	if (flags.zero)
		pad_char = '0';
	else
		pad_char = ' ';
	temp = s;
	s = (char *)calloc(flags.minw + 1, 1);
	if (!s)
	{
		free(temp);
		return (NULL);
	}
	ft_strncpy_b(s + flags.minw - s_len, temp, s_len);
	ft_memset((void *)s, pad_char, flags.minw - s_len);
	free(temp);
	return (s);
}

char	*pad_right_b(char *s, t_flags flags)
{
	char	pad_char;
	int		s_len;
	char	*temp;

	s_len = ft_strlen(s);
	if (flags.zero)
		pad_char = '0';
	else
		pad_char = ' ';
	temp = s;
	s = (char *)calloc(flags.minw + 1, 1);
	if (!s)
	{
		free(temp);
		return (NULL);
	}
	ft_strncpy_b(s, temp, s_len);
	ft_memset((void *)s + s_len, pad_char, flags.minw - s_len);
	free(temp);
	return (s);
}
