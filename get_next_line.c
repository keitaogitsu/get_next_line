/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kogitsu <kogitsu@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 19:59:48 by kogitsu           #+#    #+#             */
/*   Updated: 2023/03/02 14:33:10 by kogitsu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_read(int fd, char *save)
{
	char	*tmp;
	char	*save_free;
	int		read_size;

	tmp = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (tmp == NULL)
		return (NULL);
	while (ft_strchr(save, '\n') == NULL && read_size != 0)
	{
		read_size = read(fd, tmp, BUFFER_SIZE);
		if (read_size == -1)
		{
			free(tmp);
			return (NULL);
		}
		else
		{
			tmp[read_size] = '\0';
			save_free = save;
			save = ft_strjoin(save, tmp);
			free(save_free);
		}
	}
	free(tmp);
	return (save);
}

char	*ft_get_line(char *save)
{
	size_t	i;
	size_t	count;
	char	*rtn_line;

	i = 0;
	count = ft_strchr(save, '\n') - save;
	rtn_line = (char *)malloc((count + 2) + sizeof(char));
	if (rtn_line == NULL)
		return (NULL);
	while (save[i] != '\n')
	{
		rtn_line[i] = save[i];
		i++;
	}
	rtn_line[i++] = '\n';
	rtn_line[i] = '\0';
	return (rtn_line);
}

char	*ft_save(char *save)
{
	size_t	i;
	size_t	j;
	size_t	save_size;
	char	*rtn;

	i = 0;
	while (save[i] && save[i] != '\n')
		i++;
	i++;
	save_size = ft_strlen(save);
	rtn = (char *)malloc((save_size - i + 1) * sizeof(char));
	if (rtn == NULL)
		return (NULL);
	j = 0;
	while (i < save_size)
		rtn[j++] = save[i++];
	rtn[j] = '\0';
	return (rtn);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*save;

	save = ft_read(fd, save);
	if (save == NULL)
		return (NULL);
	line = ft_get_line(save);
	save = ft_save(save);
	return (line);
}
