/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 17:27:47 by brda-sil          #+#    #+#             */
/*   Updated: 2022/05/12 21:46:08 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	*texture_load(t_main *config, char *path)
{
	void	*tmp;
	int		i;

	tmp = mlx_xpm_file_to_image(config->mlx, path, &i, &i);
	if (!tmp)
	{
		ft_printf("ERROR: %s not found\n", path);
		exit(-1);
	}
	return (tmp);
}

void	init_texture(t_main *config, t_textures *textures)
{
	textures->player = texture_load(config, "resources/img/player.xpm");
	textures->wall = texture_load(config, "resources/img/wall.xpm");
	textures->ground = texture_load(config, "resources/img/ground.xpm");
	textures->door_close = texture_load(config, "resources/img/door_close.xpm");
	textures->door_open = texture_load(config, "resources/img/door_open.xpm");
	textures->key = texture_load(config, "resources/img/key.xpm");
}

void	init_hook(t_main *config)
{
	mlx_hook(config->win, 33, 1L<<17, free_entry_point, config);
}

void	init_main(t_main *config, char *title)
{
	config->mlx = mlx_init();
	config->win = mlx_new_window(config->mlx, config->width * BLOCK_SIZE, \
											config->height * BLOCK_SIZE, title);
	init_hook(config);
	config->nb_player = 0;
	config->nb_door = 0;
	config->nb_key = 0;
}

void	init_entry_point(t_main *config, t_textures *textures)
{
	init_main(config, WIN_TITLE);
	init_texture(config, textures);
}
