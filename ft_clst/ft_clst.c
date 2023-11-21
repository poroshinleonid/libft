/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_clst.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lporoshi <lporoshi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 16:26:45 by lporoshi          #+#    #+#             */
/*   Updated: 2023/11/21 16:57:27 by lporoshi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_clst.h"

t_lst	*new_lst_node(void *content)
{
	t_lst	*new_node;

	new_node = (t_lst *)malloc(sizeof(t_lst));
	if (new_node == NULL)
		return (NULL);
	new_node->content = content;
	new_node->next = NULL;
	new_node->prev = NULL;
	new_node->is_head = 0;
	return (new_node);
}

int	lst_append_node(t_lst **list, t_lst *new_last_node)
{
	if (list == NULL || new_last_node == NULL)
		return (FT_ERROR);
	if (*list == NULL)
	{
		new_last_node->is_head = 1;
		*list = new_last_node;
	}
	else if ((*list)->next == (*list))
	{
		(*list)->next = new_last_node;
		(*list)->prev = new_last_node;
		new_last_node->next = (*list);
		new_last_node->prev = (*list);
	}
	else
	{
		new_last_node->next = (*list);
		new_last_node->prev = (*list)->prev;
		(*list)->prev->next = new_last_node;
		(*list)->prev = new_last_node;
	}
	return (FT_SUCCESS);
}

int	lst_insert_node(t_lst **list, t_lst *new_first_node)
{
	if (list == NULL || new_first_node == NULL)
		return (FT_ERROR);
	new_first_node->is_head = 1;
	if (*list == NULL)
		*list = new_first_node;
	else if ((*list)->next == *list)
	{
		(*list)->next = new_first_node;
		(*list)->prev = new_first_node;
		new_first_node->next = *list;
		new_first_node->prev = *list;
		(*list)->is_head = 0;
		*list = new_first_node;
	}
	else
	{
		(*list)->prev->next = new_first_node;
		new_first_node->prev = (*list)->prev;
		new_first_node->next = (*list);
		(*list)->prev = new_first_node;
		(*list)->is_head = 0;
		*list = new_first_node;
	}
	return (FT_SUCCESS);
}

int	lst_append_content(t_lst **list, void *content)
{
	t_lst	*new_node;

	new_node = new_lst_node(content);
	if (list == NULL || new_node == NULL)
		return (FT_ERROR);
	return (lst_append_node(list, new_node));
}

int	lst_insert_content(t_lst **list, void *content)
{
	t_lst	*new_node;

	new_node = new_lst_node(content);
	if (list == NULL || new_node == NULL)
		return (FT_ERROR);
	return (lst_insert_node(list, new_node));
}
