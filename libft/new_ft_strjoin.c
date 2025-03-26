/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_ft_strjoin.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: despanol <despanol@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/16 16:21:37 by despanol          #+#    #+#             */
/*   Updated: 2025/03/26 20:48:37 by despanol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*new_ft_strjoin(char const *s1, char const *s2, char c)
{
	char	*joined;
	int		s1_len;
	int		s2_len;
	int		i;
	int		j;

	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	joined = (char *)malloc((s1_len + s2_len + 2) * sizeof(char));
	if (!joined)
		return (NULL);
	i = -1;
	while (++i < s1_len)
		joined[i] = s1[i];
	joined[i] = c;
	i++;
	j = -1;
	while (++j < s2_len)
		joined[i + j] = s2[j];
	joined[i + j] = '\0';
	return (joined);
}
