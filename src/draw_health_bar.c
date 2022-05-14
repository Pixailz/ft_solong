/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_health_bar.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 05:25:37 by brda-sil          #+#    #+#             */
/*   Updated: 2022/05/15 00:08:04 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdio.h>

void	draw_player(t_main *config, int x, int y)
{
	double	current_percent;

	current_percent = (int)((config->p_health * 100) / DEFAULT_PLAYER_HEALTH);
	ft_printf("current_player_hp : %d\n", current_percent);
	if (current_percent > 95)
		put_image(config, config->textures->player_10, x, y);
	else if (current_percent > 85)
		put_image(config, config->textures->player_09, x, y);
	else if (current_percent > 75)
		put_image(config, config->textures->player_08, x, y);
	else if (current_percent > 65)
		put_image(config, config->textures->player_07, x, y);
	else if (current_percent > 55)
		put_image(config, config->textures->player_06, x, y);
	else if (current_percent > 45)
		put_image(config, config->textures->player_05, x, y);
	else if (current_percent > 35)
		put_image(config, config->textures->player_04, x, y);
	else if (current_percent > 25)
		put_image(config, config->textures->player_03, x, y);
	else if (current_percent > 15)
		put_image(config, config->textures->player_02, x, y);
	else if (current_percent > 5)
		put_image(config, config->textures->player_01, x, y);
	else
		put_image(config, config->textures->player_00, x, y);
}

double	draw_get_health_enemy(t_main *config, int x, int y)
{
	int	i;

	i = 0;
	while (i < config->nb_enemy)
	{
		if (config->enemy[i]->pos_x == x & config->enemy[i]->pos_y == y)
			return (config->enemy[i]->health);
		i++;
	}
	return (0);
}

void	draw_enemy(t_main *config, int y, int x)
{
	double	current_percent;

	current_percent = ((draw_get_health_enemy(config, y, x) * 100) \
										/ DEFAULT_ENEMY_HEALTH);
	printf("enemy hp: %f\n", current_percent);
	if (current_percent > 95)
		put_image(config, config->textures->enemy_10, x, y);
	else if (current_percent > 85)
		put_image(config, config->textures->enemy_09, x, y);
	else if (current_percent > 75)
		put_image(config, config->textures->enemy_08, x, y);
	else if (current_percent > 65)
		put_image(config, config->textures->enemy_07, x, y);
	else if (current_percent > 55)
		put_image(config, config->textures->enemy_06, x, y);
	else if (current_percent > 45)
		put_image(config, config->textures->enemy_05, x, y);
	else if (current_percent > 35)
		put_image(config, config->textures->enemy_04, x, y);
	else if (current_percent > 25)
		put_image(config, config->textures->enemy_03, x, y);
	else if (current_percent > 15)
		put_image(config, config->textures->enemy_02, x, y);
	else if (current_percent > 5)
		put_image(config, config->textures->enemy_01, x, y);
	else
		put_image(config, config->textures->enemy_00, x, y);
}

/*
void	duel_check_direction(t_main *config, int i, int j)
{
	if (config->enemy[i]->pos_x == config->p_x + j && \
		config->enemy[i]->pos_y == config->p_y)
	{
		duel_deal_damage(config, config->enemy[i]);
		config->p_step++;
	}
	if (config->enemy[i]->pos_x == config->p_x && \
		config->enemy[i]->pos_y == config->p_y + j)
	{
		duel_deal_damage(config, config->enemy[i]);
		config->p_step++;
	}
}

void	get_nearby_enemy(t_main *config)
{
* 1 00) \
										/ DEFAULT_PLAYER_HEALTHi;
	int	j;

config, co nfig->textures->enemy_10,0;
	j = -1;
	while (i < config->nb_enemy)
	{
		while (j <= 1)
		{
			duel_check_direction(config, i, j);
			j += 2;
		}
		j = -1;
		i++;
	}
}
*/
