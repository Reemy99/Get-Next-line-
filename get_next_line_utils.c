/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: realdahh <realdahh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 18:17:19 by realdahh          #+#    #+#             */
/*   Updated: 2022/11/12 13:29:59 by realdahh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strjoin(char const *str1, char const *str2)
{
	char	*new;
	size_t	i;
	size_t	x;

	x = 0;
	if (!str1 || !str2)
		return (NULL);
	new = malloc(sizeof(char) * (ft_strlen(str1) + ft_strlen(str2) + 1));
	if (!new)
		return (NULL);
	i = 0;
	while (str1[x] != '\0')
		new[i++] = str1[x++];
	x = 0;
	while (str2[x] != '\0')
		new[i++] = str2[x++];
	new[i++] = '\0';
	return (new);
}

size_t	ft_strlen(const	char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

int	has_newline(char *str)
{
	if (!str)
		return (0);
	while (*str)
	{
		if (*str == '\n')
			return (1);
		str++;
	}
	return (0);
}
