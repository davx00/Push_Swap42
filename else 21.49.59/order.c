/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   order.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: despanol <despanol@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 17:53:41 by despanol          #+#    #+#             */
/*   Updated: 2025/03/26 20:50:55 by despanol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	order(t_stack *a, t_stack *b)
{
	int	size;

	size = a->size;
	if (size == 2)
		order_two(a);
	else if (size == 3)
		order_three(a);
	else if (size == 4)
		order_four(a, b);
	else if (size == 5)
		order_five(a, b);
	else
	{
		k_short(a, b, size);
		k_short_aux(a, b, size);
	}
}

void	exe_operation2(t_stack *a, t_stack *b, char *operation)
{
	free(operation);
	free_stack(a);
	free_stack(b);
	ft_putstr("Error\n");
}
