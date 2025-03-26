/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: despanol <despanol@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 17:43:20 by despanol          #+#    #+#             */
/*   Updated: 2025/03/21 10:04:14 by despanol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_stack *stack)
{
	t_nodedouble	*first;
	t_nodedouble	*second;

	if (stack->size < 2)
		return ;
	first = stack->head;
	second = first->next;
	first->next = second->next;
	if (second->next)
		second->next->prev = first;
	second->prev = NULL;
	second->next = first;
	first->prev = second;
	stack->head = second;
	if (stack->size == 2)
		stack->tail = first;
}

void	swap_b(t_stack *stack_b)
{
	t_nodedouble	*first;
	t_nodedouble	*second;

	if (stack_b->size < 2)
		return ;
	first = stack_b->head;
	second = first->next;
	first->next = second->next;
	if (second->next)
		second->next->prev = first;
	second->prev = NULL;
	second->next = first;
	first->prev = second;
	stack_b->head = second;
	if (stack_b->size == 2)
		stack_b->tail = first;
}

void	swap_both(t_stack *a, t_stack *b)
{
	swap(a);
	swap_b(b);
}
