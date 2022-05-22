/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_health_bar.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 05:25:37 by brda-sil          #+#    #+#             */
/*   Updated: 2022/05/17 10:12:07 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdio.h>

static	void	put_health_bar(t_main *config, void *img, int x, int y)
{
	mlx_put_image_to_window(config->mlx, config->win, img, (x * BLOCK_SIZE) \
				+ 1, ((y * BLOCK_SIZE) + (LOG_LENGTH * LOG_FONT_HEIGTH)) + 1);
}

static	void	draw_health_bar(t_main *config, int x, int y, int
current_percent)
{
	if (current_percent > 95)
		put_health_bar(config, config->textures->health_10, x, y);
	else if (current_percent > 85)
		put_health_bar(config, config->textures->health_09, x, y);
	else if (current_percent > 75)
		put_health_bar(config, config->textures->health_08, x, y);
	else if (current_percent > 65)
		put_health_bar(config, config->textures->health_07, x, y);
	else if (current_percent > 55)
		put_health_bar(config, config->textures->health_06, x, y);
	else if (current_percent > 45)
		put_health_bar(config, config->textures->health_05, x, y);
	else if (current_percent > 35)
		put_health_bar(config, config->textures->health_04, x, y);
	else if (current_percent > 25)
		put_health_bar(config, config->textures->health_03, x, y);
	else if (current_percent > 15)
		put_health_bar(config, config->textures->health_02, x, y);
	else
		put_health_bar(config, config->textures->health_01, x, y);
}

void	draw_player(t_main *config, int x, int y)
{
	if (config->map_new[y + 1][x + 1] == 'p')
		put_image(config, config->textures->player_on_grave, x, y);
	else if (config->map_new[y + 1][x + 1] != 'e')
		put_image(config, config->textures->player, x, y);
	draw_health_bar(config, x, y, (int)(config->p_health * 100) / \
									DEFAULT_PLAYER_HEALTH);
}

static	int	get_enemy_id(t_main *config, int y, int x)
{
	int	i;

	i = 0;
	while (i < config->nb_enemy)
	{
		if (config->enemy[i]->pos_x == x + 1 && \
			config->enemy[i]->pos_y == y + 1)
			return (i);
		i++;
	}
	return (-1);
}

void	draw_enemy(t_main *config, int x, int y)
{
	int	id_enemy;

	id_enemy = get_enemy_id(config, x, y);
	put_image(config, config->textures->enemy, x, y);
	draw_health_bar(config, x, y, (int)(config->enemy[id_enemy]->health * 100) \
												/ DEFAULT_ENEMY_HEALTH);
}
