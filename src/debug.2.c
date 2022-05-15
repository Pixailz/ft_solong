/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/15 14:20:57 by brda-sil          #+#    #+#             */
/*   Updated: 2022/05/15 22:40:16 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	debug_print_keycode_release(int keycode)
{
	ft_printf("keyrelease\n");
	if (keycode == KEY_A)
		ft_printf("   known_name : KEY_A\n");
	if (keycode == KEY_W)
		ft_printf("   known_name : KEY_W\n");
	if (keycode == KEY_S)
		ft_printf("   known_name : KEY_S\n");
	if (keycode == KEY_D)
		ft_printf("   known_name : KEY_D\n");
	if (keycode == KEY_UP)
		ft_printf("   known_name : KEY_UP\n");
	if (keycode == KEY_RIGHT)
		ft_printf("   known_name : KEY_RIGHT\n");
	if (keycode == KEY_DOWN)
		ft_printf("   known_name : KEY_DOWN\n");
	if (keycode == KEY_LEFT)
		ft_printf("   known_name : KEY_LEFT\n");
	if (keycode == KEY_R)
		ft_printf("   known_name : KEY_R\n");
	if (keycode == KEY_ESC)
		ft_printf("   known_name : KEY_ESC\n");
	ft_printf("   keycode : %x\n", keycode);
}

void	debug_print_keycode_press(t_main *config, int keycode)
{
	if (DEBUG)
	{
		if (keycode == KEY_A || keycode == KEY_W || keycode == KEY_S || \
			keycode == KEY_D || keycode == KEY_UP || keycode == KEY_RIGHT || \
			keycode == KEY_DOWN || keycode == KEY_LEFT || keycode == KEY_R || \
			keycode == KEY_ESC)
		{
			ft_printf("player move\n");
			debug_print_map_without_9(config);
		}
	}
	ft_printf("keypress\n");
}

void	debug_print_map(t_main *config)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	ft_printf("checked_map :\n");
	while (i < config->height)
	{
		while (j < config->width)
		{
			if (j == 0)
				ft_printf("   %c", config->map[i][j]);
			else if (j != config->width - 1)
				ft_printf("%c", config->map[i][j]);
			else
				ft_printf("%c\n", config->map[i][j]);
			j++;
		}
		j = 0;
		i++;
	}
}

void	debug_print_inited(t_main *config)
{
	debug_print_map(config);
}
