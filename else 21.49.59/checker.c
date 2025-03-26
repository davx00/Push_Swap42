/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: despanol <despanol@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 11:37:05 by despanol          #+#    #+#             */
/*   Updated: 2025/03/26 09:36:05 by despanol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_duplicates(char **args)
{
	int	i;
	int	j;
	int	*int_args;
	int	arg_len;

	i = 0;
	if (args == NULL || *args == NULL)
		return (0);
	int_args = strarray_to_intarray(args);
	if (int_args == NULL)
		return (0);
	arg_len = array_len(args);
	while (i < arg_len)
	{
		j = i + 1;
		while (j < arg_len)
		{
			if (int_args[i] == int_args[j])
				return (free(int_args), 0);
			j++;
		}
		i++;
	}
	free(int_args);
	return (1);
}

int	check_valid_num(char **args)
{
	int	i;

	i = 0;
	if (args == NULL || *args == NULL)
		return (0);
	while (args[i] != NULL)
	{
		if (!ft_plus_minus(args[i]))
			return (0);
		if (num_len(args[i]) > 10)
			return (0);
		i++;
	}
	return (1);
}

int	check_if_the_stack_is_ordered(t_stack *stack)
{
	t_nodedouble	*current;
	int				i;

	if (stack->size >= 2)
	{
		i = 1;
		current = stack->head;
		while (current->next != NULL)
		{
			if (current->data > current->next->data)
				return (i = 0, 0);
			current = current->next;
		}
		return (i);
	}
	if (stack->size == 1)
		return (1);
	return (0);
}
