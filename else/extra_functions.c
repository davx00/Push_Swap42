/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extra_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: despanol <despanol@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 11:41:18 by despanol          #+#    #+#             */
/*   Updated: 2025/03/26 13:21:50 by despanol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_plus_minus(const char *str)
{
	if (str == NULL)
		return (0);
	while (ft_isspace(*str))
		str++;
	if (*str == '+' || *str == '-')
		str++;
	if (*str == '\0')
		return (0);
	while (*str)
	{
		if (!ft_isdigit(*str))
			return (0);
		str++;
	}
	while (ft_isspace(*str))
		str++;
	if (*str != '\0')
		return (0);
	return (1);
}

int	num_len(char *str_num)
{
	int	len;
	int	i;

	len = 0;
	i = 0;
	if (str_num[i] == '-' || str_num[i] == '+')
		i++;
	while (str_num[i] == '0')
		i++;
	while (str_num[i] >= '0' && str_num[i] <= '9')
	{
		len++;
		i++;
	}
	return (len);
}

int	*strarray_to_intarray(char **str)
{
	int		i;
	int		num_longitude;
	int		*int_array;
	long	value;

	num_longitude = 0;
	if (!str || !*str)
		return (NULL);
	while (str[num_longitude])
		num_longitude++;
	int_array = (int *)ft_calloc(num_longitude, sizeof(int));
	if (!int_array)
		return (NULL);
	i = 0;
	while (i < num_longitude)
	{
		value = ft_atol(str[i]);
		if (value > INT_MAX || value < INT_MIN || num_len(str[i]) > 10)
			return (free(int_array), NULL);
		int_array[i] = (int)value;
		i++;
	}
	return (int_array);
}

int	array_len(char **array)
{
	int	i;

	i = 0;
	while (array[i] != NULL)
		i++;
	return (i);
}

void	free_array(char **array)
{
	int	i;

	i = 0;
	if (array[i] == NULL)
		return ;
	if (!array)
		return ;
	while (array[i])
	{
		free(array[i]);
		array[i] = NULL;
		i++;
	}
	free(array);
	array = NULL;
}
