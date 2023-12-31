/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trusanov <trusanov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 13:56:59 by lporoshi          #+#    #+#             */
/*   Updated: 2023/12/11 14:30:51 by trusanov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	c_converted;

	if (!s)
		return (NULL);
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
