/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_pixel_art.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 01:54:29 by brda-sil          #+#    #+#             */
/*   Updated: 2022/05/21 21:41:33 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	print_ascii_art_pixel(t_main *config, int x, int y, int color)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < BLOCK_SIZE / 4)
	{
		while (j < BLOCK_SIZE / 4)
		{
			mlx_pixel_put(config->mlx, config->win, \
				(x * BLOCK_SIZE / 4) + j, \
				(y * BLOCK_SIZE / 4) + i + \
				(LOG_LENGTH * LOG_FONT_HEIGTH), color);
			j++;
		}
		j = 0;
		i++;
	}
	usleep(1000000 * TIME_BETWEEN_PIXEL);
}

void	print_limits_pixel_art(t_main *config)
{
	int	i;

	i = 0;
	while (i < (config->width * BLOCK_SIZE))
		mlx_pixel_put(config->mlx, config->win, i++, \
						LOG_LENGTH * LOG_FONT_HEIGTH, WHITE);
}

void	print_ascii_art_loose(t_main *config)
{
	int	global_offset;

	global_offset = 5;
	print_limits_pixel_art(config);
	print_ascii_l(global_offset, config);
	print_ascii_l_shadow(global_offset, config);
	print_ascii_o(global_offset, config, 0);
	print_ascii_o_shadow(global_offset, config, 0);
	print_ascii_o(global_offset, config, 8);
	print_ascii_o_shadow(global_offset, config, 8);
	print_ascii_s(global_offset, config);
	print_ascii_s_shadow(global_offset, config);
	print_ascii_e(global_offset, config);
	print_ascii_e_shadow(global_offset, config);
}
