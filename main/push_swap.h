/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: despanol <despanol@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/02 17:39:31 by despanol          #+#    #+#             */
/*   Updated: 2025/03/26 20:51:20 by despanol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"
# include <stdlib.h>
# include <limits.h>
# include <stdio.h>
// # define INT_MAX 
// # define INT_MIN

typedef struct s_nodedouble
{
	int						data;
	struct s_nodedouble		*next;
	struct s_nodedouble		*prev;
}	t_nodedouble;

typedef struct s_stack
{
	t_nodedouble	*head;
	t_nodedouble	*tail;
	int				size;
}	t_stack;

int				count_total_args(int argc, char **argv);
char			**convert_args(int argc, char **argv);
int				ft_putnbr(int n);
int				ft_plus_minus(const char *str);
int				num_len(char *str_num);
int				check_valid_num(char **args);
int				check_duplicates(char **args);
int				*strarray_to_intarray(char **args);
int				array_len(char **array);
int				*index_intarray(int *array, int size);
void			free_array(char **array);
t_stack			*create_stack(char **args);
t_stack			*init_the_stack(void);
t_nodedouble	*create_node(int data);
void			push(t_stack *stack, int value);
int				is_stack_in_order(t_stack *a);
void			free_stack(t_stack *stack);
void			order_two(t_stack *a);
void			swap(t_stack *stack);
void			push_(t_stack *stack, int value);
int				return_buble(t_stack *stack);
int				return_buble(t_stack *stack);
void			rotate_ra_rb(t_stack *stack, t_stack *stack_b);
void			rotate(t_stack *stack);
void			reverse_rotate(t_stack *stack);
int				where_is_min(t_stack *stack);
void			order_four(t_stack *stack, t_stack *stack_b);
void			order_five(t_stack *stack, t_stack *stack_b);
int				ft_sqrt(int nb);
int				count_nodo_interaction(t_nodedouble *node, int size);
void			k_short(t_stack *stack, t_stack *stack_b, int size);
void			k_short_aux(t_stack *stack, t_stack *stack_b, int size);
int				check_if_the_stack_is_ordered(t_stack *stack);
void			exe_operation(t_stack *a, t_stack *b, char *op);
void			order_three(t_stack *a);
void			printf_operations(t_stack *a, t_stack *b, char *operations);
void			swap_both(t_stack *a, t_stack *b);
void			rotate_ra_rb(t_stack *stack, t_stack *stack_b);
void			push_to_head(t_stack *stack, t_stack *stack_b);
void			rotate_rrra_rrb(t_stack *stack, t_stack *stack_b);
int				*index_intarray(int *args, int size);
void			ft_swap(int *a, int *b);
void			quick_sort_intarray(int *arr, size_t size);
void			quick_sort_recursive(int *arr, int low, int high);
int				partition(int *arr, int low, int high);
void			order(t_stack *a, t_stack *b);
void			swap_b(t_stack *stack_b);
void			rotate_b(t_stack *stack_b);
void			reverse_rotate_b(t_stack *stack_b);
void			push_to_head_b(t_stack *stack, t_stack *stack_b);
void			exe_operation2(t_stack *a, t_stack *b, char *operation);

#endif