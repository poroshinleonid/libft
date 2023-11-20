/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lporoshi <lporoshi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 16:29:34 by lporoshi          #+#    #+#             */
/*   Updated: 2023/11/20 20:40:19 by lporoshi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static int	ft_get_digit_len(int n)
{
	int	l;

	if (n == 0)
		return (1);
	l = 0;
	while (n)
	{
		n /= 10;
		l++;
	}
	return (l);
}

static int	ft_itoa_edgecases(char **resptr, int n)
{
	if (n == 0)
	{
		*resptr = (char *)malloc(sizeof(char) * 2);
		if (!(*resptr))
			return (-1);
		(*resptr)[0] = '0';
		(*resptr)[1] = '\0';
		return (1);
	}
	if (n <= -2147483648)
	{
		*resptr = (char *)malloc(sizeof(char) * 12);
		if (!(*resptr))
			return (-1);
		ft_strncpy(*resptr, "-2147483648", 12);
		return (1);
	}
	return (0);
}

static int	ft_itoa_alloc(char **resptr, int n, int *wlen)
{
	int	i;

	i = ft_itoa_edgecases(resptr, n);
	if (i != 0)
		return (i);
	if (n < 0)
		*wlen += 1;
	*resptr = (char *)malloc(*wlen * sizeof(char));
	if (!*resptr)
		return (1);
	return (0);
}

char	*ft_itoa(int n)
{
	int		wlen;
	char	*w;
	char	*res;

	wlen = ft_get_digit_len(n) + 1;
	if (ft_itoa_alloc(&res, n, &wlen))
		return (res);
	w = res;
	w[wlen - 1] = '\0';
	if (n < 0)
		*(w) = '-';
	if (n < 0)
		n *= -1;
	w += wlen - 2;
	while (n)
	{
		*(w--) = n % 10 + '0';
		n /= 10;
	}
	return (res);
}
