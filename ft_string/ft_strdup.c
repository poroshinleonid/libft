/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lporoshi <lporoshi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 15:42:35 by lporoshi          #+#    #+#             */
/*   Updated: 2023/11/20 16:00:38 by lporoshi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_strdup(const char *s1)
{
	char	*s2;
	int		offset;

	if (!s1)
		return (NULL);
	s2 = (char *)malloc(ft_strlen(s1) + 1);
	if (!s2)
		return (NULL);
	offset = 0;
	while (s1[offset])
	{
		s2[offset] = s1[offset];
		offset++;
	}
	s2[offset] = '\0';
	return (s2);
}
