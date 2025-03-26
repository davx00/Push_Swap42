/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: despanol <despanol@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/02 18:04:18 by despanol          #+#    #+#             */
/*   Updated: 2025/03/24 12:39:25 by despanol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	count_total_args(int argc, char **argv)
{
	int				total_args;
	int				i;
	char			**split;
	int				j;

	total_args = 0;
	i = 1;
	while (i < argc)
	{
		split = ft_split(argv[i], ' ');
		j = 0;
		while (split[j])
		{
			total_args++;
			j++;
		}
		free(split);
		i++;
	}
	return (total_args);
}

static char	**free_str_return(char *str, char **ret)
{
	free(str);
	return (ret);
}

static char	*join_args(int argc, char **argv, char *str)
{
	char			*aux;
	int				i;

	i = 1;
	while (i < argc)
	{
		if (argv[i][0] == '\0')
		{
			free(str);
			return (NULL);
		}
		aux = str;
		str = new_ft_strjoin(aux, argv[i], ' ');
		if (!str)
		{
			free(aux);
			return (NULL);
		}
		free(aux);
		i++;
	}
	return (str);
}

char	**convert_args(int argc, char **argv)
{
	char	**args;
	char	*str;

	if (argc < 2)
		return (NULL);
	str = ft_strdup("");
	if (!str)
		return (NULL);
	str = join_args(argc, argv, str);
	if (!str)
		return (NULL);
	args = ft_split(str, ' ');
	if (!args)
		return (free_str_return(str, NULL));
	return (free_str_return(str, args));
}

void	ft_swap(int *a, int *b)
{
	int	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}
