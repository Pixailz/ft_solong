/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 19:00:32 by brda-sil          #+#    #+#             */
/*   Updated: 2022/05/10 18:54:59 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(void)
{
	t_main		config;
	t_textures	textures;

	init_entry_point(&config, &textures);
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
	usleep(2000000);
	free_entry_point(&config, &textures);
	return (0);
}
