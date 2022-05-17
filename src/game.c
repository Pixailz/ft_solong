/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 18:35:50 by brda-sil          #+#    #+#             */
/*   Updated: 2022/05/17 10:08:13 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	open_door_2(t_main *config)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < config->height)
	{
		while (j < config->width)
		{
			if (config->map_new[i][j] == 'i')
			{
				config->map_new[i][j] = 'e';
			}
			j++;
		}
		j = 0;
		i++;
	}
	draw_map(config);
}

void	open_door(t_main *config)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < config->height)
	{
		while (j < config->width)
		{
			if (config->map_new[i][j] == 'E')
			{
				config->map_new[i][j] = 'i';
			}
			j++;
		}
		j = 0;
		i++;
	}
	draw_map(config);
	open_door_2(config);
}

void	put_steps(t_main *config)
{
	char	*tmp;
	char	*step;

	step = ft_itoa(config->p_step);
	tmp = ft_strjoin("player steps: ", step);
	free(step);
	put_str_log(config, tmp, WHITE);
	free(tmp);
}

int	keypress(int keycode, t_main *config)
{
	config->p_last_step = config->p_step;
	if (config->p_win)
		keypress_inmenu(config, keycode);
	else
		keypress_ingame(config, keycode);
	if (DEBUG)
		debug_print_keycode_press(config, keycode);
	return (1);
}

int	keyrelease(int keycode, t_main *config)
{
	(void) config;
	if (DEBUG)
		debug_print_keycode_release(keycode);
	return (1);
}
