/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_surround.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lporoshi <lporoshi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 16:22:19 by lporoshi          #+#    #+#             */
/*   Updated: 2023/12/15 16:48:58 by lporoshi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_str_surround(char **s, char surround_char)
{
	char	*res;
	int		len;

	if (!s || !(*s))
		return (FT_ERROR);
	len = ft_strlen(*s);
	if (len == -1)
		return (FT_ERROR);
	res = ft_calloc(len + 3, sizeof(char));
	if (res == NULL)
		return (FT_ERROR);
	res[0] = surround_char;
	if (ft_strncpy(res + 1, *s, len + 1) == NULL)
	{
		free(res);
		return (FT_ERROR);
	}
	res[len + 1] = surround_char;
	free(*s);
	*s = res;
	return (FT_SUCCESS);
}
