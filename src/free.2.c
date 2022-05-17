/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 17:30:38 by brda-sil          #+#    #+#             */
/*   Updated: 2022/05/18 01:13:17 by brda-sil         ###   ########.fr       */
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

void	free_texture_health(t_main *config)
{
	free_texture(config, config->textures->health_10);
	free_texture(config, config->textures->health_09);
	free_texture(config, config->textures->health_08);
	free_texture(config, config->textures->health_07);
	free_texture(config, config->textures->health_06);
	free_texture(config, config->textures->health_05);
	free_texture(config, config->textures->health_04);
	free_texture(config, config->textures->health_03);
	free_texture(config, config->textures->health_02);
	free_texture(config, config->textures->health_01);
}

void	free_log(t_main *config)
{
	int	i;

	i = 0;
	while (i < LOG_LENGTH)
	{
		free(config->log->line[i]->str);
		config->log->line[i]->str = NULL;
		free(config->log->line[i]);
		config->log->line[i] = NULL;
		i++;
	}
	free(config->log->line);
}

void	free_multiple_map(t_main *config)
{
	int	i;

	i = 0;
	while (i < config->nb_map)
	{
		free(config->map_str[i]);
		config->map_str[i++] = NULL;
	}
	free(config->map_str);
	config->map_str = NULL;
}

void	free_empty_file(t_main *config)
{
	free_multiple_map(config);
	ft_error("Map file is empty");
}
