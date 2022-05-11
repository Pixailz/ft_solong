/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 19:00:32 by brda-sil          #+#    #+#             */
/*   Updated: 2022/05/11 22:53:02 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	t_main		config;
	t_textures	textures;
	(void)		argv;

	if (argc != 2)
		ft_error("Not enought args");
	//parse_map(config, argv[1]);
	init_entry_point(&config, &textures);
	mlx_put_image_to_window(config.mlx, config.win, textures.wall, \
							0, 0);
	usleep(2000000);
	free_entry_point(&config, &textures);
	return (0);
}
/*
	mlx_put_image_to_window(config.mlx, config.win, textures.wall->img, \
							0, 0);
	mlx_put_image_to_window(config.mlx, config.win, textures.wall->img, \
							32, 0);
	mlx_put_image_to_window(config.mlx, config.win, textures.wall->img, \
							64, 0);
	mlx_put_image_to_window(config.mlx, config.win, textures.wall->img, \
							64, 32);
	mlx_put_image_to_window(config.mlx, config.win, textures.wall->img, \
							64, 64);
	mlx_put_image_to_window(config.mlx, config.win, textures.wall->img, \
							32, 64);
	mlx_put_image_to_window(config.mlx, config.win, textures.wall->img, \
							0, 64);
	mlx_put_image_to_window(config.mlx, config.win, textures.wall->img, \
							0, 32);
	mlx_put_image_to_window(config.mlx, config.win, textures.wall->img, \
							32, 32);
	mlx_put_image_to_window(config.mlx, config.win, textures.character->img, \
							32, 32);
*/
