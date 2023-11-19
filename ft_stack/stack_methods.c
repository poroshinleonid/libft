/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_methods.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lporoshi <lporoshi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 17:31:04 by lporoshi          #+#    #+#             */
/*   Updated: 2023/11/19 18:09:04 by lporoshi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

int	stack_swap(t_stack **stack)
{
	t_stack	*temp;

	if (!stack)
		return (FT_ERROR);
	if (!*stack || *stack == (*stack)->next)
		return (FT_SUCCESS);
	if ((*stack)->prev == (*stack)->next)
		return (stack_swap_2(stack));
	temp = (*stack)->next;
	(*stack)->prev->next = (*stack)->next;
	temp->next->prev = (*stack);
	(*stack)->next = temp->next;
	temp->next = (*stack);
	temp->prev = (*stack)->prev;
	(*stack)->prev = temp;
	(*stack)->is_top = 0;
	temp->is_top = 1;
	*stack = temp;
	return (FT_SUCCESS);
}

int	stack_push(t_stack **head, void *content)
{
	t_stack	*temp;

	if (!(*head))
	{
		if (init_node(head) == FT_ERROR)
			return (FT_ERROR);
		(*head)->content = content;
		(*head)->prev = *head;
		(*head)->next = *head;
		(*head)->is_top = 1;
		return (FT_SUCCESS);
	}
	temp = (*head)->prev;
	if (init_node(&((*head)->prev)) == FT_ERROR)
		return (FT_ERROR);
	(*head)->prev->content = content;
	(*head)->prev->next = (*head);
	(*head)->prev->prev = temp;
	(*head)->prev->is_top = 1;
	(*head)->is_top = 0;
	if (temp)
		temp->next = (*head)->prev;
	*head = (*head)->prev;
	return (FT_SUCCESS);
}

void	*stack_pop(t_stack **head)
{
	void			*content;
	t_stack			*temp;

	if (!head || !(*head))
		return (NULL);
	content = (*head)->content;
	temp = (*head)->next;
	(*head)->next->prev = (*head)->prev;
	(*head)->prev->next = (*head)->next;
	if (*head == temp)
	{
		free(*head);
		*head = NULL;
	}
	else
	{
		free(*head);
		*head = temp;
	}
	if (*head)
		(*head)->is_top = 1;
	return (content);
}

int	stack_transfer(t_stack **from, t_stack **to)
{
	void	*content;

	content = stack_pop(from);
	if (content == NULL)
		return (FT_ERROR);
	return (stack_push(to, content));
}

int	reverse_rotate(t_stack **head)
{
	if (!head)
		return (FT_ERROR);
	if (!(*head) || *head == (*head)->next)
		return (FT_SUCCESS);
	(*head)->is_top = 0;
	(*head)->prev->is_top = 1;
	*head = (*head)->prev;
	return (FT_SUCCESS);
}
