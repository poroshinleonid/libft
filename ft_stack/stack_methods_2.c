/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_methods_2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lporoshi <lporoshi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 19:09:33 by lporoshi          #+#    #+#             */
/*   Updated: 2023/11/19 18:11:18 by lporoshi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

/**
 * @brief Swaps elems in a stack of size 2
 * 
 * @param stack 
 * @return int 
 */
int	stack_swap_2(t_stack **stack)
{
	if (!stack || !(*stack))
		return (FT_ERROR);
	(*stack)->is_top = 0;
	(*stack)->next->is_top = 1;
	*stack = (*stack)->next;
	return (FT_SUCCESS);
}

/**
 * @brief Rotates a stack (First element becomes last)
 * 
 * @param head 
 * @return int 
 */
int	stack_rotate(t_stack **head)
{
	if (!head)
		return (FT_ERROR);
	if (!(*head) || *head == (*head)->next)
		return (FT_SUCCESS);
	(*head)->next->is_top = 1;
	(*head)->is_top = 0;
	*head = (*head)->next;
	return (FT_SUCCESS);
}

int	get_stack_size(t_stack *stack)
{
	int	sz;

	sz = 0;
	if (!stack)
		return (0);
	sz++;
	stack = stack->next;
	while (stack->is_top == 0)
	{
		sz++;
		stack = stack->next;
	}
	return (sz);
}
