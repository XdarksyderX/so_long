/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarci2 <migarci2@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 14:34:08 by migarci2          #+#    #+#             */
/*   Updated: 2023/12/02 14:37:53 by migarci2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/map.h"

static int	read_char(int fd, char *buffer, int *i)
{
	ssize_t	bytes_read;

	bytes_read = read(fd, &buffer[*i], 1);
	if (bytes_read <= 0)
		return (bytes_read);
	if (buffer[*i] == '\n' || *i == BUFFER_SIZE)
	{
		buffer[*i] = '\0';
		return (1);
	}
	(*i)++;
	return (2);
}

char	*get_next_line(int fd)
{
	char	buffer[BUFFER_SIZE + 1];
	int		i;
	int		result;

	i = 0;
	result = 2;
	while (result == 2)
		result = read_char(fd, buffer, &i);
	if (result <= 0 && i == 0)
		return (NULL);
	return (ft_strdup(buffer));
}
