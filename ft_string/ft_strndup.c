/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lporoshi <lporoshi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 19:30:07 by lporoshi          #+#    #+#             */
/*   Updated: 2023/11/20 19:32:34 by lporoshi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_strndup(char *s, size_t n)
{
	char	*copy;
	int		offset;

	if (!s)
		return (NULL);
	copy = (char *)malloc(ft_min(ft_strlen(s), n) + 1);
	if (!copy)
		return (NULL);
	offset = 0;
	while (s[offset] * n > 0)
	{
		copy[offset] = s[offset];
		offset++;
		n--;
	}
	copy[offset] = '\0';
	return (copy);
}
