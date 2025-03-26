/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   k_short_b.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: despanol <despanol@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 20:36:00 by despanol          #+#    #+#             */
/*   Updated: 2025/03/26 13:41:05 by despanol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	*create_index_mapping(int *args, int *sorted_copy, int size)
{
	int	*index;
	int	i;
	int	j;

	index = ft_calloc(size, sizeof(int));
	if (!index)
		return (NULL);
	i = -1;
	while (++i < size)
	{
		j = -1;
		while (++j < size)
		{
			if (args[i] == sorted_copy[j])
			{
				index[i] = j;
				break ;
			}
		}
	}
	return (index);
}

int	*index_intarray(int *args, int size)
{
	int	*index;
	int	*sorted_copy;

	sorted_copy = ft_calloc(size, sizeof(int));
	if (!sorted_copy)
		return (NULL);
	ft_memcpy(sorted_copy, args, size * sizeof(int));
	quick_sort_intarray(sorted_copy, size);
	index = create_index_mapping(args, sorted_copy, size);
	free(sorted_copy);
	return (index);
}

void	quick_sort_intarray(int *arr, size_t size)
{
	if (size > 1)
		quick_sort_recursive(arr, 0, size - 1);
}

void	quick_sort_recursive(int *arr, int low, int high)
{
	int	i;

	if (low < high)
	{
		i = partition(arr, low, high);
		quick_sort_recursive(arr, low, i - 1);
		quick_sort_recursive(arr, i + 1, high);
	}
}

int	partition(int *arr, int low, int high)
{
	int	pivot;
	int	i;
	int	j;

	pivot = arr[high];
	i = low - 1;
	j = low;
	while (j < high)
	{
		if (arr[j] < pivot)
		{
			i++;
			ft_swap(&arr[i], &arr[j]);
		}
		j++;
	}
	ft_swap(&arr[i + 1], &arr[high]);
	return (i + 1);
}
