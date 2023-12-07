/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarci2 <migarci2@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 14:34:14 by migarci2          #+#    #+#             */
/*   Updated: 2023/12/07 12:52:35 by migarci2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/map.h"

static bool	ft_check_map_shape(t_map *map)
{
	int	i;

	if (!map || map->width == 0 || map->height == 0)
		return (false);
	i = 0;
	while (i < map->height)
	{
		if (((int) ft_strlen(map->map[i])) != map->width)
			return (false);
		i++;
	}
	return (true);
}

static bool	ft_check_map_walls(t_map *map)
{
	ssize_t	i;

	i = 0;
	while (i < map->width)
	{
		if (map->map[0][i] != '1' || map->map[map->height - 1][i] != '1')
			return (false);
		i++;
	}
	i = 0;
	while (i < map->height)
	{
		if (map->map[i][0] != '1' || map->map[i][map->width - 1] != '1')
			return (false);
		i++;
	}
	return (true);
}

bool	ft_validate_map(t_map *map)
{
	if (!ft_check_map_shape(map))
		return (false);
	if (!ft_check_map_walls(map))
		return (false);
	if (!(ft_count_char_in_map(map, 'P')
			== 1 && ft_count_char_in_map(map, 'E') == 1))
		return (false);
	if (!(map->max_collectives > 0))
		return (false);
	return (true);
}
