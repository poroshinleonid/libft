/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lporoshi <lporoshi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 13:10:59 by lporoshi          #+#    #+#             */
/*   Updated: 2023/11/19 16:36:07 by lporoshi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t	cur_offset;

	if (!dst || !src)
		return (NULL);
	cur_offset = 0;
	while (cur_offset < n)
	{
		((unsigned char *)dst)[cur_offset] = ((unsigned char *)src)[cur_offset];
		cur_offset++;
	}
	return (dst);
}
