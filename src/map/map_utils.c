/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarci2 <migarci2@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 14:34:41 by migarci2          #+#    #+#             */
/*   Updated: 2023/12/02 14:35:12 by migarci2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/map.h"

t_map	*ft_copy_map(t_map *map)
{
	t_map	*new_map;
	int		i;

	new_map = malloc(sizeof(t_map));
	if (!new_map)
		return (NULL);
	new_map->width = map->width;
	new_map->height = map->height;
	new_map->map = malloc(sizeof(char *) * (new_map->height + 1));
	if (!new_map->map)
		return (NULL);
	i = 0;
	while (i < new_map->height)
	{
		new_map->map[i] = ft_strdup(map->map[i]);
		if (!new_map->map[i])
			return (NULL);
		i++;
	}
	new_map->map[i] = NULL;
	return (new_map);
}

int	ft_count_char_in_map(t_map *map, char c)
{
	int	count;
	int	i;
	int	j;

	count = 0;
	i = 0;
	while (i < map->height)
	{
		j = 0;
		while (j < map->width)
		{
			if (map->map[i][j] == c)
				count++;
			j++;
		}
		i++;
	}
	return (count);
}

int	find_player(t_map *map, int player_cords[2])
{
	int	x;
	int	y;

	y = 0;
	while (y < map->height)
	{
		x = 0;
		while (x < map->width)
		{
			if (map->map[y][x] == 'P')
			{
				player_cords[0] = x;
				player_cords[1] = y;
				return (1);
			}
			x++;
		}
		y++;
	}
	return (0);
}

void	ft_print_map(t_map *map)
{
	int		i;
	int		j;
	char	*line;

	if (map == NULL)
		return ;
	ft_putstr_fd("Map Details:\n", STDOUT_FILENO);
	ft_putstr_fd("Width: ", STDOUT_FILENO);
	ft_putnbr_fd(map->width, STDOUT_FILENO);
	ft_putstr_fd(", Height: ", STDOUT_FILENO);
	ft_putnbr_fd(map->height, STDOUT_FILENO);
	ft_putstr_fd("\nMap Layout:\n", STDOUT_FILENO);
	i = 0;
	while (i < map->height)
	{
		line = map->map[i];
		j = 0;
		while (j < map->width)
		{
			write(STDOUT_FILENO, &line[j], 1);
			j++;
		}
		ft_putstr_fd("\n", STDOUT_FILENO);
		i++;
	}
}

bool	ft_check_file_extension(char *filename)
{
	size_t		len;
	size_t		ext_len;
	const char	*ext = ".ber";

	ext_len = 4;
	if (!filename)
		return (false);
	len = ft_strlen(filename);
	if (len < ext_len)
		return (false);
	return (ft_strncmp(filename + len - ext_len, ext, ext_len) == 0);
}
