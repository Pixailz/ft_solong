/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 18:35:50 by brda-sil          #+#    #+#             */
/*   Updated: 2022/05/17 01:00:49 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
				config->map_new[i][j] = 'e';
			j++;
		}
		j = 0;
		i++;
	}
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
	{
		if (keycode == KEY_ESC)
			print_close(config);
		if (keycode == KEY_R)
			print_retry(config);
	}
	else
	{
		if (keycode == KEY_ESC)
			end_hook(config);
		if (keycode == KEY_W || keycode == KEY_UP)
			move_player(config, -1, 0);
		if (keycode == KEY_A || keycode == KEY_LEFT)
			move_player(config, 0, -1);
		if (keycode == KEY_S || keycode == KEY_DOWN)
			move_player(config, 1, 0);
		if (keycode == KEY_D || keycode == KEY_RIGHT)
			move_player(config, 0, 1);
	}
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
