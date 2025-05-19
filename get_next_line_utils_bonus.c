/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbakhaye <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 10:25:38 by rbakhaye          #+#    #+#             */
/*   Updated: 2022/12/19 10:25:40 by rbakhaye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_strjoin(char *s1, char *b)
{
	size_t	i;
	char	*str;
	size_t	j;

	if (s1 == NULL)
	{
		s1 = (char *)malloc(1 * sizeof(char));
		s1[0] = '\0';
	}
	if (s1 == NULL || b == NULL)
		return (NULL);
	str = malloc((ft_strlen(s1) + ft_strlen(b) + 1) * sizeof(char));
	if (str == NULL)
		return (NULL);
	i = -1;
	j = 0;
	if (s1 != NULL)
		while (s1[++i] != '\0')
			str[i] = s1[i];
	while (b[j] != '\0')
		str[i++] = b[j++];
	str[ft_strlen(s1) + ft_strlen(b)] = '\0';
	free(s1);
	return (str);
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*ft_strchr(char *t, int c)
{
	int	u;

	u = 0;
	if (t == NULL)
		return (0);
	if (c == '\0')
		return ((char *)&t[ft_strlen(t)]);
	while (t[u] != '\0')
	{
		if (t[u] == (char)c)
			return ((char *)&t[u]);
		u++;
	}
	return (0);
}
