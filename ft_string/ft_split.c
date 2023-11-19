/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lporoshi <lporoshi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 20:59:21 by lporoshi          #+#    #+#             */
/*   Updated: 2023/11/19 18:23:29 by lporoshi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static int	ft_count_words(char const *s, char c)
{
	int	wc;
	int	inside;

	wc = 0;
	inside = 0;
	while (*s == c)
		s++;
	while (*s)
	{
		if (inside && *s == c)
		{
			inside = 0;
			continue ;
		}
		if (!inside && *s != c)
		{
			inside = 1;
			wc += 1;
		}
		s++;
	}
	return (wc);
}

static char	**ft_free_arr(char **arr, int size)
{
	int	i;

	i = 0;
	if (!arr)
		return (NULL);
	while (i <= size)
	{
		if (arr[i])
			free(arr[i]);
		i++;
	}
	free(arr);
	return (NULL);
}

static char	*ft_copy_word(char *dst, char *s, char c)
{
	while (*s && *s != c)
	{
		*dst = *s;
		dst++;
		s++;
	}
	*dst = '\0';
	return (s);
}

static char	**ft_allocate_words(const char *s, char c, int wc)
{
	char	**arr;
	int		curword;
	int		i;

	arr = (char **)malloc(sizeof(char *) * (wc + 1));
	if (!arr)
		return (NULL);
	curword = 0;
	while (curword < wc)
	{
		i = 0;
		while (*s == c)
			s++;
		while (s[i] && s[i] != c)
			i++;
		arr[curword] = (char *)malloc(sizeof(char) * (i + 1));
		if (!arr[curword])
			return (ft_free_arr(arr, curword - 1));
		s = ft_copy_word(arr[curword], (char *)s, c);
		curword++;
	}
	arr[curword] = NULL;
	return (arr);
}

char	**ft_split(char const *s, char c)
{
	int		wc;
	char	**array;

	if (s == NULL)
		return (NULL);
	if (*s == '\0')
	{
		array = (char **)malloc(sizeof(char *));
		if (!array)
			return (NULL);
		*array = NULL;
		return (array);
	}
	wc = ft_count_words(s, c);
	array = ft_allocate_words(s, c, wc);
	return (array);
}
