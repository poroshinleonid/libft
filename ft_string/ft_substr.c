/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lporoshi <lporoshi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 15:16:05 by lporoshi          #+#    #+#             */
/*   Updated: 2024/01/22 17:13:07 by lporoshi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_handle_bigstart(char **res)
{
	*res = (char *)malloc(sizeof(char));
	if (!(*res))
		return (NULL);
	**res = '\0';
	return (*res);
}

char	*ft_substr(const char *s, int start, int len)
{
	int		maxlen;
	int		offset;
	char	*res;

	if (!s)
		return (NULL);
	if (start >= ft_strlen(s))
		return (ft_handle_bigstart(&res));
	maxlen = ft_strlen(s + start) + 1;
	if (len < maxlen - 1)
		maxlen = len + 1;
	res = (char *)malloc(maxlen);
	if (!res)
		return (NULL);
	offset = 0;
	while (offset < maxlen)
	{
		res[offset] = s[start + offset];
		offset++;
	}
	res[offset - 1] = '\0';
	return (res);
}
