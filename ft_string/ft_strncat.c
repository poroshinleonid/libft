/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lporoshi <lporoshi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 15:27:19 by lporoshi          #+#    #+#             */
/*   Updated: 2023/11/20 19:29:11 by lporoshi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_strncat(char *s1, char *s2, size_t n)
{
	char	*start;

	start = s1;
	if (s1 == NULL || s2 == NULL)
		return (NULL);
	while (s1)
		s1++;
	while (*s2 != '\0' && n)
	{
		*s1 = *s2;
		s1++;
		s2++;
		n--;
	}
	*s1 = '\0';
	return (start);
}
