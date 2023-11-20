/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lporoshi <lporoshi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 16:13:01 by lporoshi          #+#    #+#             */
/*   Updated: 2023/11/20 16:05:50 by lporoshi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	*ft_realloc(void *old_mem, size_t old_sz, size_t new_sz)
{
	void	*new_mem;

	if (!old_mem)
		return (NULL);
	new_mem = (void *)malloc(new_sz);
	if (new_mem == NULL)
		return (NULL);
	ft_bzero(new_mem, new_sz);
	if (new_sz >= old_sz)
		ft_memcpy(new_mem, old_mem, old_sz);
	else
		ft_memcpy(new_mem, old_mem, new_sz);
	free(old_mem);
	return (new_mem);
}