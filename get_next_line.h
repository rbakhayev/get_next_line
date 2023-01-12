/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbakhaye <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 10:10:31 by rbakhaye          #+#    #+#             */
/*   Updated: 2022/12/19 10:10:37 by rbakhaye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>
# include <sys/uio.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

char	*get_next_line(int fd);
char	*ft_reader(int fd, char *buf);
char	*ft_ritornastr(char *buf);
char	*ft_remainder(char *buf);
char	*ft_strjoin(char *s1, char *b);
size_t	ft_strlen(const char *s);
char	*ft_strchr(char *t, int c);

#endif
