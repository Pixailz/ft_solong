/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 05:25:37 by brda-sil          #+#    #+#             */
/*   Updated: 2022/05/14 05:36:14 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	put_image(t_main *config, void *img, int x, int y)
{
	mlx_put_image_to_window(config->mlx, config->win, img, \
							x * BLOCK_SIZE, (y * BLOCK_SIZE) + TITLE_PADDING);
}

void	draw_wall_block_oriented(t_main *config, int x, int y)
{
	if (config->map_new[x][y] == 'N')
		put_image(config, config->textures->wall_3_n, y - 1, x - 1);
	else if (config->map_new[x][y] == 'S')
		put_image(config, config->textures->wall_3_s, y - 1, x - 1);
	else if (config->map_new[x][y] == '2')
		put_image(config, config->textures->wall_3_e, y - 1, x - 1);
	else if (config->map_new[x][y] == 'W')
		put_image(config, config->textures->wall_3_w, y - 1, x - 1);
	else if (config->map_new[x][y] == 'n')
		put_image(config, config->textures->wall_1_n, y - 1, x - 1);
	else if (config->map_new[x][y] == 's')
		put_image(config, config->textures->wall_1_s, y - 1, x - 1);
	else if (config->map_new[x][y] == '3')
		put_image(config, config->textures->wall_1_e, y - 1, x - 1);
	else if (config->map_new[x][y] == 'w')
		put_image(config, config->textures->wall_1_w, y - 1, x - 1);
	else if (config->map_new[x][y] == '5')
		put_image(config, config->textures->wall_2_ur, y - 1, x - 1);
	else if (config->map_new[x][y] == '6')
		put_image(config, config->textures->wall_2_ul, y - 1, x - 1);
	else if (config->map_new[x][y] == '7')
		put_image(config, config->textures->wall_2_ll, y - 1, x - 1);
	else if (config->map_new[x][y] == '8')
		put_image(config, config->textures->wall_2_lr, y - 1, x - 1);
}

void	draw_block_wall(t_main *config, int x, int y)
{
	draw_wall_block_oriented(config, x, y);
	if (config->map_new[x][y] == '1')
		put_image(config, config->textures->wall_0, y - 1, x - 1);
	else if (config->map_new[x][y] == 'h')
		put_image(config, config->textures->wall_2_h, y - 1, x - 1);
	else if (config->map_new[x][y] == 'v')
		put_image(config, config->textures->wall_2_v, y - 1, x - 1);
	else if (config->map_new[x][y] == '4')
		put_image(config, config->textures->wall_4, y - 1, x - 1);
}

void	draw_block(t_main *config, int x, int y)
{
	if (config->map_new[x][y] == '0')
		put_image(config, config->textures->ground, y - 1, x - 1);
	else if (config->map_new[x][y] == 'E')
		put_image(config, config->textures->door_close, y - 1, x - 1);
	else if (config->map_new[x][y] == 'e')
		put_image(config, config->textures->door_open, y - 1, x - 1);
	else if (config->map_new[x][y] == 'P')
		put_image(config, config->textures->player, y - 1, x - 1);
	else if (config->map_new[x][y] == 'C')
		put_image(config, config->textures->key, y - 1, x - 1);
	else
		draw_block_wall(config, x, y);
}

int	draw_map(t_main *config)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < config->height)
	{
		while (j < config->width)
		{
			draw_block(config, i + 1, j + 1);
			j++;
		}
		j = 0;
		i++;
	}
	return (1);
}
