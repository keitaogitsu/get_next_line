/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kogitsu <kogitsu@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 20:00:49 by kogitsu           #+#    #+#             */
/*   Updated: 2023/02/27 16:16:45 by kogitsu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <unistd.h>
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE = 4
# endif

char	*get_next_line(int fd);
char	*ft_strchr(const char *s, int c);

#endif