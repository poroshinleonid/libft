/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lporoshi <lporoshi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 15:36:51 by lporoshi          #+#    #+#             */
/*   Updated: 2023/11/20 16:03:37 by lporoshi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	unsigned char	*ptr;
	int				offset;
	int				len;

	len = count * size;
	ptr = (unsigned char *)malloc(len);
	if (!ptr)
		return (NULL);
	offset = 0;
	while (offset < len)
		ptr[offset++] = 0;
	return ((void *)ptr);
}
