/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lporoshi <lporoshi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 14:15:03 by lporoshi          #+#    #+#             */
/*   Updated: 2023/11/20 16:04:37 by lporoshi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*b1;
	unsigned char	*b2;

	if (!s1 || !s2)
		return (FT_ERROR);
	b1 = (unsigned char *)s1;
	b2 = (unsigned char *)s2;
	while (n)
	{
		if (*b1 != *b2)
			return (*b1 - *b2);
		b1++;
		b2++;
		n--;
	}
	return (0);
}
