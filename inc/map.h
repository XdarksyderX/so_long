/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarci2 <migarci2@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 14:32:07 by migarci2          #+#    #+#             */
/*   Updated: 2023/12/02 14:32:09 by migarci2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_H
# define MAP_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 32
# endif

# include <fcntl.h>
# include <stdbool.h>

# include "../libs/libft/libft.h"

typedef struct s_map
{
	char	**map;
	int		width;
	int		height;
	int		max_collectives;
	int		collected;
	int		exit_cords[2];
}	t_map;

char	*get_next_line(int fd);
bool	ft_validate_map(t_map *map);
t_map	*ft_get_map(char *path);

t_map	*ft_copy_map(t_map *map);
void	ft_print_map(t_map *map);
int		ft_count_char_in_map(t_map *map, char c);
bool	ft_check_file_extension(char *filename);
int		find_player(t_map *map, int player_cords[2]);

#endif
