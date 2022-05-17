/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 17:30:38 by brda-sil          #+#    #+#             */
/*   Updated: 2022/05/17 08:50:08 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_texture(t_main *config, void *texture)
{
	if (config->texture_loaded > 0)
		mlx_destroy_image(config->mlx, texture);
	config->texture_loaded--;
}

void	free_map_new(t_main *config)
{
	int	i;

	i = 0;
	while (i < config->height + 2)
	{
		free(config->map_new[i]);
		config->map_new[i] = NULL;
		i++;
	}
	free(config->map_new);
	config->map_new = NULL;
	config->map_new_loaded = 0;
}

void	free_map(t_main *config)
{
	int	i;

	i = 0;
	while (i < config->height)
	{
		free(config->map[i]);
		config->map[i] = NULL;
		i++;
	}
	free(config->map);
	config->map = NULL;
	config->map_loaded = 0;
}

void	free_textures(t_main *config)
{
	free_texture_walls(config);
	free_texture_health(config);
	free_texture(config, config->textures->player);
	free_texture(config, config->textures->enemy);
	free_texture(config, config->textures->grave);
	free_texture(config, config->textures->player_on_grave);
	free_texture(config, config->textures->ground);
	free_texture(config, config->textures->door_close);
	free_texture(config, config->textures->door_between);
	free_texture(config, config->textures->door_open);
	free_texture(config, config->textures->key);
	config->texture_loaded = 0;
}

void	free_entry_point(t_main *config)
{
	if (config->map_loaded)
		free_map(config);
	if (config->map_new_loaded)
		free_map_new(config);
	if (config->enemy_loaded)
		free_enemy(config);
	if (config->texture_loaded)
		free_textures(config);
	free_log(config);
	mlx_destroy_window(config->mlx, config->win);
	mlx_destroy_display(config->mlx);
	free(config->mlx);
}
