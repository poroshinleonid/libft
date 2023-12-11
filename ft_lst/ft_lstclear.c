/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trusanov <trusanov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 17:29:58 by lporoshi          #+#    #+#             */
/*   Updated: 2023/12/11 14:31:16 by trusanov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*cur;
	t_list	*prev;

	if (!lst || !(*lst) || !del)
		return ;
	if ((*lst)->next == NULL)
	{
		del((*lst)->content);
		free(*lst);
		*lst = NULL;
		return ;
	}
	cur = (*lst)->next;
	prev = *lst;
	while (prev)
	{
		del(prev->content);
		free(prev);
		prev = cur;
		if (cur)
			cur = cur->next;
	}
	*lst = NULL;
}
