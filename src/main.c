/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarci2 <migarci2@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 14:38:52 by migarci2          #+#    #+#             */
/*   Updated: 2023/12/02 14:38:54 by migarci2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/map.h"
#include "../inc/rendering.h"

int	main(int argc, char **argv)
{
	t_data	*data;

	if (argc != 2)
		ft_error("Invalid number of arguments");
	if (!ft_check_file_extension(argv[1]))
		ft_error("Invalid map file");
	data = ft_init_data(argv[1]);
	if (!data)
		ft_error("Data initialization failed");
	ft_render_map(data, NULL);
	mlx_loop(data->mlx_ptr);
	return (0);
}
