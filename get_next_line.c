/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykot <ykot@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 22:14:57 by ykot              #+#    #+#             */
/*   Updated: 2021/12/01 00:25:55 by ykot             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"


static void	ft_realloc_buffer(char **buffer, size_t *buff_size)
{
	char		*new_buff;

	*buff_size *= 2;
	new_buff = ft_strnew(*buff_size);
	ft_strcpy(new_buff, *buffer);
	ft_strdel(&(*buffer));
	*buffer = new_buff;
}

static int ft_read_line (const int fd, char ***line)
{
	size_t		i;
	size_t		buff_size;
	int			ret;
	char		*buffer;
	char		buf;


	buff_size = BUFF_SIZE;
	buffer = ft_strnew(buff_size);
	i = 0;
	ret = read(fd, &buf, 1);
	while (ret && buf != '\n')
	{
		buffer[i] = buf;
		++i;
		if (i == buff_size)
			ft_realloc_buffer(&buffer, &buff_size);
		ret = read(fd, &buf, 1);
	}
	**line = buffer;
	if (!ret)
		return (0);
	else
		return (1);
}

int	get_next_line(const int fd, char **line)
{
	int	result;

	if (fd == -1 || fd == 1 || fd > 65535)
		return (-1);
	result = ft_read_line(fd, &line);
	if (result == 0)
		return (0);
	if (result == 1)
		return (1);
	return (-1);
}
