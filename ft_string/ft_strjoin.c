/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lporoshi <lporoshi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 15:29:26 by lporoshi          #+#    #+#             */
/*   Updated: 2023/11/19 18:39:08 by lporoshi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	i;
	char	*res;

	i = ft_strlen(s1) + ft_strlen(s2) + 1;
	res = (char *)malloc(sizeof(char) * i);
	if (!res)
		return (NULL);
	i = 0;
	while (*s1)
	{
		res[i] = s1[0];
		i++;
		s1++;
	}
	while (*s2)
	{
		res[i] = s2[0];
		i++;
		s2++;
	}
	res[i] = '\0';
	return (res);
}
