/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trusanov <trusanov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 13:16:11 by lporoshi          #+#    #+#             */
/*   Updated: 2023/12/11 14:31:16 by trusanov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	int			offset;
	long long	llen;

	if (!dst || !src)
		return (NULL);
	llen = (long long)len;
	if (dst == src || !llen)
		return (dst);
	if (dst - src < llen && dst > src)
	{
		while (llen)
		{
			((unsigned char *)dst)[llen - 1] = ((unsigned char *)src)[llen - 1];
			llen--;
		}
		return (dst);
	}
	offset = 0;
	while (llen)
	{
		((unsigned char *)dst)[offset] = ((unsigned char *)src)[offset];
		llen--;
		offset++;
	}
	return (dst);
}
