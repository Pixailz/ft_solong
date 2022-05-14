/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 18:35:50 by brda-sil          #+#    #+#             */
/*   Updated: 2022/05/14 05:55:35 by brda-sil         ###   ########.fr       */
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

int	check_move(t_main *config, char next_move)
{
	if (check_is_wall(next_move) || next_move == 'E')
		return (0);
	if (next_move == 'C')
	{
		config->p_key++;
		if (config->p_key == config->nb_key)
			open_door(config);
	}
	if (next_move == 'e')
		config->p_win = 1;
	return (1);
}

void	put_steps(t_main *config)
{
	char	*tmp;
	char	*tmp_nbr;

	ft_printf("player step: [%d]\n", config->p_step);
	if (config->p_step)
	{
		tmp_nbr = ft_itoa(config->p_step - 1);
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

void	move_player(t_main *config, int x, int y)
{
	if (!check_move(config, config->map_new[config->p_x + x][config->p_y + y]))
		return ;
	config->map_new[config->p_x + x][config->p_y + y] = 'P';
	config->map_new[config->p_x][config->p_y] = '0';
	config->p_x += x;
	config->p_y += y;
	config->p_step++;
	put_steps(config);
	if (config->p_win)
		mlx_loop_end(config->mlx);
}

int	keypress(int keycode, t_main *config)
{
	if (keycode == KEY_ESC)
		free_hook(config);
	if (keycode == KEY_W || keycode == KEY_UP)
		move_player(config, -1, 0);
	if (keycode == KEY_A || keycode == KEY_LEFT)
		move_player(config, 0, -1);
	if (keycode == KEY_S || keycode == KEY_DOWN)
		move_player(config, 1, 0);
	if (keycode == KEY_D || keycode == KEY_RIGHT)
		move_player(config, 0, 1);
	return (1);
}
