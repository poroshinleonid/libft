/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lporoshi <lporoshi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 15:32:52 by lporoshi          #+#    #+#             */
/*   Updated: 2023/11/19 16:40:08 by lporoshi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static int	ft_isspace(const char c)
{
	if (c == ' ' || c == '\t' || c == '\v' \
	|| c == '\n' || c == '\f' || c == '\r')
		return (1);
	return (0);
}

static const char	*skip_sign(const char *str, int *sign)
{
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			*sign = -1;
		return (str + 1);
	}
	return (str);
}

int	ft_atoi(const char *str)
{
	long long	res;
	int			sign;

	res = 0;
	sign = 1;
	while (ft_isspace(*str) || *str == '0')
	{
		if (*(str++) == '0')
			break ;
	}
	str = skip_sign(str, &sign);
	while (ft_isdigit(*str))
	{
		res *= 10;
		res += *(str++) - '0';
		if (res >= 2147483647 && sign == 1)
			return (2147483647);
		if (sign == -1 && res * -1 <= -2147483647 - 1)
			return (-2147483647 - 1);
	}
	return ((int)res * sign);
}
