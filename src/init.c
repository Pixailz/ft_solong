/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 17:27:47 by brda-sil          #+#    #+#             */
/*   Updated: 2022/05/10 18:50:47 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_img	*texture_load(t_main *config, char *path)
{
	t_img	*tmp;

	tmp = malloc(sizeof(t_img));
	tmp->img = mlx_xpm_file_to_image(config->mlx, path, \
									&tmp->width, &tmp->height);
	if (!tmp->img)
	{
		ft_printf("ERROR: %s not found\n", path);
		exit(-1);
	}
	return (tmp);
}

void	init_texture(t_main *config, t_textures *textures)
{
	textures->character = texture_load(config, "./imgs/character.xpm");
	textures->wall = texture_load(config, "./imgs/wall.xpm");
}

void	init_main(t_main *config, int height, int width, char *title)
{
	config->mlx = mlx_init();
	config->win = mlx_new_window(config->mlx, height, width, title);
}

void	init_entry_point(t_main *config, t_textures *textures)
{
	init_main(config, WIN_HEIGHT, WIN_WIDTH, WIN_TITLE);
	init_texture(config, textures);
}
