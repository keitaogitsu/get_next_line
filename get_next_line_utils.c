/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kogitsu <kogitsu@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 12:43:42 by kogitsu           #+#    #+#             */
/*   Updated: 2023/03/13 19:51:10 by kogitsu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_free(char *str)
{
	free(str);
	return (NULL);
}

size_t	ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	while (s[len] != '\0')
		len++;
	return (len);
}

char	*ft_strchr(const char *s, int c)
{
	size_t	i;

	i = 0;
	if (s == NULL)
		return (NULL);
	while (s[i])
	{
		if (s[i] == (char)c)
			return ((char *)&s[i]);
		i++;
	}
	if (c == '\0')
		return ((char *)&s[i]);
	return (NULL);
}

void	ft_join_content(char *str, char *s1, char *s2)
{
	while (*s1)
		*(str++) = *(s1++);
	while (*s2)
		*(str++) = *(s2++);
	*str = '\0';
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*str;
	char	*start_str;
	int		flag;

	flag = 0;
	if (s1 == NULL && s2 != NULL)
	{
		s1 = (char *)malloc(1 * sizeof(char));
		if (s1 == NULL)
			return (NULL);
		s1[0] = '\0';
		flag = 1;
	}
	str = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	start_str = str;
	if (str == NULL && flag)
		return (ft_free(s1));
	else if (str == NULL)
		return (NULL);
	ft_join_content(str, s1, s2);
	if (flag)
		free(s1);
	return (start_str);
}
