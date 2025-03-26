/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stacks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: despanol <despanol@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 12:49:50 by despanol          #+#    #+#             */
/*   Updated: 2025/03/24 18:45:49 by despanol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*create_stack(char **args)
{
	t_stack	*stack;
	int		size;
	int		*int_args;
	int		*stack_array;

	int_args = strarray_to_intarray(args);
	if (!int_args)
		return (free_array(args), ft_putstr("Error\n"), NULL);
	stack = init_the_stack();
	if (!stack)
		return (free_array(args), free(int_args), ft_putstr("Error\n"), NULL);
	size = array_len(args);
	stack_array = index_intarray(int_args, size);
	if (!stack_array)
	{
		ft_putstr("Error\n");
		return (free_array(args), free(int_args), free_stack(stack), NULL);
	}
	while (--size >= 0)
		push(stack, stack_array[size]);
	free(int_args);
	free(stack_array);
	free_array(args);
	return (stack);
}

t_stack	*init_the_stack(void)
{
	t_stack	*new_stack;

	new_stack = (t_stack *)ft_calloc(1, sizeof(t_stack));
	if (!new_stack)
		return (NULL);
	new_stack->head = NULL;
	new_stack->tail = NULL;
	new_stack->size = 0;
	return (new_stack);
}

t_nodedouble	*create_node(int data)
{
	t_nodedouble	*node;

	node = (t_nodedouble *)ft_calloc(1, sizeof(t_nodedouble));
	if (!node)
		return (NULL);
	node->data = data;
	node->prev = NULL;
	node->next = NULL;
	return (node);
}

void	free_stack(t_stack *stack)
{
	t_nodedouble	*node;
	t_nodedouble	*next;

	if (!stack)
		return ;
	node = stack->head;
	while (node != NULL)
	{
		next = node->next;
		free(node);
		node = next;
	}
	free(stack);
	stack = NULL;
}
