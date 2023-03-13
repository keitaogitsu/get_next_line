/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kogitsu <kogitsu@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 16:23:09 by kogitsu           #+#    #+#             */
/*   Updated: 2023/03/13 19:58:33 by kogitsu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE  42
# endif

char	*get_next_line(int fd);
char	*ft_strchr(const char *s, int c);
size_t	ft_strlen(const char *s);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_read(int fd, char *save);
char	*ft_get_line(char *save);
char	*ft_save(char *save);
char	*ft_free(char *str);
void	ft_join_content(char *str, char *s1, char *s2);

#endif