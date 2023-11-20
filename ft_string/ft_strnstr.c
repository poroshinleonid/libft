/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lporoshi <lporoshi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 15:30:56 by lporoshi          #+#    #+#             */
/*   Updated: 2023/11/20 16:24:28 by lporoshi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static int	ft_strncmp_zeroed(const char *s1, const char *s2, size_t n)
{
	unsigned char	*ss1;
	unsigned char	*ss2;

	ss1 = (unsigned char *)s1;
	ss2 = (unsigned char *)s2;
	while (n)
	{
		if (*ss1 == *ss2 && *ss1 != '\0')
		{
			ss1++;
			ss2++;
		}
		else if (*ss2 == '\0')
			return (0);
		else
			return (*ss1 - *ss2);
		n--;
	}
	return (0);
}

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	hof;
	size_t	needle_len;
	size_t	haystack_len;

	if (!haystack || !needle)
		return (NULL);
	haystack_len = ft_strlen(haystack);
	needle_len = ft_strlen(needle);
	if (needle_len == 0 || *needle == '\0')
		return ((char *)haystack);
	if (needle_len > len || needle_len > haystack_len)
		return (NULL);
	hof = 0;
	while (hof + needle_len <= len && haystack[hof] != '\0')
	{
		if (haystack[hof] == needle[0] && \
		!ft_strncmp_zeroed(haystack + hof, needle, needle_len + 1))
			return ((char *)(haystack + hof));
		hof++;
	}
	return (NULL);
}
