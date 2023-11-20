/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lporoshi <lporoshi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 15:22:10 by lporoshi          #+#    #+#             */
/*   Updated: 2023/11/20 20:41:23 by lporoshi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_H
# define STACK_H

# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <stdio.h>
# include <limits.h>
# include "../libft.h"

# define ITOA_ERR -2147483649
# define FT_LONG_TERMINATOR -2147483650
# define FT_STACK_EMPTY -2

typedef struct s_stack {
	void			*content;
	int				is_top;
	struct s_stack	*next;
	struct s_stack	*prev;
}	t_stack;

int			stack_push(t_stack **head, void *content);
int			init_node(t_stack **node);
int			stack_swap(t_stack **stack);
void		*stack_pop(t_stack **head);
int			stack_transfer(t_stack **from, t_stack **to);
int			stack_rotate(t_stack **head);
int			stack_swap_2(t_stack **stack);
int			reverse_rotate(t_stack **head);
int			free_stack(t_stack **stack);
void		stack_terminate(t_stack *stack_a, \
			t_stack *stack_b, void *free_me, int ext_code);
int			get_stack_size(t_stack *stack);

#endif
