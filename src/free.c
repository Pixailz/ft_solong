/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 17:30:38 by brda-sil          #+#    #+#             */
/*   Updated: 2022/05/14 22:05:36 by brda-sil         ###   ########.fr       */
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
}

void	free_textures(t_main *config)
{
	free_texture_walls(config);
	free_texture_players(config);
	free_texture_enemys(config);
	free_texture(config, config->textures->ground);
	free_texture(config, config->textures->door_close);
	free_texture(config, config->textures->door_open);
	free_texture(config, config->textures->key);
}

void	free_entry_point(t_main *config)
{
	int	i;

	i = 0;
	free_textures(config);
	if (config->is_map_new)
		free_map_new(config);
	if (config->nb_enemy)
	{
		while (i < config->nb_enemy)
			free(config->enemy[i++]);
		free(config->enemy);
	}
	mlx_destroy_window(config->mlx, config->win);
	mlx_destroy_display(config->mlx);
	free(config->mlx);
}
