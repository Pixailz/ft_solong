/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 05:25:37 by brda-sil          #+#    #+#             */
/*   Updated: 2022/05/12 14:40:00 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	draw_block(t_textures *textures, t_main *config, int x, int y)
{
	if (config->map[x][y] == '1')
		mlx_put_image_to_window(config->mlx, config->win, textures->wall, \
								y * POINT_SIZE, x * POINT_SIZE);
	else if (config->map[x][y] == '0')
		mlx_put_image_to_window(config->mlx, config->win, textures->ground, \
								y * POINT_SIZE, x * POINT_SIZE);
	else if (config->map[x][y] == 'E')
		mlx_put_image_to_window(config->mlx, config->win, textures->door_close, \
								y * POINT_SIZE, x * POINT_SIZE);
	else if (config->map[x][y] == 'P')
		mlx_put_image_to_window(config->mlx, config->win, textures->player, \
								y * POINT_SIZE, x * POINT_SIZE);
	else if (config->map[x][y] == 'C')
		mlx_put_image_to_window(config->mlx, config->win, textures->key, \
								y * POINT_SIZE, x * POINT_SIZE);
}

void	draw_map(t_main *config, t_textures *textures)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < config->height)
	{
		while (j < config->width)
		{
			draw_block(textures, config, i, j);
			j++;
		}
		j = 0;
		i++;
	}
}
