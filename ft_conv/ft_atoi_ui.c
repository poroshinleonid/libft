/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_ui.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lporoshi <lporoshi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 15:49:48 by lporoshi          #+#    #+#             */
/*   Updated: 2023/11/20 20:39:56 by lporoshi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int			ft_max(int a, int b);
int			ft_min(int a, int b);
int			ft_isdigit(int c);

static char	*skip_sign(char *str, int *sign)
{
	if (!str)
	{
		*sign = -2;
		return (NULL);
	}
	if (*str == '-')
	{
		if (ft_isdigit(*(str + 1)))
			*sign = -1;
		else
			*sign = -2;
		return (str + 1);
	}
	if (!ft_isdigit(*str))
		*sign = -2;
	return (str);
}

long int	ft_atoi_ui(char *str)
{
	long int	res;
	int			sign;

	res = 0;
	sign = 1;
	str = skip_sign(str, &sign);
	if (sign == -2)
		return (FT_LONG_ERR);
	while (ft_isdigit(*str))
	{
		res *= 10;
		res += *(str++) - '0';
		if (res > 2147483647 && sign == 1)
		{
			return (FT_LONG_ERR);
		}
		if (sign == -1 && res * -1 < -2147483647 - 1)
			return (FT_LONG_ERR);
	}
	if (*str != '\0')
		return (FT_LONG_ERR);
	res *= sign;
	res += 1;
	res += INT_MAX;
	return (res);
}
