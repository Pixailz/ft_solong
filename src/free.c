/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 17:30:38 by brda-sil          #+#    #+#             */
/*   Updated: 2022/05/12 15:15:27 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_texture(t_main *config, void *texture)
{
	mlx_destroy_image(config->mlx, texture);
}

void	free_map(char **map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		free(map[i]);
		map[i] = NULL;
		i++;
	}
	free(map);
	map = NULL;
}

void	free_entry_point(t_main *config, t_textures *textures)
{
	free_texture(config, textures->player);
	free_texture(config, textures->wall);
	free_texture(config, textures->ground);
	free_texture(config, textures->door_close);
	free_texture(config, textures->door_open);
	free_texture(config, textures->key);
	free_map(config->map);
	mlx_destroy_window(config->mlx, config->win);
	mlx_destroy_display(config->mlx);
	free(config->mlx);
}
