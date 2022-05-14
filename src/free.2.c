/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 17:30:38 by brda-sil          #+#    #+#             */
/*   Updated: 2022/05/14 22:10:23 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_texture_walls(t_main *config)
{
	free_texture(config, config->textures->wall_0);
	free_texture(config, config->textures->wall_1_n);
	free_texture(config, config->textures->wall_1_s);
	free_texture(config, config->textures->wall_1_e);
	free_texture(config, config->textures->wall_1_w);
	free_texture(config, config->textures->wall_2_h);
	free_texture(config, config->textures->wall_2_v);
	free_texture(config, config->textures->wall_2_ur);
	free_texture(config, config->textures->wall_2_ul);
	free_texture(config, config->textures->wall_2_ll);
	free_texture(config, config->textures->wall_2_lr);
	free_texture(config, config->textures->wall_3_n);
	free_texture(config, config->textures->wall_3_s);
	free_texture(config, config->textures->wall_3_e);
	free_texture(config, config->textures->wall_3_w);
	free_texture(config, config->textures->wall_4);
}

void	free_texture_players(t_main *config)
{
	free_texture(config, config->textures->player_00);
	free_texture(config, config->textures->player_01);
	free_texture(config, config->textures->player_02);
	free_texture(config, config->textures->player_03);
	free_texture(config, config->textures->player_04);
	free_texture(config, config->textures->player_05);
	free_texture(config, config->textures->player_06);
	free_texture(config, config->textures->player_07);
	free_texture(config, config->textures->player_08);
	free_texture(config, config->textures->player_09);
	free_texture(config, config->textures->player_10);
}

void	free_texture_enemys(t_main *config)
{
	free_texture(config, config->textures->enemy_00);
	free_texture(config, config->textures->enemy_01);
	free_texture(config, config->textures->enemy_02);
	free_texture(config, config->textures->enemy_03);
	free_texture(config, config->textures->enemy_04);
	free_texture(config, config->textures->enemy_05);
	free_texture(config, config->textures->enemy_06);
	free_texture(config, config->textures->enemy_07);
	free_texture(config, config->textures->enemy_08);
	free_texture(config, config->textures->enemy_09);
	free_texture(config, config->textures->enemy_10);
}
