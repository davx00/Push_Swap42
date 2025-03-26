/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_rra_rrb.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: despanol <despanol@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 08:41:18 by despanol          #+#    #+#             */
/*   Updated: 2025/03/26 20:40:51 by despanol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_rrra_rrb(t_stack *stack, t_stack *stack_b)
{
	reverse_rotate(stack);
	reverse_rotate_b(stack_b);
}
