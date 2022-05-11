/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 17:27:47 by brda-sil          #+#    #+#             */
/*   Updated: 2022/05/11 22:50:43 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_img	*texture_load(t_main *config, char *path)
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
	textures->character = texture_load(config, "./img/character.xpm");
	textures->wall = texture_load(config, "./img/wall.xpm");
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
