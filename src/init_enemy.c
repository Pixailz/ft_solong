/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_enemy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/14 07:25:39 by brda-sil          #+#    #+#             */
/*   Updated: 2022/05/15 16:49:15 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_texture_health(t_main *config)
{
	config->textures->health_10 = texture_load(config, "res/img/health_10.xpm");
	config->textures->health_09 = texture_load(config, "res/img/health_09.xpm");
	config->textures->health_08 = texture_load(config, "res/img/health_08.xpm");
	config->textures->health_07 = texture_load(config, "res/img/health_07.xpm");
	config->textures->health_06 = texture_load(config, "res/img/health_06.xpm");
	config->textures->health_05 = texture_load(config, "res/img/health_05.xpm");
	config->textures->health_04 = texture_load(config, "res/img/health_04.xpm");
	config->textures->health_03 = texture_load(config, "res/img/health_03.xpm");
	config->textures->health_02 = texture_load(config, "res/img/health_02.xpm");
	config->textures->health_01 = texture_load(config, "res/img/health_01.xpm");
}

void	free_enemy(t_main *config)
{
	int	i;

	i = 0;
	if (config->enemy_loaded)
		while (i < config->nb_enemy)
			free(config->enemy[i++]);
	free(config->enemy);
	config->enemy = NULL;
}

static	t_enemy	*init_get_enemy(int i, int j)
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
	config->enemy_loaded = 1;
}
