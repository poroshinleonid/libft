/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_replace_node_to_list.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lporoshi <lporoshi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 12:40:15 by lporoshi          #+#    #+#             */
/*   Updated: 2023/12/16 12:54:51 by lporoshi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	lst_replace_node2list_front(t_list **dst, t_list *source);
void	lst_replace_node2list_mid(t_list *prev, t_list **cur, t_list *source);

t_list	*lst_replace_node_to_list(t_list *prev, t_list **dst, t_list *source)
{
	t_list	*ret_val;

	ret_val = (*dst)->next;
	if ((*dst) == NULL || source == NULL)
		return (NULL);
	if (prev == NULL)
		lst_replace_node2list_front(dst, source);
	else if ((*dst)->next == NULL)
		ft_lstadd_back(&prev, source);
	else
		lst_replace_node2list_mid(prev, dst, source);
	free((*dst));
	return (ret_val);
}
