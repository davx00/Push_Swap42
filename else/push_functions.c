/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: despanol <despanol@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 18:45:24 by despanol          #+#    #+#             */
/*   Updated: 2025/03/26 20:35:38 by despanol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_to_head(t_stack *stack, t_stack *stack_b)
{
	if (stack_b->size != 0)
	{
		push_(stack, return_buble(stack_b));
	}
}

void	push_to_head_b(t_stack *stack, t_stack *stack_b)
{
	if (stack->size != 0)
	{
		push_(stack_b, return_buble(stack));
	}
}

void	push(t_stack *stack, int value)
{
	t_nodedouble	*node;

	node = create_node(value);
	if (!node)
	{
		free_stack(stack);
		ft_putstr("Error\n");
		return ;
	}
	node->next = stack->head;
	if (stack->size == 0)
	{
		stack->tail = node;
		stack->head = node;
	}
	else
	{
		stack->head->prev = node;
		stack->head = node;
	}
	stack->size++;
}
