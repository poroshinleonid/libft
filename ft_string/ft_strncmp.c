/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trusanov <trusanov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 14:05:17 by lporoshi          #+#    #+#             */
/*   Updated: 2023/12/11 14:31:16 by trusanov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned char	*ss1;
	unsigned char	*ss2;

	if (!s1 || !s2)
		return (FT_ERROR);
	ss1 = (unsigned char *)s1;
	ss2 = (unsigned char *)s2;
	while (n)
	{
		if (*ss1 == *ss2 && *ss1 != '\0')
		{
			ss1++;
			ss2++;
		}
		else
			return (*ss1 - *ss2);
		n--;
	}
	return (0);
}
