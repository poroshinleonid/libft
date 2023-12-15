/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_array_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lporoshi <lporoshi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 12:18:59 by lporoshi          #+#    #+#             */
/*   Updated: 2023/12/15 14:58:09 by lporoshi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	get_str_arr_len(char **strings)
{
	size_t	res_len;
	int		str_len;

	if (strings == NULL)
		return (FT_ERROR);
	res_len = 0;
	while (*strings)
	{
		str_len = ft_strlen(*strings);
		if (str_len == FT_ERROR)
			return (FT_ERROR);
		res_len += str_len;
		strings++;
	}
	return (res_len);
}

char	*strjoin_str_arr(char **strings, char sep)
{
	int		tmp_len;
	char	*joined_strings;
	int		pos;

	tmp_len = get_str_arr_len(strings);
	if (tmp_len == -1)
		return (NULL);
	joined_strings = ft_calloc(tmp_len, sizeof(char));
	pos = 0;
	while (*strings)
	{
		tmp_len = ft_strlen(*strings);
		ft_strncpy(joined_strings + pos, *strings, tmp_len);
		pos += tmp_len;
		joined_strings[pos] = sep;
		strings++;
		if (*strings)
			pos++;
	}
	joined_strings[pos] = '\0';
	return (joined_strings);
}

int	get_str_arr_sz(char **text)
{
	char	*temp;
	int		size;

	if (text == NULL)
		return (FT_ERROR);
	temp = *text;
	size = 0;
	while (temp++ != NULL)
		size++;
	return (size);
}

void	free_str_arr(char ***text)
{
	char	**orig_arr;

	orig_arr = *text;
	if (text == NULL || *text == NULL)
		return ;
	while (**text != NULL)
	{
		free(**text);
		(*text)++;
	}
	free (orig_arr);
	*text = NULL;
	return ;
}
