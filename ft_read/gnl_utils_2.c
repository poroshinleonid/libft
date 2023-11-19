/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl_utils_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lporoshi <lporoshi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 17:48:51 by lporoshi          #+#    #+#             */
/*   Updated: 2023/11/19 18:56:47 by lporoshi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gnl.h"

void	*free_buf_tail(char **buf_tail)
{
	if (*buf_tail)
		free(*buf_tail);
	*buf_tail = NULL;
	return (NULL);
}
