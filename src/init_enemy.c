/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_enemy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/14 07:25:39 by brda-sil          #+#    #+#             */
/*   Updated: 2022/05/14 23:14:57 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_texture_players(t_main *config)
{
	config->textures->player_00 = texture_load(config, "res/img/player_00.xpm");
	config->textures->player_01 = texture_load(config, "res/img/player_01.xpm");
	config->textures->player_02 = texture_load(config, "res/img/player_02.xpm");
	config->textures->player_03 = texture_load(config, "res/img/player_03.xpm");
	config->textures->player_04 = texture_load(config, "res/img/player_04.xpm");
	config->textures->player_05 = texture_load(config, "res/img/player_05.xpm");
	config->textures->player_06 = texture_load(config, "res/img/player_06.xpm");
	config->textures->player_07 = texture_load(config, "res/img/player_07.xpm");
	config->textures->player_08 = texture_load(config, "res/img/player_08.xpm");
	config->textures->player_09 = texture_load(config, "res/img/player_09.xpm");
	config->textures->player_10 = texture_load(config, "res/img/player_10.xpm");
}

void	init_texture_enemys(t_main *config)
{
	config->textures->enemy_00 = texture_load(config, "res/img/enemy_00.xpm");
	config->textures->enemy_01 = texture_load(config, "res/img/enemy_01.xpm");
	config->textures->enemy_02 = texture_load(config, "res/img/enemy_02.xpm");
	config->textures->enemy_03 = texture_load(config, "res/img/enemy_03.xpm");
	config->textures->enemy_04 = texture_load(config, "res/img/enemy_04.xpm");
	config->textures->enemy_05 = texture_load(config, "res/img/enemy_05.xpm");
	config->textures->enemy_06 = texture_load(config, "res/img/enemy_06.xpm");
	config->textures->enemy_07 = texture_load(config, "res/img/enemy_07.xpm");
	config->textures->enemy_08 = texture_load(config, "res/img/enemy_08.xpm");
	config->textures->enemy_09 = texture_load(config, "res/img/enemy_09.xpm");
	config->textures->enemy_10 = texture_load(config, "res/img/enemy_10.xpm");
}

void	free_enemy(t_main *config)
{
	int	i;

	i = 0;
	while (i < config->nb_enemy)
		free(config->enemy[i++]);
	free(config->enemy);
}

t_enemy	*init_get_enemy(int i, int j)
{
	t_enemy	*tmp;

	tmp = malloc(sizeof(t_enemy));
	tmp->health = DEFAULT_ENEMY_HEALTH;
	tmp->pos_x = i;
	tmp->pos_y = j;
	return (tmp);
}

void	init_enemy(t_main *config)
{
	int	i;
	int	j;
	int	k;

	config->enemy = (t_enemy **)malloc(sizeof(t_enemy *) * \
														(config->nb_enemy));
	i = 0;
	j = 0;
	k = 0;
	while (i < config->height)
	{
		while (j < config->width)
		{
			if (config->map[i][j] == 'K')
				config->enemy[k++] = init_get_enemy(i + 1, j + 1);
			j++;
		}
		j = 0;
		i++;
	}
}
