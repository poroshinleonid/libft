/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lporoshi <lporoshi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 16:50:36 by lporoshi          #+#    #+#             */
/*   Updated: 2023/11/19 14:03:26 by lporoshi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/************************************************
**THIS FUNCTION IS WRONG, MOULINETTE SAID IT!!!**
************************************************/
static int	ft_get_digit_len(int n)
{
	int	l;

	if (n == 0)
		return (0);
	l = 0;
	while (n)
	{
		n /= 10;
		l++;
	}
	return (l);
}

void	ft_putnbr_fd(int n, int fd)
{
	long	num;
	long	log;
	int		l;

	num = n;
	if (num < 0)
	{
		write(fd, "-", 1);
		num *= -1;
	}
	l = ft_get_digit_len(n);
	log = 1;
	while (l-- > 1)
		log *= 10;
	while (num)
	{
		ft_putchar_fd(num / log + '0', fd);
		num = num % log;
		log /= 10;
	}
	if (l == -1 || !(n % 10))
		ft_putchar_fd('0', fd);
}
