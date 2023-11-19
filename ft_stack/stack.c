/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lporoshi <lporoshi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 15:22:07 by lporoshi          #+#    #+#             */
/*   Updated: 2023/11/19 18:09:29 by lporoshi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

int	init_node(t_stack **node)
{
	(*node) = malloc(sizeof(t_stack));
	if (!(*node))
		return (FT_ERROR);
	(*node)->content = NULL;
	(*node)->next = NULL;
	(*node)->prev = NULL;
	(*node)->is_top = 0;
	return (FT_SUCCESS);
}
