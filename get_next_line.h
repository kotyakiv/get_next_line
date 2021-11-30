/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykot <ykot@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 22:14:55 by ykot              #+#    #+#             */
/*   Updated: 2021/12/01 00:29:06 by ykot             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <unistd.h> 
# include <stdlib.h>
# include <fcntl.h>
# define BUFF_SIZE 10000000

int		get_next_line(const int fd, char **line);
char	*ft_strnew(size_t size);
void	ft_strdel(char **as);
char	*ft_strcpy(char *dst, const char *src);

#endif
