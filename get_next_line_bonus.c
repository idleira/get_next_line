/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibeliaie <ibeliaie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 12:31:20 by ibeliaie          #+#    #+#             */
/*   Updated: 2023/06/19 15:23:47 by ibeliaie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

/* extract line with '\n' from buffer */
char	*ft_extract_line(char *rest)
{
	int		i;
	char	*str;

	i = 0;
	if (!rest[i])
		return (NULL);
	while (rest[i] && rest[i] != '\n')
		i++;
	str = (char *)malloc(sizeof(char) * (i + 2));
	if (!str)
		return (NULL);
	i = 0;
	while (rest[i] && rest[i] != '\n')
	{
		str[i] = rest[i];
		i++;
	}
	if (rest[i] == '\n')
	{
		str[i] = rest[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

/* read from fd until '\n' and put contents into rest*/
char	*ft_read_till_nl(int fd, char *rest)
{
	char	*buff;
	int		bytes_read;

	buff = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buff)
		return (NULL);
	bytes_read = 1;
	while (!ft_strchr(rest, '\n') && bytes_read != 0)
	{
		bytes_read = read(fd, buff, BUFFER_SIZE);
		if (bytes_read == -1)
		{
			free (buff);
			return (NULL);
		}
		buff[bytes_read] = '\0';
		rest = ft_strjoin(rest, buff);
	}
	free (buff);
	return (rest);
}

/* read line from a file specified by fd and return it */
char	*get_next_line(int fd)
{
	char		*line;
	static char	*rest[4096];

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	rest[fd] = ft_read_till_nl(fd, rest[fd]);
	if (!rest[fd])
		return (NULL);
	line = ft_extract_line(rest[fd]);
	rest[fd] = ft_new_rest(rest[fd]);
	return (line);
}
