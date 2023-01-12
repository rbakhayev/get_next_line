/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbakhaye <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 10:10:18 by rbakhaye          #+#    #+#             */
/*   Updated: 2022/12/19 10:10:20 by rbakhaye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_reader(int fd, char *buf)
{
	int		flag;
	char	*tmp;

	tmp = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (tmp == NULL)
		return (NULL);
	flag = 1;
	while (ft_strchr(buf, '\n') == 0 && flag != 0)
	{
		flag = read(fd, tmp, BUFFER_SIZE);
		if (flag == -1)
		{
			free(tmp);
			return (NULL);
		}
		tmp[flag] = '\0';
		buf = ft_strjoin(buf, tmp);
	}
	free (tmp);
	return (buf);
}

char	*ft_ritornastr(char *buf)
{
	int		i;
	char	*str;

	i = 0;
	if (buf[i] == '\0')
		return (NULL);
	while (buf[i] != '\n' && buf[i] != '\0')
		i++;
	if (buf[i] == '\n')
		i++;
	str = (char *)malloc(sizeof(char) * (i + 1));
	i = 0;
	while (buf[i] != '\n' && buf[i] != '\0')
	{
		str[i] = buf[i];
		i++;
	}
	if (buf[i] == '\n')
	{
		str[i] = buf[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	*ft_remainder(char *buf)
{
	int		i;
	int		y;
	char	*str;

	i = 0;
	while (buf[i] != '\n' && buf[i] != '\0')
		i++;
	if (buf[i] == '\0')
	{
		free(buf);
		return (NULL);
	}
	str = (char *)malloc((sizeof(char) *(ft_strlen(buf) - i + 1)));
	if (str == NULL)
		return (NULL);
	i++;
	y = 0;
	while (buf[i] != '\0')
	{
		str[y++] = buf[i++];
	}
	str[y] = '\0';
	free(buf);
	return (str);
}

char	*get_next_line(int fd)
{
	static char	*buf;
	char		*ritorna;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buf = ft_reader(fd, buf);
	if (buf == NULL)
		return (NULL);
	ritorna = ft_ritornastr(buf);
	buf = ft_remainder(buf);
	return (ritorna);
}
