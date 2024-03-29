/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 19:00:32 by brda-sil          #+#    #+#             */
/*   Updated: 2022/05/22 12:58:03 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	move_win(t_main *config, int x, int y)
{
	config->p_win = 1;
	config->map_new[config->p_x + x][config->p_y + y] = 'e';
	if (config->map_new[config->p_x][config->p_y] == 'p')
		config->map_new[config->p_x][config->p_y] = 'k';
	else
		config->map_new[config->p_x][config->p_y] = '0';
	return (2);
}

void	post_game(t_main *config)
{
	if (config->p_win == 1)
		print_ascii_art_win(config);
	else if (config->p_win == -1)
		print_ascii_art_loose(config);
}

int	main(int argc, char **argv)
{
	t_main		config;
	t_textures	textures;
	t_log		log;

	if (argc < 2)
		ft_error("Not enought args");
	config.textures = &textures;
	config.log = &log;
	config.nb_map = argc - 1;
	init_multiple_map(&config, argv);
	pre_init(&config);
	while (config.retry)
	{
		ft_printf("Starting game\n");
		parse_map(&config);
		init_main(&config);
		if (config.nb_enemy > 0)
			init_enemy(&config);
		parse_wall(&config);
		mlx_loop(config.mlx);
		free_entry_point(&config);
	}
	return (0);
}
