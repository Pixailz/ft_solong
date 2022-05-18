/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_pixel_art.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 01:54:29 by brda-sil          #+#    #+#             */
/*   Updated: 2022/05/18 02:47:05 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	print_ascii_art_pixel(t_main *config, int x, int y)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < BLOCK_SIZE / 8)
	{
		while (j < BLOCK_SIZE / 8)
		{
			mlx_pixel_put(config->mlx, config->win, \
				(x * BLOCK_SIZE / 8) + j, \
				(y * BLOCK_SIZE / 8) + i + \
				(LOG_LENGTH * LOG_FONT_HEIGTH), WHITE);
			j++;
		}
		j = 0;
		i++;
	}
	usleep(1000000 * TIME_BETWEEN_PIXEL);
}

void	print_ascii_l(t_main *config)
{
	int	i;

	i = 0;
	while (i < 10)
		print_ascii_art_pixel(config, 1, i++);
}

void	print_ascii_art(t_main *config)
{
	print_ascii_art_pixel(config, 0, 1);
	print_ascii_art_pixel(config, 0, 2);
	print_ascii_art_pixel(config, 0, 3);
	print_ascii_art_pixel(config, 0, 0);
	print_ascii_art_pixel(config, 1, 0);
	print_ascii_art_pixel(config, 2, 0);
	print_ascii_art_pixel(config, 3, 0);
}
