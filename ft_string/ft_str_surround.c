/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_surround.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lporoshi <lporoshi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 16:22:19 by lporoshi          #+#    #+#             */
/*   Updated: 2023/12/15 17:20:18 by lporoshi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_str_surround(char **s, char surround_char)
{
	char	*res;
	int		len;

	if (!s || !(*s))
		return (NULL);
	len = ft_strlen(*s);
	if (len == -1)
		return (NULL);
	res = (char *)ft_calloc(len + 4, sizeof(char));
	if (res == NULL)
		return (NULL);
	res[0] = surround_char;
	if (ft_strncpy(res + 1, *s, len + 1) == NULL)
	{
		free(res);
		return (NULL);
	}
	res[len + 1] = surround_char;
	return (res);
}
