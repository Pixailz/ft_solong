/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_move.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 18:35:50 by brda-sil          #+#    #+#             */
/*   Updated: 2022/05/16 01:57:37 by brda-sil         ###   ########.fr       */
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
