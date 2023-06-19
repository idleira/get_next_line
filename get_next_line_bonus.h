/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibeliaie <ibeliaie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 12:31:22 by ibeliaie          #+#    #+#             */
/*   Updated: 2023/06/19 12:40:08 by ibeliaie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <unistd.h>
# include <stdlib.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 5
# endif

char	*get_next_line(int fd);

char	*ft_new_rest(char *rest);
size_t	ft_strlen(const char *str);
char	*ft_extract_line(char *rest);
char	*ft_strchr(char *str, int find);
char	*ft_read_till_nl(int fd, char *rest);
char	*ft_strjoin(char *rest, char *buff);

#endif