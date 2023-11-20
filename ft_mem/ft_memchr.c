/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lporoshi <lporoshi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 14:09:53 by lporoshi          #+#    #+#             */
/*   Updated: 2023/11/20 16:03:46 by lporoshi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	cc;
	unsigned char	*ss;

	if (!s)
		return (NULL);
	cc = (unsigned char)c;
	ss = (unsigned char *)s;
	while (n)
	{
		if (*ss == cc)
			return (ss);
		ss++;
		n--;
	}
	return (NULL);
}
