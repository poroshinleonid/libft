/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lporoshi <lporoshi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 13:01:34 by lporoshi          #+#    #+#             */
/*   Updated: 2023/11/20 16:05:18 by lporoshi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*ptr;
	unsigned char	data;

	if (!b)
		return (NULL);
	ptr = (unsigned char *)b;
	data = (unsigned char)c;
	while (len)
	{
		*ptr++ = data;
		len--;
	}
	return (b);
}
