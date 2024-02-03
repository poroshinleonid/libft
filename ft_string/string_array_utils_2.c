/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_array_utils_2.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lporoshi <lporoshi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 17:16:35 by lporoshi          #+#    #+#             */
/*   Updated: 2024/02/03 17:25:33 by lporoshi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**str_arr_append(char ***arr_ptr, char *new_item)
{
	int		sz;
	char	**new_arr;

	if (arr_ptr == NULL)
		return (NULL);
	if (*arr_ptr == NULL)
		return (ft_strdup(new_item));
	sz = get_str_arr_sz(*arr_ptr);
	new_arr = ft_calloc(sz + 2, sizeof(char *));
	sz = 0;
	while ((*arr_ptr)[sz] != NULL)
	{
		new_arr[sz] = (*arr_ptr)[sz];
		sz++;
	}
	new_arr[sz] = ft_strdup(new_item);
	free_str_arr(arr_ptr);
	return (new_arr);
}
