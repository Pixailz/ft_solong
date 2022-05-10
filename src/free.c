/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 17:30:38 by brda-sil          #+#    #+#             */
/*   Updated: 2022/05/10 18:40:44 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_texture(t_main *config, t_img *texture)
{
	mlx_destroy_image(config->mlx, texture->img);
	free(texture);
}

void	free_entry_point(t_main *config, t_textures *textures)
{
	free_texture(config, textures->character);
	free_texture(config, textures->wall);
	mlx_destroy_window(config->mlx, config->win);
	mlx_destroy_display(config->mlx);
	free(config->mlx);
}
