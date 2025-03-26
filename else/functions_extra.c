/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions_extra.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: despanol <despanol@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 17:54:30 by despanol          #+#    #+#             */
/*   Updated: 2025/03/26 13:29:31 by despanol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_stack_in_order(t_stack *a) // check if the stack is in ascendent order
{
	t_nodedouble	*current;
	int				sorted;

	if (a->size >= 2)
	{
		sorted = 1;
		current = a->head;
		while (current->next != NULL)
		{
			if (current->data > current->next->data)
			{
				sorted = 0;
				break ;
			}
			current = current->next;
		}
		return (sorted);
	}
	if (a->size == 1)
		return (1);
	return (0);
}

void	push_(t_stack *stack, int value)
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

int	return_buble(t_stack *stack)
{
	t_nodedouble	*node_to_delete;
	int				val;

	if (stack->size == 0)
		return (free_stack(stack), ft_putstr("Error\n"), -1);
	node_to_delete = stack->head;
	val = node_to_delete->data;
	stack->head = node_to_delete->next;
	if (stack->head != NULL)
		stack->head->prev = NULL;
	else
		stack->tail = NULL;
	free(node_to_delete);
	stack->size--;
	return (val);
}

void	printf_operations(t_stack *a, t_stack *b, char *operations)
{
	exe_operation(a, b, operations);
	ft_printf("%s\n", operations);
}
