/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_move.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 18:35:50 by brda-sil          #+#    #+#             */
/*   Updated: 2022/05/17 09:47:10 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_player_increment(t_main *config, int x, int y)
{
	config->p_x += x;
	config->p_y += y;
	config->p_step++;
	put_steps(config);
	if (config->p_win)
		print_before_win_loose(config);
}

void	move_player(t_main *config, int x, int y)
{
	int			return_code;

	return_code = check_move(config, x, y, \
							config->map_new[config->p_x + x][config->p_y + y]);
	if (!return_code)
		return ;
	else if (return_code == -1)
	{
		config->map_new[config->p_x][config->p_y] = config->saved_block;
		config->saved_block = config->map_new[config->p_x + x][config->p_y + y];
		config->map_new[config->p_x + x][config->p_y + y] = 'p';
	}
	else if (return_code == -2)
	{
		config->map_new[config->p_x + x][config->p_y + y] = 'P';
		config->map_new[config->p_x][config->p_y] = config->saved_block;
		config->saved_block = '0';
	}
	else if (return_code == 1)
	{
		config->map_new[config->p_x][config->p_y] = config->saved_block;
		config->saved_block = config->map_new[config->p_x + x][config->p_y + y];
		config->map_new[config->p_x + x][config->p_y + y] = 'P';
	}
	move_player_increment(config, x, y);
}

void	keypress_inmenu(t_main *config, int keycode)
{
	if (keycode == KEY_ESC)
		print_close(config);
	if (keycode == KEY_R)
		print_retry(config);
	if (keycode == KEY_SPACE && config->p_current_map + 1 < config->nb_map)
		print_continue(config);
}

void	keypress_ingame(t_main *config, int keycode)
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
