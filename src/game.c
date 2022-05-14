/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 18:35:50 by brda-sil          #+#    #+#             */
/*   Updated: 2022/05/14 23:49:05 by brda-sil         ###   ########.fr       */
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
	char		*tmp;
	char		*tmp_nbr;

	if (config->p_step)
	{
		tmp_nbr = ft_itoa(config->p_step - \
							(config->p_step - config->p_last_step));
		tmp = ft_strjoin("player step : ", tmp_nbr);
		mlx_string_put(config->mlx, config->win, \
					0, 14, 0x000000, tmp);
		free(tmp_nbr);
		free(tmp);
	}
	tmp_nbr = ft_itoa(config->p_step);
	tmp = ft_strjoin("player step : ", tmp_nbr);
	mlx_string_put(config->mlx, config->win, \
					0, 14, 0xffffff, tmp);
	free(tmp_nbr);
	free(tmp);
}

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

	return_code = check_move(config, \
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
	return (1);
}
