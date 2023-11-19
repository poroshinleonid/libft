/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lporoshi <lporoshi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 13:56:59 by lporoshi          #+#    #+#             */
/*   Updated: 2023/11/19 18:23:26 by lporoshi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	c_converted;

	c_converted = (char)c;
	while (1)
	{
		if (*s == c_converted)
			return ((char *)s);
		if (*((char *)s) == '\0')
			return (NULL);
		s++;
	}
}
