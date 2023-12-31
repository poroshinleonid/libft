/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trusanov <trusanov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 14:00:52 by lporoshi          #+#    #+#             */
/*   Updated: 2023/12/11 14:31:16 by trusanov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t		offset;
	long int	last;
	char		c_converted;

	if (!s)
		return (NULL);
	offset = 0;
	last = -1;
	c_converted = (char)c;
	while (1)
	{
		if (s[offset] == c_converted)
			last = offset;
		if (s[offset] == '\0')
			break ;
		offset++;
	}
	if (last != -1)
		return ((char *)(s + last));
	return (NULL);
}
