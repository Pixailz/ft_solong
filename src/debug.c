/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/15 14:20:57 by brda-sil          #+#    #+#             */
/*   Updated: 2022/05/15 22:37:51 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	debug_print_map_without_9(t_main *config)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i <= config->height - 1)
	{
		while (j <= config->width - 1)
		{
			if (j == 0)
				ft_printf("   %c", config->map_new[i + 1][j + 1]);
			else if (j != config->width - 1)
				ft_printf("%c", config->map_new[i + 1][j + 1]);
			else
				ft_printf("%c\n", config->map_new[i + 1][j + 1]);
			j++;
		}
		j = 0;
		i++;
	}
}

void	debug_print_map_with_9(t_main *config)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i <= config->height + 1)
	{
		while (j <= config->width + 1)
		{
			if (j != config->width + 1)
				ft_printf("%c", config->map_new[i][j]);
			else
				ft_printf("%c\n", config->map_new[i][j]);
			j++;
		}
		j = 0;
		i++;
	}
}

void	debug_print_current_block(t_main *config, int x, int y)
{
	ft_printf("current block (%d,%d) = [%c]\n", x + 1, y + 1, \
												config->map_new[y + 1][x + 1]);
}

void	debug_print_enemy_info(t_main *config, int x, int y)
{
	int	id_enemy;

	id_enemy = get_enemy_id(config, x, y);
	ft_printf("id_enemy = %d\n", id_enemy);
	if (id_enemy < 0)
	{
		ft_printf("Error: enemy not found\n");
		return ;
	}
	ft_printf("Enemy [%d]: hp [%d], pos [%d,%d]\n", id_enemy, \
											config->enemy[id_enemy]->health, \
											config->enemy[id_enemy]->pos_x, \
											config->enemy[id_enemy]->pos_y);
}
