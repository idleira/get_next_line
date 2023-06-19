/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibeliaie <ibeliaie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/04 18:43:47 by ibeliaie          #+#    #+#             */
/*   Updated: 2023/06/19 12:26:45 by ibeliaie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	size_t	count;

	count = 0;
	if (!str)
		return (0);
	while (str[count])
		count++;
	return (count);
}

char	*ft_strchr(char *str, int find)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	if (find == '\0')
		return ((char *)&str[ft_strlen(str)]);
	while (str[i] != '\0')
	{
		if (str[i] == (char) find)
			return ((char *)&str[i]);
		i++;
	}
	return (0);
}

char	*ft_strjoin(char *rest, char *buff)
{
	size_t	i;
	size_t	j;
	char	*newstr;

	if (!rest)
	{
		rest = (char *)malloc(1 * sizeof(char));
		rest[0] = '\0';
	}
	if (!rest || !buff)
		return (NULL);
	newstr = malloc(sizeof(char) * ((ft_strlen(rest) + ft_strlen(buff)) + 1));
	if (newstr == NULL)
		return (NULL);
	i = -1;
	j = 0;
	if (rest)
		while (rest[++i] != '\0')
			newstr[i] = rest[i];
	while (buff[j] != '\0')
		newstr[i++] = buff[j++];
	newstr[ft_strlen(rest) + ft_strlen(buff)] = '\0';
	free(rest);
	return (newstr);
}

char	*ft_new_rest(char *rest)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	while (rest[i] && rest[i] != '\n')
		i++;
	if (!rest[i])
	{
		free(rest);
		return (NULL);
	}
	str = (char *)malloc(sizeof(char) * (ft_strlen(rest) - i + 1));
	if (!str)
		return (NULL);
	i++;
	j = 0;
	while (rest[i])
		str[j++] = rest[i++];
	str[j] = '\0';
	free(rest);
	return (str);
}
