/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarci2 <migarci2@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 14:34:08 by migarci2          #+#    #+#             */
/*   Updated: 2023/12/02 15:22:38 by migarci2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/map.h"

char	*ft_error_eof(int ret, char **str)
{
	if (ret < 0 || (ret == 0 && (!(*str) || !(*(*str)))))
	{
		free(*str);
		*str = NULL;
		return (NULL);
	}
	return (*str);
}

static char	*extract_line(char **str)
{
	size_t		i;
	char		*tmp;
	char		*line;

	i = 0;
	while ((*str)[i] && (*str)[i] != '\n')
		i++;
	if (!(*str)[i])
	{
		tmp = ft_strdup(*str);
		free(*str);
		*str = NULL;
		return (tmp);
	}
	line = ft_substr(*str, 0, i + 1);
	tmp = ft_strdup(&((*str)[i + 1]));
	free(*str);
	*str = tmp;
	return (line);
}

static char	*update_str(char *str, char *buffer)
{
	char	*tmp;

	tmp = ft_strjoin(str, buffer);
	if (tmp == NULL)
	{
		free(str);
		return (NULL);
	}
	free(str);
	return (tmp);
}

char	*get_next_line(int fd)
{
	static char	*str;
	char		buffer[BUFFER_SIZE + 1];
	int			ret;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!str)
		str = ft_strdup("");
	ret = read(fd, buffer, BUFFER_SIZE);
	while (ret > 0)
	{
		buffer[ret] = '\0';
		str = update_str(str, buffer);
		if (str == NULL)
			return (NULL);
		if (ft_strchr(str, '\n'))
			break ;
		ret = read(fd, buffer, BUFFER_SIZE);
	}
	if (ft_error_eof(ret, &str) == NULL)
		return (NULL);
	return (extract_line(&str));
}
