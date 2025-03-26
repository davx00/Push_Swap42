/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: despanol <despanol@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/02 17:39:25 by despanol          #+#    #+#             */
/*   Updated: 2025/03/26 09:29:35 by despanol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	char	**args;
	t_stack	*a;
	t_stack	*b;

	if (argc < 2)
		return (0);
	args = convert_args(argc, argv);
	if (!args)
		return (ft_putstr("Error\n"), 2);
	if (!check_valid_num(args))
		return (free_array(args), ft_putstr("Error\n"), 2);
	if (!check_duplicates(args))
		return (free_array(args), ft_putstr("Error\n"), 2);
	a = create_stack(args);
	b = init_the_stack();
	if (is_stack_in_order(a) == 1 && b->size == 0)
		return (free_stack(a), free_stack(b), 0);
	order(a, b);
	if (is_stack_in_order(a) == 1 && b->size == 0)
		return (free_stack(a), free_stack(b), 0);
	else
		return (free_stack(a), free_stack(b), ft_putstr("Error\n"), 2);
	return (free_stack(a), free_stack(b), 0);
}
