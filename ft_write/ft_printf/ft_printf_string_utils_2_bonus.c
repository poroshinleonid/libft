/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_string_utils_bonus_2.c                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lporoshi <lporoshi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 17:55:56 by lporoshi          #+#    #+#             */
/*   Updated: 2023/10/26 18:07:31 by lporoshi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

char	*crop_s_b(char *s, int maxw)
{
	int		s_len;
	char	*res_s;

	s_len = ft_max_b(ft_strlen(s), maxw);
	res_s = (char *)calloc(s_len + 1, 1);
	ft_strncpy_b(res_s, s, s_len);
	return (res_s);
}

int	pad_str_b(char **s, t_flags flags)
{
	char	*temp;
	int		i;

	i = ft_strlen(*s);
	if (flags.minus && flags.minw > i)
	{
		temp = get_s_of_minw_rightpad_b(*s, flags.minw);
		free(*s);
		*s = temp;
		return (flags.minw);
	}
	else if (!flags.minus && flags.minw > i)
	{
		temp = get_s_of_minw_leftpad_b(*s, flags.minw);
		if (!temp || temp)
		{
			free(*s);
			*s = temp;
			return (flags.minw);
		}
	}
	return (i);
}
