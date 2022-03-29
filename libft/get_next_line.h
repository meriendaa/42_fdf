/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmerida- <tmerida-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 17:55:14 by tmerida-          #+#    #+#             */
/*   Updated: 2022/02/18 18:36:10 by tmerida-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include <string.h>

# ifndef BUFFERSIZE
#  define BUFFER_SIZE 1
# endif

char	*ft_get_strchr(char *s, int c);
char	*ft_get_strjoin(char *left_str, char *buff);
size_t	ft_get_strlen(char *s);
char	*get_next_line(int fd);
char	*ft_linia(char *guardar);
char	*ft_principal(char *guardar, int fd);

#endif
