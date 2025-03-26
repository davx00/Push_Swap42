/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: despanol <despanol@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 19:24:59 by despanol          #+#    #+#             */
/*   Updated: 2025/03/26 20:43:33 by despanol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate(t_stack *a)
{
	t_nodedouble	*new_tail;
	t_nodedouble	*new_head;

	if (a->size > 1)
	{
		new_tail = a->head;
		new_head = a->head->next;
		new_head->prev = NULL;
		a->head = new_head;
		a->tail->next = new_tail;
		new_tail->prev = a->tail;
		new_tail->next = NULL;
		a->tail = new_tail;
	}
}

void	rotate_b(t_stack *b)
{
	t_nodedouble	*new_tail;
	t_nodedouble	*new_head;

	if (b->size > 1)
	{
		new_tail = b->head;
		new_head = b->head->next;
		new_head->prev = NULL;
		b->head = new_head;
		b->tail->next = new_tail;
		new_tail->prev = b->tail;
		new_tail->next = NULL;
		b->tail = new_tail;
	}
}

void	rotate_ra_rb(t_stack *stack, t_stack *stack_b)
{
	rotate(stack);
	rotate_b(stack_b);
}

void	reverse_rotate(t_stack *stack)
{
	t_nodedouble	*first;
	t_nodedouble	*last;

	if (stack->size > 1)
	{
		first = stack->tail;
		last = stack->tail->prev;
		last->next = NULL;
		stack->tail = last;
		first->prev = NULL;
		first->next = stack->head;
		stack->head->prev = first;
		stack->head = first;
	}
}

void	reverse_rotate_b(t_stack *stack_b)
{
	t_nodedouble	*first;
	t_nodedouble	*last;

	if (stack_b->size > 1)
	{
		first = stack_b->tail;
		last = stack_b->tail->prev;
		if (last != NULL)
		{
			last->next = NULL;
		}
		stack_b->tail = last;
		first->prev = NULL;
		if (stack_b->head != NULL)
		{
			first->next = stack_b->head;
			stack_b->head->prev = first;
		}
		stack_b->head = first;
	}
}
