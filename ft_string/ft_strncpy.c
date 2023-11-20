/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lporoshi <lporoshi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 16:16:23 by lporoshi          #+#    #+#             */
/*   Updated: 2023/11/20 19:28:18 by lporoshi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_strncpy(char *dst, char *src, size_t len)
{
	char	*start;

	start = dst;
	if (dst == NULL || src == NULL)
		return (NULL);
	while (*src != '\0' && len > 0)
	{
		*dst = *src;
		dst++;
		src++;
		len--;
	}
	*dst = '\0';
	return (start);
}
