/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kogitsu <kogitsu@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 16:21:54 by kogitsu           #+#    #+#             */
/*   Updated: 2023/03/13 18:00:36 by kogitsu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_read(int fd, char *save)
{
	char		*tmp[OPEN_MAX + 1];
	ssize_t		read_size;
	char		*save_free;

	tmp[fd] = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (tmp[fd] == NULL)
		return (NULL);
	while (ft_strchr(save, '\n') == NULL)
	{
		read_size = read(fd, tmp[fd], BUFFER_SIZE);
		if (read_size == -1)
			return (ft_free(tmp[fd]));
		else if (read_size == 0)
			break ;
		tmp[fd][read_size] = '\0';
		save_free = save;
		save = ft_strjoin(save, tmp[fd]);
		if (save == NULL)
			return (ft_free(tmp[fd]));
		free(save_free);
	}
	free(tmp[fd]);
	return (save);
}

char	*ft_get_line(char *save)
{
	size_t	i;
	size_t	count;
	char	*rtn_line;

	if (*save == '\0')
		return (NULL);
	count = 0;
	while (save[count] && save[count] != '\n')
		count++;
	rtn_line = (char *)malloc((count + 2) + sizeof(char));
	if (rtn_line == NULL)
		return (NULL);
	i = 0;
	while (save[i] && save[i] != '\n')
	{
		rtn_line[i] = save[i];
		i++;
	}
	if (save[i] == '\n')
	{
		rtn_line[i] = save[i];
		i++;
	}
	rtn_line[i] = '\0';
	return (rtn_line);
}

char	*ft_save(char *save)
{
	size_t	i;
	size_t	j;
	char	*rtn;

	i = 0;
	while (save[i] && save[i] != '\n')
		i++;
	if (!save[i])
	{
		free(save);
		return (NULL);
	}
	rtn = (char *)malloc((ft_strlen(save) - i + 1) * sizeof(char));
	if (rtn == NULL)
	{
		free(save);
		return (NULL);
	}
	j = 0;
	i++;
	while (i < ft_strlen(save))
		rtn[j++] = save[i++];
	rtn[j] = '\0';
	free(save);
	return (rtn);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*save;

	if (fd < 0 || BUFFER_SIZE < 0 \
		|| BUFFER_SIZE > SIZE_MAX || fd > OPEN_MAX)
		return (NULL);
	save = ft_read(fd, save);
	if (save == NULL)
		return (NULL);
	line = ft_get_line(save);
	save = ft_save(save);
	return (line);
}

// #include <stdio.h>
// #include <fcntl.h>

// int main(void)
// {
// 	int		fd;
// 	int		fd2;
// 	char	*line;
// 	char	*line2;

// 	line = "";
// 	fd = open("./test.txt", O_RDONLY);
// 	line = get_next_line(fd);
// 	printf("fd> %s", line);
// 	free(line);
// 	system("leaks -q a.out");

	// while (line || line2)
	// {
	// 	line = get_next_line(fd);
	// 	printf("fd> %s", line);
	// 	line2 = get_next_line(fd2);
	// 	printf("fd2> %s", line2);
	// 	free(line);
	// 	free(line2);
	// }
	// system("leaks -q a.out");

	// printf("\n\n>>>>>>>>>>>>>>>>>>>>>>>>>>\n\n");
	// fd = open("./test.txt", O_RDONLY);
	// line = "";
	// while (line)
	// {
	// 	line = get_next_line(fd);
	// 	printf("> %s", line);
	// 	free(line);
	// }
	// system("leaks -q a.out");
// 	return (0);
// }