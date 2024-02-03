/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_array_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lporoshi <lporoshi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 17:27:20 by lporoshi          #+#    #+#             */
/*   Updated: 2024/02/03 17:30:50 by lporoshi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ptr_arr_free_simple(void ***arr)
{
	char	**orig_arr;

	orig_arr = *arr;
	if (arr == NULL || *arr == NULL)
		return ;
	while (**arr != NULL)
	{
		free(**arr);
		(*arr)++;
	}
	free (orig_arr);
	*arr = NULL;
	return ;
}

void	ptr_arr_free_complex(void ***arr, void (*del_item)(void *))
{
	char	**orig_arr;

	orig_arr = *arr;
	if (arr == NULL || *arr == NULL)
		return ;
	while (**arr != NULL)
	{
		del_item(**arr);
		(*arr)++;
	}
	free (orig_arr);
	*arr = NULL;
	return ;
}
