/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lporoshi <lporoshi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 15:33:50 by lporoshi          #+#    #+#             */
/*   Updated: 2024/02/25 16:42:16 by lporoshi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_get_start(const char *s1, char *set)
{
	int	i;

	if (!s1 || !set)
		return (FT_ERROR);
	i = 0;
	while (s1[i] && ft_in(s1[i], set))
		i++;
	return (i);
}

static int	ft_get_end(const char *s1, char *set)
{
	int	i;

	i = ft_strlen(s1) - 1;
	while (i >= 0 && ft_in(s1[i], set))
		i--;
	return (i);
}

static char	*ft_get_empty_str(void)
{
	char	*s;

	s = (char *)malloc(sizeof(char));
	if (!s)
		return (NULL);
	*s = '\0';
	return (s);
}

char	*ft_strtrim(char *s1, char *set)
{
	int		start;
	int		end;
	int		i;
	char	*trimmed;

	if (!s1 || !set)
		return (NULL);
	start = ft_get_start(s1, set);
	end = ft_get_end(s1, set);
	if (end < start)
		return (ft_get_empty_str());
	trimmed = (char *)ft_calloc((end - start + 2), sizeof(char));
	if (!trimmed)
		return (free(s1), NULL);
	i = 0;
	while (start <= end)
	{
		trimmed[i] = s1[start];
		start++;
		i++;
	}
	trimmed[i] = '\0';
	free(s1);
	return (trimmed);
}
