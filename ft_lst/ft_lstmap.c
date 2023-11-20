/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lporoshi <lporoshi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 17:36:54 by lporoshi          #+#    #+#             */
/*   Updated: 2023/11/20 16:06:34 by lporoshi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static void	ft_free_list(t_list *head, void (*del)(void *))
{
	t_list	*current;
	t_list	*nextnode;

	current = head;
	while (current)
	{
		del(current->content);
		if (current->next)
		{
			nextnode = current->next;
			free(current);
			current = nextnode;
		}
		else
		{
			free(current);
			return ;
		}
	}
	return ;
}

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_head;
	t_list	*cur;

	if (!lst || !f || !del)
		return (NULL);
	new_head = ft_lstnew(f(lst->content));
	if (!new_head)
		return (NULL);
	cur = new_head;
	lst = lst->next;
	while (lst)
	{
		cur->next = ft_lstnew(f(lst->content));
		if (!cur->next)
		{
			ft_free_list(new_head, del);
			return (NULL);
		}
		cur = cur->next;
		if (!lst->next)
			return (new_head);
		lst = lst->next;
	}
	return (new_head);
}
