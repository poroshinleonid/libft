/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_replace_node_to_list.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lporoshi <lporoshi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 12:40:15 by lporoshi          #+#    #+#             */
/*   Updated: 2023/12/18 13:03:31 by lporoshi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	lst_replace_node2list_front(t_list **dst, t_list *source)
{
	t_list	*source_last;

	source_last = ft_lstlast(source);
	source_last->next = (*dst)->next;
	*dst = source;
	return ;
}

static void	lst_replace_node2list_mid(t_list *prev, t_list **cur, \
										t_list *source)
{
	t_list	*source_last;

	source_last = ft_lstlast(source);
	source_last->next = (*cur)->next;
	prev->next = source;
	return ;
}

static void	lst_replace_node2list_back(t_list *prev, t_list *source)
{
	prev->next = source;
	return ;
}

t_list	*lst_replace_node_to_list(t_list *prev, t_list **dst, t_list *source)
{
	t_list	*dst_saved;
	t_list	*dst_next_saved;

	if ((*dst) == NULL || source == NULL)
		return (NULL);
	dst_saved = (*dst);
	dst_next_saved = dst_saved->next;
	if (prev == NULL)
		lst_replace_node2list_front(dst, source);
	else if ((*dst)->next == NULL)
		lst_replace_node2list_back(prev, source);
	else
		lst_replace_node2list_mid(prev, dst, source);
	free(dst_saved);
	return (dst_next_saved);
}
