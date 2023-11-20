/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lporoshi <lporoshi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 16:21:50 by lporoshi          #+#    #+#             */
/*   Updated: 2023/11/20 20:39:45 by lporoshi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static int	ft_check_input(char *str, char *base)
{
	int	i;
	int	j;

	if (!str || !base || !*base || !*(base + 1))
		return (FT_ERROR);
	i = 0;
	while (base[i])
	{
		j = i + 1;
		while (base[j])
		{
			if (base[i] == base[j] || base[i] == '+' || base[j] == '-' || \
			base[j] == ' ' || base[j] == '\t' || base[j] == '\n' \
			|| base[j] == '\v' || base[j] == '\r' || base[j] == '\f')
				return (FT_ERROR);
			j++;
		}
		i++;
	}
	i = 0;
	while (str[i])
		if (!ft_in(str[i], base))
			return (FT_ERROR);
	return (FT_SUCCESS);
}

static char	*ft_skip_whitespaces(char *str)
{
	while (*str == '\t' || *str == '\n' \
		|| *str == ' ' || *str == '\v' || *str == '\r'\
		|| *str == '\f')
		str++;
	return (str);
}

static char	*ft_setsign(char *str, char *base, int *sign)
{
	if (*str == '-')
	{
		*sign *= -1;
		str++;
	}
	if (*str != '\0' && !ft_in(*str, base))
		*sign = -2;
	return (str);
}

static long	compose_number(char *str, char *base, int sign)
{
	long int	result;
	int			baselen;
	int			i;

	result = 0;
	baselen = 0;
	while (base[baselen])
		baselen++;
	while (*str)
	{
		if (!ft_in(*str, base))
			return (FT_LONG_ERR);
		i = 0;
		while (i < baselen && *str != base[i])
			i++;
		if (i == baselen)
			break ;
		else
		{
			result *= baselen;
			result += i * sign;
		}
		str++;
	}
	return (result);
}

long int	ft_atoi_base(char *str, char *base)
{
	int			sign;
	long int	number;

	if (ft_check_input(str, base) == FT_ERROR)
		return (FT_ERROR);
	sign = 1;
	number = 0;
	str = ft_skip_whitespaces(str);
	str = ft_setsign(str, base, &sign);
	if (sign == -2)
		return (FT_LONG_ERR);
	number = compose_number(str, base, sign);
	return (number);
}
