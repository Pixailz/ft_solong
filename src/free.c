/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 17:30:38 by brda-sil          #+#    #+#             */
/*   Updated: 2022/05/14 04:27:15 by brda-sil         ###   ########.fr       */
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

void	free_entry_point(t_main *config)
{
	free_texture(config, config->textures->player);
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
	free_texture(config, config->textures->ground);
	free_texture(config, config->textures->door_close);
	free_texture(config, config->textures->door_open);
	free_texture(config, config->textures->key);
	free_map_new(config);
	mlx_destroy_window(config->mlx, config->win);
	mlx_destroy_display(config->mlx);
	free(config->mlx);
}

int	free_hook(t_main *config)
{
	mlx_loop_end(config->mlx);
	return (1);
}
