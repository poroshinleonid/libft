/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_dec_utils_4_bonus.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lporoshi <lporoshi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 18:20:50 by lporoshi          #+#    #+#             */
/*   Updated: 2023/10/26 19:47:02 by lporoshi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

int	get_uint_len_b(unsigned int un)
{
	int	i;

	if (un == 0)
		return (1);
	i = 0;
	while (un)
	{
		un /= 10;
		i++;
	}
	return (i);
}
