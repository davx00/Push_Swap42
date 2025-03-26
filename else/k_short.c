/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   k_short.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: despanol <despanol@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 14:18:20 by despanol          #+#    #+#             */
/*   Updated: 2025/03/26 19:21:39 by despanol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	where_is_min(t_stack *stack)
{
	t_nodedouble	*current;
	int				min;
	int				min_index;
	int				i;

	if (stack == NULL || stack->head == NULL)
		return (ft_putstr_fd("There is no min index", 2), -1);
	min = stack->head->data;
	current = stack->head;
	min_index = 0;
	i = 0;
	while (current != NULL)
	{
		if (current->data < min)
		{
			min = current->data;
			min_index = i;
		}
		current = current->next;
		i++;
	}
	return (min_index);
}

int	ft_sqrt(int nb)
{
	int	i;

	if (nb < 0)
		return (0);
	i = 0;
	while (i * i <= nb)
	{
		if (i * i == nb)
			return (i);
		i++;
	}
	return (i - 1);
}

void	k_short(t_stack *stack, t_stack *stack_b, int size)
{
	int	i;
	int	range;

	i = 0;
	range = ft_sqrt(size) * 14 / 10;
	while (stack->head != NULL)
	{
		if (stack->head->data <= i)
		{
			printf_operations(stack, stack_b, "pb");
			if (stack_b->size > 1)
				printf_operations(NULL, stack_b, "rb");
			i++;
		}
		else if (stack->head->data <= i + range)
		{
			printf_operations(stack, stack_b, "pb");
			i++;
		}
		else
			printf_operations(stack, NULL, "ra");
	}
}

void	k_short_aux(t_stack *stack, t_stack *stack_b, int size)
{
	int	rb;
	int	rrb;

	while (size - 1 >= 0)
	{
		rb = count_nodo_interaction(stack_b->head, size - 1);
		rrb = stack_b->size - rb;
		if (rb <= rrb)
		{
			while (stack_b->head->data != size - 1)
				printf_operations(NULL, stack_b, "rb");
			printf_operations(stack, stack_b, "pa");
			size--;
		}
		else
		{
			while (stack_b->head->data != size - 1)
				printf_operations(NULL, stack_b, "rrb");
			printf_operations(stack, stack_b, "pa");
			size--;
		}
	}
}

int	count_nodo_interaction(t_nodedouble *node, int size)
{
	int	i;

	i = 0;
	while (node != NULL)
	{
		if (node->data == size)
			return (i);
		node = node->next;
		i++;
	}
	return (-1);
}
