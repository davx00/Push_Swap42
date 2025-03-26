/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   order2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: despanol <despanol@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 18:17:01 by despanol          #+#    #+#             */
/*   Updated: 2025/03/26 20:30:39 by despanol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	order_two(t_stack *a)
{
	if (a->head->data > a->head->next->data)
		printf_operations(a, NULL, "sa");
}

void	order_three(t_stack *a)
{
	int	first;
	int	second;
	int	third;

	first = a->head->data;
	second = a->head->next->data;
	third = a->head->next->next->data;
	if (first < second && second > third && first < third)
	{
		printf_operations(a, NULL, "sa");
		printf_operations(a, NULL, "ra");
	}
	else if (first > second && second < third && first < third)
		printf_operations(a, NULL, "sa");
	else if (first < second && second > third && first > third)
		printf_operations(a, NULL, "rra");
	else if (first > second && second < third && first > third)
		printf_operations(a, NULL, "ra");
	else if (first > second && second > third && first > third)
	{
		printf_operations(a, NULL, "sa");
		printf_operations(a, NULL, "rra");
	}
}

void	order_four(t_stack *stack, t_stack *stack_b)
{
	while (where_is_min(stack) != 0)
	{
		if (where_is_min(stack) <= 2)
			printf_operations(stack, NULL, "ra");
		else
			printf_operations(stack, NULL, "rra");
	}
	printf_operations(stack, stack_b, "pb");
	order_three(stack);
	printf_operations(stack, stack_b, "pa");
}

void	order_five(t_stack *stack, t_stack *stack_b)
{
	while (where_is_min(stack) != 0)
	{
		if (where_is_min(stack) <= 2)
			printf_operations(stack, NULL, "ra");
		else
			printf_operations(stack, NULL, "rra");
	}
	printf_operations(stack, stack_b, "pb");
	while (where_is_min(stack) != 0)
	{
		if (where_is_min(stack) <= 2)
			printf_operations(stack, NULL, "ra");
		else
			printf_operations(stack, NULL, "rra");
	}
	printf_operations(stack, stack_b, "pb");
	order_three(stack);
	printf_operations(stack, stack_b, "pa");
	printf_operations(stack, stack_b, "pa");
}

void	exe_operation(t_stack *a, t_stack *b, char *op)
{
	if (!(ft_strncmp (op, "sa", 2)) || !(ft_strncmp (op, "sa\n", 3)))
		swap(a);
	else if (!(ft_strncmp(op, "sb", 2)) || !(ft_strncmp(op, "sb\n", 3)))
		swap_b(b);
	else if (!(ft_strncmp(op, "ss", 2)) || !(ft_strncmp(op, "ss\n", 3)))
		swap_both(a, b);
	else if (!(ft_strncmp(op, "pa", 2)) || !(ft_strncmp(op, "pa\n", 3)))
		push_to_head(a, b);
	else if (!(ft_strncmp(op, "pb", 2)) || !(ft_strncmp(op, "pb\n", 3)))
		push_to_head_b(a, b);
	else if (!(ft_strncmp(op, "rra", 3)) || !(ft_strncmp(op, "rra\n", 4)))
		reverse_rotate(a);
	else if (!(ft_strncmp(op, "rrb", 3)) || !(ft_strncmp(op, "rrb\n", 4)))
		reverse_rotate_b(b);
	else if (!(ft_strncmp(op, "rrr", 3)) || !(ft_strncmp(op, "rrr\n", 4)))
		rotate_rrra_rrb(a, b);
	else if (!(ft_strncmp(op, "ra", 2)) || !(ft_strncmp(op, "ra\n", 3)))
		rotate(a);
	else if (!(ft_strncmp(op, "rb", 2)) || !(ft_strncmp(op, "rb\n", 3)))
		rotate_b(b);
	else if (!(ft_strncmp(op, "rr", 2)) || !(ft_strncmp(op, "rr\n", 3)))
		rotate_ra_rb(a, b);
	else
		exe_operation2(a, b, op);
}
