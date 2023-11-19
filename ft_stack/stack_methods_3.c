/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_methods_3.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lporoshi <lporoshi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 17:07:14 by lporoshi          #+#    #+#             */
/*   Updated: 2023/11/19 18:16:40 by lporoshi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

/**
 * @brief Free a stack correctly
 * 
 * @param stack 
 * @return int 
 */
int	free_stack(t_stack **stack)
{
	t_stack	*temp;

	if (!stack)
		return (FT_ERROR);
	if (!(*stack))
		return (FT_SUCCESS);
	if ((*stack)->next == (*stack))
	{
		free((*stack)->content);
		free(*stack);
		return (FT_SUCCESS);
	}
	(*stack) = (*stack)->next;
	while ((*stack)->is_top != 1)
	{
		temp = (*stack)->next;
		free((*stack)->content);
		free(*stack);
		(*stack) = temp;
	}
	free(*stack);
	return (FT_SUCCESS);
}

/**
 * @brief Free all the memory and stack_terminate the program
 * 
 * @param stack_a 
 * @param stack_b 
 * @param free_me 
 * @param ext_code 
 */
void	stack_terminate(t_stack *stack_a, t_stack *stack_b, \
					void *free_me, int ext_code)
{
	if (stack_a)
		free_stack(&stack_a);
	if (stack_b)
		free_stack(&stack_b);
	if (free_me)
		free(free_me);
	if (ext_code == EXIT_FAILURE)
		write(STDERR_FILENO, "Error\n", 6);
	exit(ext_code);
}
