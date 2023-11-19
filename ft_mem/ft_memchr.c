/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lporoshi <lporoshi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 14:09:53 by lporoshi          #+#    #+#             */
/*   Updated: 2023/11/19 16:36:32 by lporoshi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	cc;
	unsigned char	*ss;

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
