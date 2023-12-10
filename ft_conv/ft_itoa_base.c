/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lporoshi <lporoshi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 19:12:50 by lporoshi          #+#    #+#             */
/*   Updated: 2023/12/10 15:32:18 by lporoshi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"
#include <stdbool.h>

static int	check_base(char *base)
{
	int	i;
	int	j;

	if (!base || !*base || !*(base + 1))
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
	return (FT_SUCCESS);
}

static char	*convert_itoa(char *base, long int num)
{
	bool	is_negative;
	int		i;
	int		base_len;
	char	rev_res[50];

	base_len = ft_strlen(base);
	is_negative = num < 0;
	if (is_negative)
		num *= -1;
	i = 0;
	if (num == 0)
		rev_res[i++] = base[0];
	while (num)
	{
		rev_res[i++] = base[num % base_len];
		num /= base_len;
	}
	if (is_negative)
		rev_res[i++] = '-';
	rev_res[i] = '\0';
	printf("^%s\n", rev_res);
	return (ft_strrev(rev_res));
}

char	*ft_itoa_base(char *base, int n)
{
	long int	num;
	char		*res;

	num = n;
	if (check_base(base) == FT_ERROR)
		return (NULL);
	res = convert_itoa(base, num);
	return (res);
}
