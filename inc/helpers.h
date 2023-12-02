/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarci2 <migarci2@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 14:32:37 by migarci2          #+#    #+#             */
/*   Updated: 2023/12/02 14:32:38 by migarci2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HELPERS_H
# define HELPERS_H

# include "../libs/libft/libft.h"

typedef struct s_data	t_data;
typedef struct s_map	t_map;

void	*ft_error(char	*msg);

void	*ft_free_map(t_map *map);
void	*ft_free_data(t_data *data);
void	*ft_cleanup_sprites(t_data *data, int loaded);

int		ft_strlen_protected(char *str);

#endif
