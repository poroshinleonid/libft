/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_array_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lporoshi <lporoshi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 12:18:59 by lporoshi          #+#    #+#             */
/*   Updated: 2023/11/19 18:54:58 by lporoshi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

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
	if (text == NULL || *text == NULL)
		return ;
	while (**text != NULL)
	{
		free(**text);
		(**text)++;
	}
	free (*text);
	return ;
}
