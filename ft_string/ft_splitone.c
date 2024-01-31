/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_splitone.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lporoshi <lporoshi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 16:58:08 by trusanov          #+#    #+#             */
/*   Updated: 2024/01/22 16:58:16 by lporoshi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//if no '=', it overflows in a aycle finding char c
//if not '=' found, should return NULL as 2nd
//if fount at the last char of the string, should return "" as 2nd
char	**ft_splitone(char const *s, char c)
{
	char	**res;
	int		index_c;

	if (s[0] == '\0')
	{
		res = (char **)malloc(sizeof(char *) * 2);
		res[0] = ft_strdup("");
		res[1] = NULL;
		return (res);
	}
	if (!ft_in(c, (char *) s))
		return (ft_split(s, c));
	res = (char **)malloc(sizeof(char *) * 3);
	index_c = 0;
	while (s[index_c] != c)
		index_c++;
	res[0] = ft_substr(s, 0, index_c);
	res[1] = ft_substr(s, index_c + 1, ft_strlen(s) - index_c - 1);
	res[2] = NULL;
	return (res);
}
