/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kogitsu <kogitsu@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 19:59:48 by kogitsu           #+#    #+#             */
/*   Updated: 2023/02/27 16:16:41 by kogitsu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char		*line;
	char		buf[BUFFER_SIZE];
	static char	*save;

	while (read(fd, buf, BUFFER_SIZE) > 0)
	{
		if (ft_strchr(buf, '\n'))
		{
			save = 
		}
		else
		{
			save = ft_strjoin(save, buf);
		}
	}
	return (line);
}
