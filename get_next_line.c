/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: realdahh <realdahh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 18:02:40 by realdahh          #+#    #+#             */
/*   Updated: 2022/11/12 15:12:26 by realdahh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_allocate(char *str)
{
	int		i;
	char	*new;

	i = 0;
	if (str[i] == '\0')
		return (NULL);
	while (str[i] != '\n' && str[i])
		i++;
		new = malloc(sizeof(char) * i + 2);
	if (!new)
		return (NULL);
	i = 0;
	while (str[i] != '\n' && str[i])
	{
		new[i] = str[i];
		i++;
	}
	if (str[i] == '\n')
		new[i++] = '\n';
	new[i] = '\0';
	return (new);
}

char	*ft_save(char *str)
{
	int		i;
	int		j;
	char	*new;

	j = 0;
	if (!str)
		return (NULL);
	i = ft_strlen(str);
	while (str[j] != '\n' && str[j])
		j++;
	if (str[j] == '\0')
	{
		free(str);
		return (NULL);
	}
	new = malloc(sizeof(char) * (i - j));
	if (!new)
		return (NULL);
	i = 0;
	j++;
	while (str[j])
		new[i++] = str[j++];
	new[i] = '\0';
	free(str);
	return (new);
}

char	*ft_read_line(int fd, char *buf, char *new, char *txt)
{
	int		i;

	i = 1;
	while (i != 0)
	{
		i = read(fd, buf, BUFFER_SIZE);
		if (i == -1)
		{
			free (buf);
			return (NULL);
		}
		buf[i] = '\0';
		new = txt;
		if (!new)
		{
			new = malloc(sizeof(char) * 1);
			new[0] = '\0';
		}
		txt = ft_strjoin(new, buf);
		free(new);
		if (has_newline(txt) == 1)
			break ;
	}
	free(buf);
	return (txt);
}

char	*get_next_line(int fd)
{
	static char	*txt;
	void		*buf;
	char		*line;
	char		*new;

	new = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0 || fd > 1024)
		return (NULL);
	buf = malloc(BUFFER_SIZE + 1);
	if (!buf)
		return (NULL);
	txt = ft_read_line(fd, buf, new, txt);
	if (!txt)
		return (NULL);
	line = ft_allocate(txt);
	txt = ft_save(txt);
	return (line);
}
